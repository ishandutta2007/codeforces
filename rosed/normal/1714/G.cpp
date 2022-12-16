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
    const int N=1e6+10,mod=1e9+7,inv2=5e8+4,inf=2e9;
    const double pi=acos(-1.0);
    int n;
    struct node
    {
        int to,x,y;
    };
    vector<node> eg[N];
    int dp[N];
    vector<int> a;
    inline void dfs(int now,int fa,int s1)
    {
        dp[now]=upper_bound(a.begin(),a.end(),s1)-a.begin()-1;
        for(auto tmp:eg[now])
        {
            int t=tmp.to;
            if(t==fa) continue;
            a.emplace_back(a.back()+tmp.y);
            dfs(t,now,s1+tmp.x);
            a.pop_back();
        }
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>n;
            for(int i=1;i<=n;++i)
            {
                dp[i]=0;
                eg[i].clear();
            }
            for(int i=2;i<=n;++i)
            {
                int x,y,z;cin>>x>>y>>z;
                eg[x].emplace_back((node){i,y,z});
                eg[i].emplace_back((node){x,y,z});
            }
            a.emplace_back(0);
            dfs(1,0,0);
            a.clear();
            for(int i=2;i<=n;++i) cout<<dp[i]<<' ';
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
9
1 5 6
4 5 1
2 9 10
4 2 1
1 2 1
2 3 3
6 4 3
8 1 3

*/