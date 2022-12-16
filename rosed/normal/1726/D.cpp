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
        vector<vector<pr> > eg(n+1);
        vector<int> ans(m+2);
        for(int i=1;i<=m;++i)
        {
            int x,y;
            cin>>x>>y;
            //a[i]=pr{x,y};
            eg[x].emplace_back(pr{y,i});
            eg[y].emplace_back(pr{x,i});
        }
        vector<bool> vis(n+1);
        vector<int> f(n+1);
        for(int i=1;i<=n;++i) f[i]=i;
        function<int(int)> find=[&](int k) -> int
        {
            return f[k]==k?k:f[k]=find(f[k]);
        };
        function<void(int,int,int)> dfs=[&](int now,int v,int frm) -> void
        {
            vis[now]=1;
            for(auto [t,id]:eg[now])
            {
                if(id==frm) continue;
                if(!vis[t])
                {
                    ans[id]=v;
                    if(v) f[find(now)]=find(t);
                    dfs(t,v^1,id);
                }
                else
                {
                    if(find(now)!=find(t))
                    {
                        ans[id]=1;
                        f[find(now)]=find(t);
                    }
                    
                }
            }
        };
        dfs(1,0,0);
        for(int i=1;i<=m;++i) cout<<ans[i];
        cout<<'\n';
        // if(m==n-1)
        // {
        //     for(int i=1;i<=m;++i) cout<<0;
        //     cout<<'\n';
        //     return;
        // }
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
m/i=(-p%i)*inv[i]

inv[i]*i%p=1

*/