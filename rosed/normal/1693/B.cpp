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
    int n,m,ans;
    vector<int> eg[N];
    struct node
    {
        int l,r;
    }a[N];
    inline int dfs(int now,int fa)
    {
        int tmp=0;
        for(int t:eg[now])
        {
            if(t==fa) continue;
            tmp+=dfs(t,now);
        }
        if(tmp<a[now].l) tmp=a[now].r,++ans;
        if(tmp>a[now].r) tmp=a[now].r;
        return tmp;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int skx;
        cin>>skx;
        while(skx--)
        {
            cin>>n;ans=0;
            for(int i=1;i<=n;++i)
            {
                eg[i].clear();
            }
            for(int i=2;i<=n;++i)
            {
                int x,y;x=i;cin>>y;
                eg[x].emplace_back(y);
                eg[y].emplace_back(x);
            }
            for(int i=1;i<=n;++i)
            {
                cin>>a[i].l>>a[i].r;
            }
            dfs(1,0);
            cout<<ans<<'\n';
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
5
1 2 3 4
5 5
4 4
2 2
1 2
1 1


*/