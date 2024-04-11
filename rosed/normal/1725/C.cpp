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
        int n,m;
        cin>>n>>m;
        vector<int> dis(2*n);
        int sum=0;
        for(int i=0;i<n;++i) cin>>dis[i],sum+=dis[i];
        for(int i=n;i<2*n;++i) dis[i]=dis[i-n];
        int tot=0,t=0;
        int tmp=0;
        for(int i=0;i<n;++i)
        {
            while((tot+dis[t])*2<=sum&&t<2*n) tot+=dis[t],++t;
            if(tot*2==sum) ++tmp;
            tot-=dis[i];
        }
        tmp/=2;
        assert(tmp*2<=n);
        vector<int> down(m+1),fac(n+1),inv(n+1);
        down[0]=1;
        for(int i=1;i<=m;++i) down[i]=down[i-1]*(m-i+1)%mod;
        fac[0]=inv[0]=1;
        for(int i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
        inv[n]=fast(fac[n],mod-2);
        for(int i=n-1;i>=1;--i) inv[i]=inv[i+1]*(i+1)%mod;
        auto C=[&](int n,int m) -> int
        {
            if(n<m||m<0) return 0;
            return fac[n]*inv[m]%mod*inv[n-m]%mod;
        };
        int ans=0;
        for(int i=0;i<=min(tmp,m);++i)
        {
            ans=(ans+C(tmp,i)*down[i]%mod*fast((m-i)*(m-i-1)%mod,tmp-i)%mod*fast(m-i,n-2*tmp)%mod)%mod;
        }
        cout<<ans<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; //cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*
m/i=(-p%i)*inv[i]

inv[i]*i%p=1

*/