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
    int n,m;
    struct edge
    {
        int x,y,z;
    }a[N];
    bool viss[N];
    int f[N];
    vector<int> eg[N];
    inline int find(int k){return f[k]==k?k:f[k]=find(f[k]);}
    int fa[N][21];
    int dep[N],lg[N],cf[N];
    //set<int> vis[N];
    int vis[N];
    bool sha[N],gong[N],mg[N],ans[N];
    int tl[N],tr[N],di[N];
    int idx;
    inline void dfs(int now,int from)
    {
        tl[now]=++idx;
        di[idx]=now;
        fa[now][0]=from;
        dep[now]=dep[from]+1;
        for(int i=1;i<=20;++i) fa[now][i]=fa[fa[now][i-1]][i-1];
        for(int t:eg[now])
        {
            if(t==fa[now][0]) continue;
            dfs(t,now);
        }
        tr[now]=idx;
    }
    inline int getlca(int x,int y)
    {
        while(dep[x]!=dep[y])
        {
            if(dep[x]<dep[y]) swap(x,y);
            x=fa[x][lg[dep[x]-dep[y]]-1];
        }
        if(x==y) return x;
        for(int i=20;~i;--i) if(fa[x][i]^fa[y][i])
            x=fa[x][i],y=fa[y][i];
        return fa[x][0];
    }
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=m;++i)
        {
            cin>>a[i].x>>a[i].y;
            a[i].z=i;
        }
        for(int i=1;i<=n;++i) f[i]=i,lg[i]=lg[i>>1]+1;
        lg[0]=1;
        for(int i=1;i<=m;++i)
        {
            int x=a[i].x,y=a[i].y;
            if(find(x)==find(y)) continue;
            f[find(x)]=find(y);
            eg[x].emplace_back(y);
            eg[y].emplace_back(x);
            viss[i]=1;
        }
        dfs(1,0);
        for(int i=1;i<=m;++i) if(!viss[i])
        {
            int x=a[i].x,y=a[i].y,lca=getlca(x,y);
            if(lca!=x&&lca!=y)
            {
                ++cf[1];
                --cf[tl[x]];
                ++cf[tr[x]+1];
                --cf[tl[y]];
                ++cf[tr[y]+1];
            }
            else
            {
                if(lca==y) swap(x,y);
                int pos=y;
                for(int k=20;~k;--k)
                {
                    if(dep[fa[pos][k]]>dep[x]) pos=fa[pos][k];
                }
                ++cf[tl[pos]];
                --cf[tr[pos]+1];
                --cf[tl[y]];
                ++cf[tr[y]+1];
            }
        }
        for(int i=1;i<=n;++i) cf[i]+=cf[i-1];
        for(int i=1;i<=n;++i)
        {
            if(cf[i]) ans[di[i]]=0;
            else ans[di[i]]=1;
        }
        for(int i=1;i<=n;++i) cout<<ans[i];
        cout<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*

3 4
1 2
2 3
1 3
1 2

*/