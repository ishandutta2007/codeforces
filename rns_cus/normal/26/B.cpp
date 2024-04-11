///b
#include<stdio.h>
#include<string.h>

#define N 1001000

char s[N];
int maxlen,optot;

int main()
{
    gets(s);
    int len=strlen(s);
    optot=0;
    maxlen=0;
    for(int i=0;i<len;i++){
        if(s[i]=='('){optot++;continue;}
        if(s[i]==')'){
            if(optot==0)continue;
            maxlen++;
            optot--;
        }
    }
    printf("%d\n",maxlen*2);
    return 0;
}