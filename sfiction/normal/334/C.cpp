/*
ID: Sfiction
OJ: CF
PROB: 334C
*/
#include <cstdio>
int main()
{
    long long n;
    scanf("%I64d",&n);
    while (n%3==0) n/=3;
    printf("%I64d",(n+2)/3);
    return 0;
}