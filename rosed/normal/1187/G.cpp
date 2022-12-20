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
    const int N=2e6+10,mod=1e9+7,inv2=5e8+4,inf=2e9;
    const double pi=acos(-1.0);
    int n,m,k,cc,d;
    int st,ed;
    struct edge
    {
        int nxt,to,val,f;
        edge(){}
        edge(const int &nxt,const int &to,const int &f,const int &val):nxt(nxt),to(to),f(f),val(val){}
    }a[N<<1];
    int head[N],cnt=1;
    inline void link(int x,int y,int f,int z)
    {
        a[++cnt]=(edge){head[x],y,f,z};head[x]=cnt;
        a[++cnt]=(edge){head[y],x,0,-z};head[y]=cnt;
    }
    int dis[N],c[N],pre[N],eg[N];
    bool vis[N];
    queue<int> q;
    inline bool spfa()
    {
        memset(dis,0x3f,sizeof(dis));dis[st]=0;
        memset(c,0x3f,sizeof(c));
        memset(vis,0,sizeof(vis));
        q.push(st);pre[ed]=-1;
        while(!q.empty())
        {
            int now=q.front();q.pop();
            vis[now]=0;
            for(int i=head[now];i;i=a[i].nxt)
            {
                int t=a[i].to;
                if(a[i].f&&dis[t]>dis[now]+a[i].val)
                {
                    dis[t]=dis[now]+a[i].val;
                    c[t]=min(c[now],a[i].f);
                    pre[t]=now;
                    eg[t]=i;
                    if(!vis[t])
                    {
                        vis[t]=1;
                        q.push(t);
                    }
                }
            }
        }
        return ~pre[ed];
    }
    inline void dinic()
    {
        int maxflow=0,mincost=0;
        while(spfa())
        {
            maxflow+=c[ed];
            mincost+=c[ed]*dis[ed];
            int now=ed;
            while(now!=st)
            {
                a[eg[now]].f-=c[ed];
                a[eg[now]^1].f+=c[ed];
                now=pre[now];
            }
        }
        cout<<mincost<<'\n';
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m>>k>>cc>>d;
        st=0;
        for(int i=1;i<=k;++i)
        {
            int x;cin>>x;
            link(st,x,1,0);
        }
        for(int i=1;i<=m;++i)
        {
            int x,y;cin>>x>>y;
            for(int j=1;j<=n+k;++j)
            {
                for(int t=1;t<=k;++t)
                {
                    link(x+(j-1)*n,y+j*n,1,d*(t*2-1)+cc);
                    link(y+(j-1)*n,x+j*n,1,d*(t*2-1)+cc);
                }
            }
        }
        for(int t=1;t<n+k;++t)
        {
            for(int i=2;i<=n;++i)
            {
                link(i+(t-1)*n,i+t*n,inf,cc);
            }
            link(1+(t-1)*n,1+t*n,inf,0);
        }
        ed=1+(n+k-1)*n;
        dinic();
    }
}
signed main()
{
    red::main();
    return 0;
}
/*

*/