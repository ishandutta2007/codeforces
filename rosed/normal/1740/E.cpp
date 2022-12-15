#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
const int mod=1e9+7;
const int inf=1e18;
const int N=2e5+10;
void solve()
{
    int n;
    cin>>n;
    vector<vector<int> > eg(n+1);
    for(int i=2;i<=n;++i)
    {
        int x;cin>>x ;
        eg[x].emplace_back(i);
    }
    int ans=0;
    vector dp(n+1,vector<int>(2));
    function<void(int,int)> dfs=[&](int now,int fa) -> void
    {
        int ret=0,sum=0;
        for(int t:eg[now])
        {
            if(t==fa) continue;
            dfs(t,now);
            ret=max(ret,dp[t][1]);
            sum+=max(dp[t][0],dp[t][1]);
        }
        dp[now][0]=sum;
        dp[now][1]=ret+1;
        dp[now][0]=max(dp[now][0],dp[now][1]);
    };
    dfs(1,0);
    cout<<dp[1][0]<<'\n';
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