#include<bits/stdc++.h>
using namespace std;
namespace red{
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n,m;
    int a[N];
    vector<int> eg[N];
    int dep[N],sum[N];
    inline void dfs(int now,int fa)
    {
        dep[now]=dep[fa]+1;
        for(int t:eg[now])
        {
            if(t==fa) continue;
            ++sum[t];++sum[now];
            dfs(t,now);
        }
        if(dep[now]%2==0) sum[now]=-sum[now];
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            for(int i=1;i<=n;++i)
            {
                sum[i]=0;
                eg[i].clear();
            }
            for(int i=1;i<n;++i)
            {
                int x,y;
                cin>>x>>y;
                eg[x].push_back(y);
                eg[y].push_back(x);
            }
            dfs(1,0);
            for(int i=1;i<=n;++i) cout<<sum[i]<<" \n"[i==n];
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
4 4
zzzz
z.z.
.zzz
zzzz

*/