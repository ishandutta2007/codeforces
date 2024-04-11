#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,inf=2e9,mod=998244353;
    int n,m,kk;
    int a[N];
    struct edge
    {
        int x,y,id;
    }e[N];
    int f[N];
    inline int find(int k){return f[k]==k?k:f[k]=find(f[k]);}
    typedef pair<int,int> pr;
    vector<pr> eg[N];
    int g[N][18],fa[N][18];
    int bz[N][18];
    int dep[N],lg[N];
    inline void dfs(int now,int faa)
    {
        dep[now]=dep[faa]+1;
        for(int i=1;i<=17;++i) fa[now][i]=fa[fa[now][i-1]][i-1],g[now][i]=max(g[now][i-1],g[fa[now][i-1]][i-1]);
        
        for(auto [t,v]:eg[now])
        {
            if(t==faa) continue;
            //cout<<now<<' '<<t<<"!!"<<endl;
            g[t][0]=v;
            fa[t][0]=now;
            dfs(t,now);
        }
    }
    inline int getlca(int x,int y)
    {
        while(dep[x]^dep[y])
        {
            if(dep[x]<dep[y]) swap(x,y);
            x=fa[x][lg[dep[x]-dep[y]]-1];
        }
        if(x==y) return x;
        for(int i=17;~i;--i) if(fa[x][i]^fa[y][i])
        {
            x=fa[x][i],y=fa[y][i];
        }
        return fa[x][0];
    }
    inline int check(int l,int r)
    {
        int k=lg[r-l+1]-1;
        return max(bz[l][k],bz[r-(1<<k)+1][k]);
    }
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>n>>m>>kk;
            lg[0]=0;
            for(int i=1;i<=n;++i)
            {
                f[i]=i,lg[i]=lg[i>>1]+1;
                eg[i].clear();
            }
            lg[0]=1;
            for(int i=1;i<=m;++i)
            {
                int x,y;cin>>x>>y;
                if(find(x)==find(y)) continue;
                eg[x].emplace_back(pr(y,i));
                eg[y].emplace_back(pr(x,i));
                f[find(x)]=find(y);
            }
            dfs(1,0);

            for(int i=1;i<n;++i)
            {
                int lca=getlca(i,i+1);
                int val=0;
                int x=i;
                for(int k=17;~k;--k)
                {
                    if(dep[fa[x][k]]>=dep[lca])
                    {
                        val=max(val,g[x][k]);
                        x=fa[x][k];
                    }
                }
                x=i+1;
                for(int k=17;~k;--k)
                {
                    if(dep[fa[x][k]]>=dep[lca])
                    {
                        val=max(val,g[x][k]);
                        x=fa[x][k];
                    }
                }
                bz[i][0]=val;
                //cout<<val<<"!!"<<endl;
            }
            for(int k=1;k<=17;++k)
            {
                for(int i=1;i+(1<<k)-1<n;++i)
                {
                    bz[i][k]=max(bz[i][k-1],bz[i+(1<<(k-1))][k-1]);
                }
            }
            for(int i=1;i<=kk;++i)
            {
                int l,r;cin>>l>>r;
                int pos=l;
                if(l==r)
                {
                    cout<<0<<' ';
                    continue;
                }
                cout<<check(l,r-1)<<' ';
            }
            cout<<'\n';    
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
5 5 5
1 2
1 3
2 4
3 4
3 5
1 4
3 4
2 2
2 5
3 5

*/