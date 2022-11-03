/*
ID: Sfiction
OJ: CF
PROB: 336B
*/
#include <cstdio>
const double t=1.4142135623731;
int main()
{
    long long i,n;
    double r,ans;
    scanf("%I64d%lf",&n,&r);
    ans=0;
    for (i=1;i<=n;++i)
    {
        ans+=2;
        if (i>1) ans+=2+t;
        if (i<n) ans+=2+t;
        if (i>2) ans+=(i-1)*(i-2)+2*t*(i-2);
        if (i<n-1) ans+=(n-i)*(n-i-1)+2*t*(n-i-1);
    }
    ans*=r;
    ans/=n*n;
    printf("%.10lf",ans);
    return 0;
}