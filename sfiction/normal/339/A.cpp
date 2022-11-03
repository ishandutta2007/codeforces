/*
ID: Sfiction
OJ: CF
PROB: 339A
*/
#include <cstdio>
char s[102];
int a[4];
int main()
{
    int p=0,i;
    scanf("%s",s);
    for (i=0;s[i];i+=2) ++a[s[i]-48];
    for (i=1;i<4;++i)
        for (;a[i];--a[i])
        {
            if (p) printf("+");
            else p=1;
            printf("%d",i);
        }
    return 0;
}