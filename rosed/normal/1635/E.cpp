#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n,m;
    bool flag=1;
    vector<int> eg[N];
    vector<int> g[N];
    int col[N],rd[N];
    queue<int> q;
    struct edge
    {
        int opt,x,y;
    }e[N];
    int ans[N],idx;
    inline void dfs(int now,int c)
    {
        col[now]=c;
        for(auto t:eg[now])
        {
            if(col[t])
            {
                if(col[t]==col[now]) flag=0;
                continue;
            }
            dfs(t,c^1);
        }
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=m;++i)
        {
            int opt,x,y;cin>>opt>>x>>y;
            e[i]=(edge){opt,x,y};
            eg[x].push_back(y);
            eg[y].push_back(x);
        }
        for(int i=1;i<=n;++i)
        {
            if(!col[i]) dfs(i,2);
        }
        for(int i=1;i<=m;++i)
        {
            if(col[e[i].x]==3) swap(e[i].x,e[i].y);
            if(e[i].opt==1) g[e[i].x].push_back(e[i].y),++rd[e[i].y];
            else g[e[i].y].push_back(e[i].x),++rd[e[i].x];
        }
        for(int i=1;i<=n;++i) if(!rd[i]) q.push(i);
        while(!q.empty())
        {
            int now=q.front();
            q.pop();
            ans[now]=++idx;
            for(int t:g[now])
            {
                --rd[t];
                if(!rd[t]) q.push(t);
            }
        }
        for(int i=1;i<=n;++i) if(!ans[i]) flag=0;
        if(!flag) cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            for(int i=1;i<=n;++i)
            {
                if(col[i]==2) cout<<"L ";
                else cout<<"R ";
                cout<<ans[i]<<'\n';
            }
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*

*/