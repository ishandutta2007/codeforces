/*
ID: Sfiction
OJ: CF
PROB: 476C
*/
/*

c=x mod bx=cbk+c=c(bk+1)
ksum(k)=(bk+1)*b*(b-1)/2
sum=((a+1)/2*b+1)*a*b*(b-1)/2
*/
#include <cstdio>

const long long MOD=1000000007;

int main(){
    long long a,b;
    scanf("%I64d%I64d",&a,&b);
    printf("%I64d",((a+1)*a/2%MOD*b+a)%MOD*(b*(b-1)/2%MOD)%MOD);
    return 0;
}