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
    const int N=1e6+10,mod=1e4+7,inf=2e9;
    int n,m,tot;
    int a[N];
    vector<int> eg[N];
    int rd[N],cd[N],r[N];
    int dp[N],ans;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T=1;
        while(T--)
        {
            cin>>n>>m;
            for(int i=1;i<=m;++i)
            {
                int x,y;
                cin>>x>>y;
                eg[x].emplace_back(y);
                ++rd[y];++cd[x];
                ++r[y];
            }
            queue<int> q;
            for(int i=1;i<=n;++i)
            {
                dp[i]=1;
                if(!rd[i])
                {
                    q.push(i);
                }
            }
            while(!q.empty())
            {
                int now=q.front();
                q.pop();
                ans=max(ans,dp[now]);
                for(int t:eg[now])
                {
                    if(r[t]>1&&cd[now]>1) dp[t]=max(dp[t],dp[now]+1);
                    --rd[t];
                    if(!rd[t]) q.push(t);
                }
            }
            cout<<ans<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
4 5
1 2
2 3
1 4
4 3
4 2


*/