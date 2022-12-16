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
    const int N=1e6+10,mod=1e9+7,inv2=5e8+4,inf=2e15;
    void __init(int n=2000) {}
    
    inline void main()//
    {
        int n,x,y;cin>>n>>x>>y;
        int m=x+y;
        int S=(1<<22);
        vector dp(2,vector<int>(S,-inf));
        dp[0][0]=0;
        int ans=0,opt=0;
        for(int i=1;i<=m;++i)
        {
            opt^=1;
            for(int k=0;k<S;++k) dp[opt][k]=-inf;
            for(int k=0;k<S;++k)
            {
                dp[opt][(S-1)&(k<<1)]=max(dp[opt][(S-1)&(k<<1)],dp[opt^1][k]);
                if((k>>(x-1))&1) continue;
                if((k>>(y-1))&1) continue;
                dp[opt][((S-1)&(k<<1))|1]=max(dp[opt][((S-1)&(k<<1))|1],dp[opt^1][k]+n/m+(n%m>=i));
            }  
            for(int k=0;k<S;++k) ans=max(ans,dp[opt][k]);
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

*/