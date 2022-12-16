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
    const int N=1e6+10,mod=998244353,inv2=499122177,inf=2e18;
    void __init(int n=2000) {}
    
    inline void main()
    {
        int n,m;cin>>n>>m;
        vector<int> p(n+1);
        int rt=0;
        vector<vector<int> > eg(n+1),g(n+1);
        vector<set<int> > pre(n+1);
        vector<int> rd(n+1),id(n+1),sum(n+1);
        for(int i=1;i<=n;++i)
        {
            cin>>p[i];
        }
        for(int i=1;i<=m;++i)
        {
            int x,y;cin>>x>>y;
            eg[x].emplace_back(y);
            ++rd[y];
        }
        int num=0;
        auto dfs=[&](auto dfs,int now,int top) -> void
        {
            g[top].emplace_back(now);
            id[now]=top;
            ++sum[top];
            for(int t:eg[now])
            {
                dfs(dfs,t,top);
            }
        };
        
        for(int i=1;i<=n;++i)
        {
            if(!rd[i]) dfs(dfs,i,++num);
        }
        for(int i=1;i<=n;++i)
        {
            rd[i]=0;
            eg[i].clear();
        }
        for(int i=1;i<=n;++i)
        {
            if(!p[i]) continue;
            int x=id[p[i]],y=id[i];
            if(x==y) continue;
            eg[x].emplace_back(y);
            ++rd[y];
        }
        vector<int> ans;
        int tot=0;
        auto topo=[&]() -> void
        {
            queue<int> q;
            for(int i=1;i<=n;++i)
            {
                if(!rd[i]) q.push(i);
            }
            while(!q.empty())
            {
                int now=q.front();
                q.pop();
                for(int x:g[now]) ans.emplace_back(x);
                tot+=sum[now];
                for(int t:eg[now])
                {
                    if(!--rd[t]) q.push(t);
                }
            }
        };
        topo();
        if(tot!=n) {cout<<"0";return;}
        vector<bool> vis(n+1);
        for(int t:ans)
        {
            if(p[t]&&!vis[p[t]])
            {
                cout<<0;return;
            }
            vis[t]=1;
        }
        for(int t:ans) cout<<t<<' ';
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