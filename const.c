#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

ssize_t readln(int fildes, void* buf, size_t nbytes) {
    int i = 0, endLine = 0;
    char a;

    while(i < nbytes && !endLine && read(fildes, &a, 1) > 0) {
        if(a != '\n') {
        	memcpy(buf, &a, 1);
			buf++;
			i++;
        }
        else endLine = 1;
	}
    return (endLine || i > 0)? i : -1;
}

int main(int argc, char ** argv) {
	char buffer[10];
	ssize_t len;

	while((len = readln(0, buffer, 10)) != -1) {
		write(1, buffer, len);
		if(len != 10) {
			write(1, ":", 1);
			write(1, argv[1], strlen(argv[1]));
			write(1, "\n", 1);
		}
	}
}
