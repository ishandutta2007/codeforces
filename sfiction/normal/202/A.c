/*
ID: Sfiction
OJ: CF129DIV2
PROB: A
*/
#include <stdio.h>
int main()
{
    int i;
    char max,s[20];
    scanf("%s",s);
    max=s[0];
    for (i=1;s[i]>0;i++)
        if (s[i]>max) max=s[i];
    for (i=0;s[i]>0;i++)
        if (s[i]==max) printf("%c",s[i]);
    return 0;
}