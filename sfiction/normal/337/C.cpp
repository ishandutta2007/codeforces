/*
ID: Sfiction
OJ: CF
PROB: 337C
*/
#include <cstdio>
int main()
{
    const int g=1000000009;
    int n,m,k;
    int t;
    long long e,s;
    scanf("%d%d%d",&n,&m,&k);
    t=m-n+n/k;
    if (t<=0)
    {
        printf("%d",m);
        return 0;
    }
    m-=t*k;
    ++t;
    s=1;
    e=2;
    while (t)
    {
        if (t&1) s=(s*e)%g;
        e=(e*e)%g;
        t>>=1;
    }
    s=(s-2+g)%g;
    s*=k;
    s=(s+m)%g;
    printf("%I64d",s);
    return 0;
}