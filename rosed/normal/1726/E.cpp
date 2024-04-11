#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=1e6+10,mod=998244353,inv2=(mod+1)/2,inf=2e18;
    void __init(int n=2000) {}
    inline void main()
    {
        auto fast=[&](int x,int k) -> int
        {
            int ret=1;
            while(k)
            {
                if(k&1) ret=ret*x%mod;
                x=x*x%mod;
                k>>=1;
            }
            return ret;
        };
        int n;
        cin>>n;
        int ans=0;
        vector<int> f(n+1),fac(n+1),inv(n+1);
        f[0]=fac[0]=inv[0]=1;
        for(int i=1;i<=n;++i)
        {
            f[i]=f[i-1];
            if(i>1) f[i]=(f[i]+(i-1)*f[i-2])%mod;
            fac[i]=fac[i-1]*i%mod;
        }
        inv[n]=fast(fac[n],mod-2);
        for(int i=n-1;i>=1;--i) inv[i]=inv[i+1]*(i+1)%mod;
        for(int k=0;4*k<=n;++k) ans=(ans+fac[n-2*k]*inv[n-4*k]%mod*inv[k]%mod*f[n-4*k]%mod)%mod;
        cout<<ans<<'\n';        
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*
m/i=(-p%i)*inv[i]

inv[i]*i%p=1

*/