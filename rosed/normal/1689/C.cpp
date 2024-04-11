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
    int n,ans;
    vector<int> eg[N];
    inline void dfs(int now,int fa,int dep)
    {
        int sum=0;
        for(int t:eg[now])
        {
            if(t==fa) continue;
            ++sum;
        }
        if(sum<2)
        {
           // cout<<now<<' '<<dep<<"!!"<<endl;

            if(sum==0) ans=min(ans,dep*2-1);
            else ans=min(ans,dep*2);
            return;
        }
        for(int t:eg[now])
        {
            if(t==fa) continue;
            dfs(t,now,dep+1);
        }
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int skx;
        cin>>skx;
        while(skx--)
        {
            cin>>n;
            ans=inf;
            for(int i=1;i<=n;++i) eg[i].clear();
            for(int i=1;i<n;++i)
            {
                int x,y;cin>>x>>y;
                eg[x].emplace_back(y);
                eg[y].emplace_back(x);
            }
            dfs(1,0,1);
            cout<<n-ans<<'\n';
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
4 5
2 3
1 5
1 2

*/