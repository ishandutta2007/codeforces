#include <cstdio>
#include <cstring>
#define maxn 200005
#define base 1000000007

long long frac[maxn],inv[maxn],n;

inline long long calc(long long x,long long t)
{
    if (!t) return 1;
    long long y=calc(x,t/2);
    y=y*y%base;
    if (t%2) y=y*x%base;
    return y;
}

int main()
{
    scanf("%I64d",&n);
    frac[0]=inv[0]=1;
    for (int i=1;i<=2*n;++i)
    {
        frac[i]=frac[i-1]*i%base;
        inv[i]=calc(frac[i],base-2);
    }
    
    //C(2*n-1,n-1)
    long long ans=(frac[2*n-1]*inv[n-1]%base)*inv[n]%base;
    ans=ans*2%base;
    ans=(ans+(base-n))%base;
    
    printf("%d\n",(int)ans);
    
    return 0;
}