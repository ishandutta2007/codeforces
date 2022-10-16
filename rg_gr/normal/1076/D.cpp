#include <queue>
#include <stdio.h>
#include <string.h> 
#include <math.h>
#include <algorithm>
#define int long long
inline int read()
{
	int num=0;char c=getchar();
	while(c<48||c>57){c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num;
}
#define inr long long
#define in long long
#define viud void
struct Egde{
    int v,w,nxt;
    bool operator<(const Egde &b)const
    {
        return w>b.w;
    }
}e[1000005];
int cnt=2;
int h[300005];
void addedge(int u,int v,inr w)
{
    e[cnt]=(Egde){v,w,h[u]};
    h[u]=cnt++;
}
int dis[300005],vis[300005],pre[300005];
namespace poly{
    struct Egde{
        int v,w,nxt;
        bool operator<(const Egde &b)const
        {
            return w>b.w;
        }
    }e[1000005];
    int cnt=1;
    int h[300005];
    void FFT(int u,int v,inr w)
    {
        e[cnt]=(Egde){v,w,h[u]};
        h[u]=cnt++;
        //printf("%lld -->> %lld\n",u,v);
    }
    int f[3000005];
    void polyexp(int n)
    {
        for(int i=2;i<=n;i++)
        {
            if(f[i])printf("%lld ",pre[i]>>1);
        }
    }
    void NTT(int u,int fa,int &k,int n)
    {
        //printf("%lld %lld\n",u,k);
        f[u]=1;
        k--;
        if(k==0)
        {
            polyexp(n);
            //puts("devin");
            exit(0);
        }
        for(int i=h[u];i;i=e[i].nxt)
        {
            int v=e[i].v;
            //printf("%lld -> %lld\n",u,v);
            if(v!=fa)NTT(v,u,k,n);
        }
    }
};
#define Edge Egde
std::priority_queue<Edge> q;
#define s u
void dij(int u,int k)
{
    Edge x=(Edge){u,0,114514};
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    q.push(x);
    int cnt=0;
    while(!q.empty())
    {
        x=q.top();q.pop();
        int u=x.v,d=x.w;
        if(vis[u])continue;
        vis[u]=1;
        cnt++;
        if(u!=1)printf("%lld ",pre[u]>>1);
        if(cnt==k)exit(0);
        for(int i=h[u];i;i=e[i].nxt)
        {
            in v=e[i].v;
            if(vis[v])continue;
            //dis[v]=dis[v]<dis[u]+e[i].w?dis[v]:dis[u]+e[i].w;
            if(dis[v]>=dis[u]+e[i].w)
            {
                pre[v]=i;
                dis[v]=dis[u]+e[i].w;
                q.push((Edge){v,dis[v],1919810});
            }
        }
    }
    
}
signed main()
{
    int n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++)
    {
        int x=read(),y=read(),w=read();
        addedge(x,y,w);
        addedge(y,x,w);
    }
    if(k>=n)k=n-1;
    printf("%lld\n",k);
    dij(1,k+1);
    /*for(int i=2;i<=n;i++)
    {
        poly::FFT(e[pre[i]^1].v,i,e[pre[i]^1].w);
    }
    k++;
    poly::NTT(1,0,k,n);*/
    //std::sort(pre+1,pre+1+n);
    //int ans=0;
    //for(int i=1;i<=n;i++)if(pre[i])//printf("%lld ",pre[i]);
    //    ans+=e[pre[i]].w;
    //printf("%lld\n",ans);
    //for(int i=1;i<=n;i++)printf("%lld ",dis[i]);
    //for(int i=1;i<=n;i++)if(pre[i])printf("%lld ",pre[i]>>1);
}