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
    const int N=2e5+10,mod=1e9+7,inv2=5e8+4,inf=2e9;
    const double pi=acos(-1.0);
    int n,m;
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
    bool ok[110][110];
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
        if(maxflow!=n) mincost=-1;
        cout<<mincost<<'\n';
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m;
        st=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                link(st,i,1,j*j-(j-1)*(j-1));
            }
        }
        for(int i=1;i<=m;++i)
        {
            int opt,l,r,v;cin>>opt>>l>>r>>v;
            for(int p=l;p<=r;++p)
            {
                int tl,tr;
                if(opt==2) tl=v+1,tr=n;
                else tl=1,tr=v-1;
                for(int k=tl;k<=tr;++k) ok[p][k]=1;
            }
        }
        ed=n+n+1;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j) if(!ok[i][j])
            {
                //cout<<j<<' '<<i+n<<"!!"<<endl;
                link(j,i+n,1,0);
            }
            link(i+n,ed,1,0);
        }
        
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