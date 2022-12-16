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
    const int N=1000+10,mod=1e9+7,inf=2e9;
    int n,m,st,ed;
    vector<int> eg[N];
    bool g[N][N];
    queue<int> q;
    inline void spfa(int now,vector<int> &dis)
    {
        dis[now]=0;
        q.push(now);
        while(!q.empty())
        {   
            int now=q.front();
            q.pop();
            for(int t:eg[now])
            {
                if(dis[t]>n)
                {
                    dis[t]=dis[now]+1;
                    q.push(t);
                }
            }
        }
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m>>st>>ed;
        for(int i=1;i<=m;++i)
        {
            int x,y;cin>>x>>y;
            eg[x].emplace_back(y);
            eg[y].emplace_back(x);
            g[x][y]=g[y][x]=1;
        }
        vector<int> dis1(n+1,inf),dis2(n+1,inf);
        spfa(st,dis1);
        spfa(ed,dis2);
        int len=dis1[ed];
        int sum=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=i+1;j<=n;++j)
            {
                if(g[i][j]) continue;
                if(dis1[i]+dis2[j]+1>=len&&dis1[j]+dis2[i]+1>=len) ++sum;
            }
        }
        cout<<sum<<'\n';
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