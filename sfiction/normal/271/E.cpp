/*
ID: Sfiction
OJ: CF
PROB: 271E
*/
#include <cstdio>
#include <cmath>
const int MAXN=100000;
int a[MAXN];
int N,M;
int Euclid(int a,int b)
{
    return b?Euclid(b,a%b):a;
}
long long Check(int x)
{
    long long sum;
    for (sum=0;x<M;x<<=1) sum+=M-x;
    return sum;
}
int main()
{
    long long sum;
    int T,i,gcd;
    scanf("%d%d",&N,&M);
    for (i=0;i<N;++i) scanf("%d",&a[i]);
    gcd=a[0]-1;
    for (i=1;i<N;++i) gcd=Euclid(gcd,a[i]-1);
    while (gcd%2==0) gcd>>=1;
    T=sqrt(gcd);
    sum=0;
    for (i=1;i<=T;++i)
        if (gcd%i==0) sum+=Check(i)+Check(gcd/i);
    if (T*T==gcd) sum-=Check(T);
    printf("%I64d",sum);
    return 0;
}