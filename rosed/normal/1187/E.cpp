#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=5e5+10,mod=1e9+7,inv2=5e8+4,inf=2e9;
    const double pi=acos(-1.0);
    int n;
    vector<int> eg[N];
    int str[N];
    int ans;
    int f[N],g[N];
    int dep[N];
    inline void dfs(int now,int fa)
    {
        dep[now]=dep[fa]+1;
        str[now]=1;
        for(int t:eg[now])
        {
            if(t==fa) continue;
            dfs(t,now);
            str[now]+=str[t];
            f[now]+=f[t];
        }
        f[now]+=str[now];
    }
    inline void dfs1(int now,int fa)
    {
        //cout<<now<<' '<<f[now]+g[now]<<"!!"<<endl;
        ans=max(ans,f[now]+g[now]);
        for(int t:eg[now])
        {
            if(t==fa) continue;
            g[t]=g[now]+(f[now]-f[t]-str[t])+(n-str[t]);
            dfs1(t,now);
        }
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        for(int i=1;i<n;++i)
        {
            int x,y;cin>>x>>y;
            eg[x].emplace_back(y);
            eg[y].emplace_back(x);
        }
        dfs(1,0);
        dfs1(1,0);
        cout<<ans<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
aab

*/