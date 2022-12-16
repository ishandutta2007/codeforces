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
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e18;
    void __init(int n=2000) {}
    inline void main()
    {
        int n,m;
        cin>>n>>m;
        typedef array<int,2> pr;
        vector<vector<pr> > eg(n+1),g(n+1);
        for(int i=1;i<=m;++i)
        {
            int x,y,z;
            cin>>x>>y>>z;
            eg[x].emplace_back(pr{y,z});
            g[y].emplace_back(pr{x,z});
        }
        vector<int> dis(n+1,inf);dis[1]=0;
        vector<bool> vis(n+1);
        priority_queue<pr,vector<pr>,greater<pr> > q;
        auto spfa=[&](auto &g) -> void
        {
            for(int i=1;i<=n;++i)
            {
                vis[i]=0;
                q.push(pr{dis[i],i});
            }
            while(!q.empty())
            {
                int now=q.top()[1];
                q.pop();
                if(vis[now]) continue;
                vis[now]=1;
                for(auto [t,v]:g[now])
                {
                    if(dis[t]>dis[now]+v)
                    {
                        dis[t]=dis[now]+v;
                        q.push(pr{dis[t],t});
                    }
                }
            }
        };
        spfa(eg);
        spfa(g);
        for(int i=2;i<=n;++i)
        {
            if(dis[i]>=inf) dis[i]=-1;
            cout<<dis[i]<<" \n"[i==n];
        }
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
m/i=(-p%i)*inv[i]

inv[i]*i%p=1

*/