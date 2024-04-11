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
    const int N=5e5+10,mod=1e9+7,inf=2e9;
    int n,m,ans;
    char s[N];
    vector<int> eg[N];
    int str[N];
    inline void dfs(int now,int fa)
    {
        str[now]=(s[now]=='B'?1:-1);
        for(int t:eg[now])
        {
            if(t==fa) continue;
            dfs(t,now);
            str[now]+=str[t];
        }
        if(str[now]==0) ++ans;
    }
    inline void init()
    {
        for(int i=1;i<=n;++i)
        {
            eg[i].clear();
            str[i]=0;
        }
        ans=0;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int skx;cin>>skx;
        while(skx--)
        {
            cin>>n;
            for(int i=2;i<=n;++i)
            {
                int x;
                cin>>x;
                eg[x].emplace_back(i);
            }
            cin>>(s+1);
            dfs(1,0);
            cout<<ans<<'\n';
            init();
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
6 4 7

6 6 5 5
3 7 8 5
*/