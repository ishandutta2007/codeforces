#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
const int mod=998244353;
void solve()
{
    auto fast=[&](int x,int k) -> int
    {
        x%=mod;
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
    int ans=0;
    vector<int> f(n+1);
    f[0]=1;
    int tmp=1;
    for(int i=1;i<=n;++i)
    {
        ans=(ans+fast(m,i))%mod;
    }
    auto check=[&](int x) -> bool
    {
        for(int i=2;i*i<=x;++i)
        {
            if(x%i==0) return 0;
        }
        return 1;
    };
    for(int i=1;i<=n;++i)
    {
        if(check(i)) m/=i;
        if(m==0) break;
        f[i]=f[i-1]*(m%mod)%mod;
        ans=(ans+mod-f[i])%mod;
    }
    cout<<ans<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;//cin>>T;
    while(T--) solve();
    return 0;
}
/*


*/