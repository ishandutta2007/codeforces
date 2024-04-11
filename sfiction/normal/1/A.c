/*
ID: Sfiction
OJ: CF
PROB: 1A
*/
#include <stdio.h>
int main()
{
    long long n,m,a,S;
    scanf("%I64d%I64d%I64d",&n,&m,&a);
    S=((n-1)/a+1)*((m-1)/a+1);
    printf("%I64d\n",S);
    return 0;
}