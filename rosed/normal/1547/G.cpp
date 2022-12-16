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
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > eg(n+1);

        for(int i=1;i<=m;++i)
        {
            int x,y;
            cin>>x>>y;
            eg[x].emplace_back(y);
        }
        vector<int> dfn(n+1),low(n+1),st(n+1),col(n+1);
        int top=0,num=0,idx=0;
        
        function<void(int)> tarjan=[&](int now) -> void
        {
            dfn[now]=low[now]=++idx;
            st[++top]=now;
            for(int t:eg[now])
            {
                if(!dfn[t])
                {
                    tarjan(t);
                    low[now]=min(low[now],low[t]);
                }
                else if(!col[t])
                    low[now]=min(low[now],dfn[t]);
            }
            if(dfn[now]==low[now])
            {
                col[now]=++num;
                while(st[top]!=now)
                {
                    col[st[top--]]=num;
                }
                --top;
            }
        };
        for(int i=1;i<=n;++i) if(!dfn[i])
        {
            tarjan(i);
        }
        vector<vector<int> > g(n+1);
        vector<set<int> > e(n+1);
        vector<int> rd(n+1),sum(n+1);
        vector<bool> vis(n+1);
        queue<int> q;
        for(int i=1;i<=n;++i)
        {
            int now=col[i];
            for(int j:eg[i])
            {
                int t=col[j];
                if(now==t) vis[now]=1;
                if(now==t||e[now].find(t)!=e[now].end()) continue;
                g[now].emplace_back(t);
                e[now].insert(t);
                ++rd[t];
            }
        }
        for(int i=1;i<=num;++i) if(!rd[i]) q.push(i);
        sum[col[1]]=1;
        while(!q.empty())
        {
            int now=q.front();
            q.pop();
            for(int t:g[now])
            {
                --rd[t];
                if(sum[now]&&vis[now]) vis[t]=1;
                sum[t]+=sum[now];
                sum[t]=min(sum[t],2ll);
                if(!rd[t]) q.push(t);
            }
        }
        for(int i=1;i<=n;++i)
        {
            int c=col[i];
            if(sum[c]==0) cout<<"0 ";
            else
            {
                if(vis[c]) cout<<"-1 ";
                else if(sum[c]>1) cout<<"2 ";
                else cout<<"1 ";
            }
        }
        cout<<'\n';
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

*/