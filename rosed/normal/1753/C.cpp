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
        int ret=1;
        while(k)
        {
            if(k&1) ret=ret*x%mod;
            x=x*x%mod;
            k>>=1;
        }
        return ret;
    };
    auto fac=[&](int n) -> int
    {
        if(!n) return 0;
        int ret=1;
        for(int i=1;i<=n;++i) ret=ret*i%mod;
        return ret;
    };
    int n;
    cin>>n;
    vector<int> a(n+1);
    int sum0=0,sum=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]==0) ++sum0;
    }
    for(int i=1;i<=sum0;++i) sum+=a[i];
    if(!sum)
    {
        cout<<0<<'\n';
        return;
    }
    int ret=1;
    for(int k=sum;k>=1;--k)
    {
        int p=n*(n-1)/2;
        p%=mod;
        p=fast(p,mod-2)%mod;
        p=p*k%mod*k%mod;
        ret=ret+fast(p,mod-2);
        ret%=mod;
    }

    cout<<(ret+mod-1)%mod<<'\n';

}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;cin>>T;
    while(T--) solve();
    return 0;
}
/*


*/