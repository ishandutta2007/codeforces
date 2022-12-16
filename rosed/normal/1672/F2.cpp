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
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n;
    int a[N],b[N],cnt[N];
    vector<int> eg[N];
    bool vis[N],insta[N];
    int maxn,flag;
    inline void dfs(int now)
    {
        insta[now]=1;
        vis[now]=1;
        for(int t:eg[now])
        {
            if(insta[t]){flag=1;break;}
            if(!vis[t]) dfs(t);
        }
        insta[now]=0;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            for(int i=1;i<=n+1;++i) cnt[i]=0,vis[i]=0,eg[i].clear();
            flag=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
            }
            for(int i=1;i<=n;++i)
            {
                cin>>b[i];
            }
            for(int i=1;i<=n;++i)
            {
                eg[a[i]].emplace_back(b[i]);
            }
            int maxn=1;
            for(int i=1;i<=n;++i)
            {
                if(eg[i].size()>eg[maxn].size()) maxn=i;
            }
            vis[maxn]=1;
            for(int i=1;i<=n;++i)
            {
                if(!vis[i]) dfs(i);
            }
            if(flag) cout<<"WA\n";
            else cout<<"AC\n";
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
4
1 2 3 3
2 1 3 3
2 3 1 3

1 1 2 2
1 2 2 1

*/