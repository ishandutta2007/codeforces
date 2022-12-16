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
    int n,p;
    int a[N];
    typedef pair<int,int> pr;
    vector<pr> eg[N];
    int ans[N],val[N];
    int pre[N];
    int num;
    inline void dfs(int now,int fa)
    {
        for(pr tmp:eg[now])
        {
            int t=tmp.first,id=tmp.second;
            if(t==fa) continue;
            if(pre[now]==n)
            {
                val[id]=num+n;
                ans[t]=num;
                ++num;
            }
            else
            {
                val[id]=num;
                ans[t]=num+n;
                ++num;
            }
            pre[t]=pre[now]^n;
            dfs(t,now);
        }
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>p;
            n=(1<<p);
            num=1;
            for(int i=1;i<=n;++i)
            {
                ans[i]=val[i]=pre[i]=0;
                eg[i].clear();
            }
            for(int i=1;i<n;++i)
            {
                int x,y;
                cin>>x>>y;
                eg[x].emplace_back(pr(y,i));
                eg[y].emplace_back(pr(x,i));
            }
            cout<<1<<'\n';
            ans[1]=pre[1]=n;
            dfs(1,0);
            for(int i=1;i<=n;++i) cout<<ans[i]<<" \n"[i==n];
            for(int i=1;i<n;++i) cout<<val[i]<<" \n"[i==n-1];
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
3
1 2
2 3
3 4
1 5
1 6
5 7
5 8

*/