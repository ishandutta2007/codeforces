/*
ID: Sfiction
OJ: CF
PROB: 341A
*/
#include <cstdio>
#include <cstdlib>
const int MAXN=100000;
long long a[MAXN];
int Comp(const void *a,const void *b)
{
    return *(long long *)a-*(long long *)b;
}
long long Euclid(long long a,long long b)
{
    if (b) return Euclid(b,a%b);
    else return a;
}
int main()
{
    int n,i;
    long long x,y,d;
    scanf("%d",&n);
    for (i=0;i<n;++i) scanf("%I64d",&a[i]);
    qsort(a,n,sizeof(long long),Comp);
    x=0;
    for (i=0;i<n;++i) x+=a[i]*(1-n+2*i);
    x<<=1;
    for (i=0;i<n;++i) x+=a[i];
    y=n;
    d=Euclid(x,y);
    printf("%I64d %I64d",x/d,y/d);
    return 0;
}