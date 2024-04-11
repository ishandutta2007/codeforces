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
    int n,m,sum;
    int st,ed;
    vector<int> eg[N];
    int c[N],num;
    bool vis[N];
    int dep[N],f[N];
    inline void init()
    {
        num=sum=0;
        for(int i=1;i<=n;++i)
        {
            eg[i].clear();
            vis[i]=0;
            f[i]=dep[i]=0;
        }
    }
    inline void dfs(int now,int fa)
    {
        f[now]=fa;
        dep[now]=dep[fa]+1;
        for(int t:eg[now])
        {
            if(t==fa) continue;
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
            cin>>n>>m;
            init();
            cin>>st>>ed;
            for(int i=1;i<=m;++i)
            {
                int x;cin>>x;
                c[++num]=x;
                //vis[x]=1;
            }
            for(int i=1;i<n;++i)
            {
                int x,y;cin>>x>>y;
                eg[x].emplace_back(y);
                eg[y].emplace_back(x);
            }
            sort(c+1,c+num+1);
            num=unique(c+1,c+num+1)-c-1;
            dfs(st,0);
            vis[st]=1;
            for(int i=1;i<=num;++i)
            {
                int x=c[i];
                while(!vis[x])
                {
                    //cout<<x<<"!!!\n";
                    vis[x]=1;
                    sum+=2;
                    x=f[x];
                }
                //cout<<sum<<"??\n";
            }
            while(!vis[ed])
            {
                ++sum;
                ed=f[ed];
            }
            while(ed!=st)
            {
                --sum;
                ed=f[ed];
            }
            cout<<sum<<'\n';
            //cout<<sum-dep[ed]+1<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
6

3 1
1 3
2
1 3
1 2

6 4
3 5
1 6 2 1
1 3
3 4
3 5
5 6
5 2

6 2
3 2
5 3
1 3
3 4
3 5
5 6
5 2

3 1
1 3
2
1 3
1 2

6 4
3 5
1 6 2 1
1 3
3 4
3 5
5 6
5 2

6 2
3 2
5 3
1 3
3 4
3 5
5 6
5 2

*/