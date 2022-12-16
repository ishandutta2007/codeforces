#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,inf=2e9,mod=1e9+7;
    int n,maxn,rt,ret;
    int a[N];
    int f[N],g[N];
    vector<int> eg[N];
    inline void dfs(int now,int fa)
    {
        for(int t:eg[now])
        {
            if(t==fa) continue;
            dfs(t,now);
            if(f[t]>f[now]) g[now]=f[now],f[now]=f[t];
            else g[now]=max(g[now],f[t]);
        }
        if(now!=rt)
        {
            if(f[now]==0) f[now]=a[now],ret+=a[now];
            else
            {
                if(f[now]<a[now]) ret+=a[now]-f[now],f[now]=a[now];
            }
        }
        else
        {
            ret+=a[now]-f[now]+a[now]-g[now];
        }
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            if(a[i]>maxn) maxn=a[i],rt=i;
        }
        for(int i=1;i<n;++i)
        {
            int x,y;cin>>x>>y;
            eg[x].push_back(y);
            eg[y].push_back(x);
        }
        dfs(rt,0);
        cout<<ret<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*

*/