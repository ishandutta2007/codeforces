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
    
    inline void main()
    {
        int n,m,k;
        cin>>n>>m>>k;
        typedef pair<int,int> pr;
        vector<vector<pr> > eg(n+1);
        for(int i=1;i<=m;++i)
        {
            int x,y,z;
            cin>>x>>y>>z;
            eg[x].emplace_back(pr(y,z));
            eg[y].emplace_back(pr(x,z));
        }
        vector<int> dis(n+1,inf);
        vector<bool> vis(n+1);
        auto spfa=[&]() -> void
        {
            dis[1]=0;
            priority_queue<pr,vector<pr>,greater<pr> > q;
            for(int i=1;i<=n;++i)
            {
                q.push(pr(dis[i],i));
                vis[i]=0;
            }
            while(!q.empty())
            {
                int now=q.top().second;
                q.pop();
                if(vis[now]) continue;
                vis[now]=1;
                for(auto [t,v]:eg[now])
                {
                    if(dis[t]>dis[now]+v)
                    {
                        dis[t]=dis[now]+v;
                        q.push(pr(dis[t],t));
                    }
                }
            }
        };
        spfa();
        vector<int> dp(n+1);
        auto y=[&](int i) -> double
        {
            return dp[i]+i*i;
        };
        auto x=[&](int i) -> double
        {
            return i;
        };
        auto slope=[&](int i,int j) -> double
        {
            return (y(i)-y(j))/(x(i)-x(j));
        };
        
        vector<int> q(2*n+1);
        for(int opt=1;opt<=k;++opt)
        {
            for(int i=1;i<=n;++i) dp[i]=dis[i];
            
            int head=1,tail=0;
            for(int i=1;i<=n;++i)
            {
                while(head<tail&&slope(q[head],q[head+1])<2*i) ++head;
                if(head<=tail)
                {
                    int j=q[head];
                    dis[i]=min(dis[i],dp[j]+(i-j)*(i-j));
                }
                while(head<tail&&slope(q[tail],q[tail-1])>slope(q[tail-1],i)) --tail;
                q[++tail]=i;
            }
            head=1,tail=0;
            for(int i=n;i>=1;--i)
            {
                while(head<tail&&slope(q[head],q[head+1])>2*i) ++head;
                if(head<=tail)
                {
                    int j=q[head];
                    dis[i]=min(dis[i],dp[j]+(i-j)*(i-j));
                }
                while(head<tail&&slope(q[tail],q[tail-1])<slope(q[tail-1],i)) --tail;
                q[++tail]=i;
            }
            spfa();

        }
        for(int i=1;i<=n;++i) cout<<dis[i]<<' ';

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