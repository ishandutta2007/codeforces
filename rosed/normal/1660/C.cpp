#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=2e5+10,mod=998244353,inf=2e9;
    int n,minn,ans;
    char s[N];
    int dp[N];
    int pre[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>(s+1);ans=inf;
            n=strlen(s+1);
            for(int i=0;i<26;++i) pre[i]=0;
            for(int i=1;i<=n;++i)
            {
                int t=s[i]-'a';
                dp[i]=dp[i-1]+1;
                if(pre[t]) dp[i]=min(dp[i],dp[pre[t]-1]+(i-pre[t]-1));
                ans=min(ans,dp[i]+n-i);
                pre[t]=i;
            }
            cout<<dp[n]<<'\n';
            //cout<<ans<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
1
1 2 3 4

*/