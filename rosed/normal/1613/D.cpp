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
    const int N=1e6+10,mod=998244353,inf=2e15;
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
        vector<int> a(n);
        vector dp(n+2,vector<int>(2));
        for(int i=0;i<n;++i)
        {
            int x;cin>>x;
            if(x!=0)
            {
                dp[x-1][1]=(2*dp[x-1][1]+dp[x-1][0])%mod;
            }
            dp[x+1][0]=(2*dp[x+1][0]+dp[x][0])%mod;
            dp[x+1][1]=2*dp[x+1][1]%mod;
            if(x==0) ++dp[1][0];
            if(x==1) ++dp[0][1];
        }
        int ans=0;
        for(int i=0;i<=n+1;++i) ans=(ans+dp[i][0]+dp[i][1])%mod;
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
1 2 5 10


*/