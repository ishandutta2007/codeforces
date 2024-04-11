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
    const int N=1e6+10,inf=2e9,mod=1e9+7;
    int n,m,ans,sum;
    int a[N];
    int fac[N],inv[N];
    inline int fast(int x,int k)
    {
        int ret=1;
        while(k)
        {
            if(k&1) ret=ret*x%mod;
            x=x*x%mod;
            k>>=1;
        }
        return ret;
    }
    inline int C(int n,int m)
    {
        return fac[n]*inv[m]%mod*inv[n-m]%mod;
    }
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        cin>>n;
        for(int i=0;i<=n;++i)
        {
            cin>>a[i];
        }
        inv[0]=fac[0]=1;
        for(int i=1;i<=4e5;++i) fac[i]=fac[i-1]*i%mod;
        inv[400000]=fast(fac[400000],mod-2);
        for(int i=4e5-1;i>=1;--i) inv[i]=inv[i+1]*(i+1)%mod;
        for(int i=0;i<=n;++i)
        {
            // for(int j=0;j<a[i];++j)
            // {
            //     ans+=C(i+j,i);
            //    // cout<<i<<' '<<j<<' '<<C(i+j,i)<<endl;
            // }

            ans+=C(i+a[i],i+1);
            ans%=mod;
        }
        //c[i][j]=c[i-1][j-1]+c[i-1][j]
        //
        cout<<ans<<'\n';
       // cout<<(ans%mod+mod)%mod<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
2.25 10 100


1+2
*/