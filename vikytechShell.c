#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>

void quit() {
    printf("\n");
}

int main(int argc, char const *argv[])
{
    while(1) {
        char command[1000];
        printf("˚__˚ § ");
        gets(command);
        int pid = fork();
        if (pid == 0) {
            execlp(command, command, NULL);
            exit(0);
        } 
        else{
            signal(SIGINT, quit);
            wait(&pid);
        }   
    }    
}