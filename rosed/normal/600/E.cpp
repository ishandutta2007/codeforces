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
    const int N=1e5+10,mod=1e9+7,inf=2e9;
    int n,tot;
    int str[N],son[N];
    int col[N],ret[N];
    int ans,maxn,cnt[N];
    vector<int> eg[N];
    inline void dfs(int now,int fa)
    {
        str[now]=1;
        for(int t:eg[now])
        {
            if(t==fa) continue;
            dfs(t,now);
            str[now]+=str[t];
            if(str[t]>str[son[now]]) son[now]=t;
        }
    }
    inline void add(int x)
    {
        ++cnt[x];
        if(cnt[x]==maxn) ans+=x;
        if(cnt[x]>maxn) maxn=cnt[x],ans=x;
    }
    inline void dfs3(int now,int fa)
    {
        --cnt[col[now]];
        for(int t:eg[now])
        {
            if(t==fa) continue;
            dfs3(t,now);
        }
    }
    inline void dfs2(int now,int fa)
    {
        add(col[now]);
        for(int t:eg[now])
        {
            if(t==fa) continue;
            dfs2(t,now);
        }
    }
    inline void dfs1(int now,int fa)
    {
        for(int t:eg[now])
        {
            if(t==fa||t==son[now]) continue;
            dfs1(t,now);
            dfs3(t,now);
            ans=maxn=0;
        }
        if(son[now]) dfs1(son[now],now);
        for(int t:eg[now])
        {
            if(t==fa||t==son[now]) continue;
            dfs2(t,now);
        }
        add(col[now]);
        ret[now]=ans;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;++i) cin>>col[i];
        for(int i=1;i<n;++i)
        {
            int x,y;
            cin>>x>>y;
            eg[x].emplace_back(y);
            eg[y].emplace_back(x);
        } 
        dfs(1,0);
        dfs1(1,0);
        for(int i=1;i<=n;++i) cout<<ret[i]<<' ';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*


*/