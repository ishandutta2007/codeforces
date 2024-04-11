/*
ID: Sfiction
OJ: CF130 Div2
PROB: A
*/
#include <stdio.h>
#include <string.h>
int main()
{
    int len,t,i,p;
    char s[300],out[200];
    scanf("%s",s);
    len=strlen(s);
    p=t=i=0;
    while (i<len)
        if (s[i]=='W'&&s[i+1]=='U'&&s[i+2]=='B')
        {
            out[t]=0;
            if (t)
            {
                if (p) printf(" ");
                else p=1;
                printf("%s",out);
            }
            t=0;
            i+=3;
        }
        else out[t++]=s[i++];
    out[t]=0;
    if (t)
    {
        if (p) printf(" ");
        else p=1;
        printf("%s",out);
    }
    return 0;
}