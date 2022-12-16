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
    const int N=1e6+10,mod=998244353,inv2=499122177,inf=2e18;
    void __init(int n=2000) {}
    
    inline void main()
    {
        int n,m,t,mod;
        cin>>n>>t>>mod;
        m=(1<<n);
        mod*=m;
        vector<int> a(m),b(n+1),c(m);
        for(int i=0;i<m;++i) cin>>a[i];
        for(int i=0;i<=n;++i) cin>>b[i];
        for(int i=0;i<m;++i)
        {
            c[i]=b[__builtin_popcount(i)];
        }
        auto fast=[&](int x,int k) -> int
        {
            int ret=1;
            while(k)
            {
                if(k&1) ret=(__int128)ret*x%mod;
                x=(__int128)x*x%mod;
                k>>=1;
            }
            return ret;
        };
        auto fwt=[&](vector<int> &a,int inv) -> void
        {
            for(int k=1;2*k<=m;k<<=1)
            {
                for(int i=0;i<m;i+=2*k)
                {
                    for(int j=0;j<k;++j)
                    {
                        int x=a[i+j],y=a[i+j+k];
                        a[i+j]=(x+y)%mod;
                        a[i+j+k]=(x-y+mod)%mod;
                    }
                }
            }
            if(inv)
            {
                for(int i=0;i<m;++i) a[i]/=m;
            }
        };
        fwt(c,0);fwt(a,0);
        for(int i=0;i<m;++i)
        {
            a[i]=(__int128)a[i]*fast(c[i],t)%mod;
        }
        fwt(a,1);
        for(int i=0;i<m;++i) cout<<a[i]<<'\n';
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

*/