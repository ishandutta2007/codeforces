#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
const int mod=1e9+7;
const int inf=1e15;
void solve()
{
    int n,m,p,q;
    cin>>n>>m>>p>>q;
    vector<string> s(n+1);
    typedef array<int,2> pr; 
    vector<vector<pr> > eg(n*m+5);
    int st=n*m+1;
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        s[i]="#"+s[i];
        for(int j=1;j<=m;++j)
        {
            if(s[i][j]=='.') eg[st].emplace_back(pr{(i-1)*m+j,0});
        }
    }
    auto id=[&](int x,int y) -> int
    {
        return (x-1)*m+y;
    };
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(s[i][j]!='.'&&s[i][j]!='#')
            {
                int x=i,y=j,tx=x,ty=y;
                if(s[i][j]=='L')
                {
                    ++ty;
                    if(ty+1<=m)
                    {
                        eg[id(tx,ty+1)].emplace_back(pr{id(x,y),q});
                    }
                    if(tx-1>=1)
                    {
                        eg[id(tx-1,ty)].emplace_back(pr{id(x,y),p});
                    }
                    if(tx+1<=n)
                    {
                        eg[id(tx+1,ty)].emplace_back(pr{id(x,y),p});
                    }
                }
                if(s[i][j]=='R')
                {
                    --ty;
                    if(ty-1>=1)
                    {
                        eg[id(tx,ty-1)].emplace_back(pr{id(x,y),q});
                    }
                    if(tx-1>=1)
                    {
                        eg[id(tx-1,ty)].emplace_back(pr{id(x,y),p});
                    }
                    if(tx+1<=n)
                    {
                        eg[id(tx+1,ty)].emplace_back(pr{id(x,y),p});
                    }
                }
                if(s[i][j]=='U')
                {
                    ++tx;
                    if(tx+1<=n)
                    {
                        eg[id(tx+1,ty)].emplace_back(pr{id(x,y),q});
                    }
                    if(ty-1>=1)
                    {
                        eg[id(tx,ty-1)].emplace_back(pr{id(x,y),p});
                    }
                    if(ty+1<=m)
                    {
                        eg[id(tx,ty+1)].emplace_back(pr{id(x,y),p});
                    }
                }
                if(s[i][j]=='D')
                {
                    --tx;
                    if(tx-1>=1)
                    {
                        eg[id(tx-1,ty)].emplace_back(pr{id(x,y),q});
                    }
                    if(ty-1>=1)
                    {
                        eg[id(tx,ty-1)].emplace_back(pr{id(x,y),p});
                    }
                    if(ty+1<=m)
                    {
                        eg[id(tx,ty+1)].emplace_back(pr{id(x,y),p});
                    }
                }
            }
        }
    }
    vector<int> dis(n*m+5,inf);
    vector<bool> vis(n*m+5);
    // cout<<st<<"!!!"<<endl;
    priority_queue<pr,vector<pr>,greater<pr> > qq;
    auto spfa=[&]() -> void
    {
        dis[st]=0;
        qq.push(pr{dis[st],st});
        while(!qq.empty())
        {
            int now=qq.top()[1];
            // cout<<now<<"!!!"<<endl;
            qq.pop();
            if(vis[now]) continue;
            vis[now]=1;
            for(auto [t,v]:eg[now])
            {
                if(dis[t]>dis[now]+v)
                {
                    dis[t]=dis[now]+v;
                    qq.push(pr{dis[t],t});
                }
            }
        }
    };
    spfa();
    int ans=inf;
    int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            int x=i,y=j;
            for(int k=0;k<4;++k)
            {
                int tx=x+dx[k],ty=y+dy[k];
                if(tx<1||ty<1||tx>n||ty>m) continue;
                ans=min(ans,dis[(x-1)*m+y]+dis[(tx-1)*m+ty]);
                // if(dis[(x-1)+y]+dis[(tx-1)*m+ty]==20) cout<<x<<' '<<y<<' '<<tx<<' '<<ty<<"!!"<<endl;
            }
        }
    }
    if(ans>=inf) ans=-1;
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