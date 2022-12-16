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
    const int N=1e5+10,mod=998244353,inv2=5e8+4,inf=1e18;
    const double pi=acos(-1.0);
    int n;
    vector dp(2,vector<int>(N));
    void main()
    {
        cin>>n;
        vector<int> a(n+1);
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        int opt=0,ans=0;
        vector v(2,vector<int>());
        for(int i=n;i>=1;--i)
        {
            opt^=1;
            v[opt].emplace_back(a[i]);
            dp[opt][a[i]]=1;
            int pre=a[i];
            for(auto x:v[opt^1])
            {
                int y=dp[opt^1][x];
                int t1=(a[i]+x-1)/x;
                int t2=a[i]/t1;
                ans=(ans+i*(t1-1)%mod*y%mod)%mod;
                dp[opt][t2]+=y;
                dp[opt][t2]%=mod;
                if(t2!=pre) v[opt].emplace_back(t2),pre=t2;
            }
            for(auto x:v[opt^1]) dp[opt^1][x]=0;
            v[opt^1].clear();
        }
        for(auto x:v[opt]) dp[opt][x]=0;
        cout<<ans<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int qwq=1;cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*
20 4
25 66 10 18 67 40 66 49 3 51 61 29 10 72 71 22 63 4 74 67

*/