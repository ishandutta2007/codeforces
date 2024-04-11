#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define N 103
using namespace std;
int n,m,deg[N],S,T,ans,q[N],h,t,dis[N],pre[N],
to[N<<3],hd[N<<3],f[N<<3],c[N<<3],lk[N],cnt=1;
bool inq[N];
inline void add(int u,int v,int F,int C)
{
    F?to[++cnt]=v,hd[cnt]=lk[u],f[cnt]=F,c[cnt]=C,lk[u]=cnt,
    to[++cnt]=u,hd[cnt]=lk[v],c[cnt]=-C,lk[v]=cnt:0;
}
inline bool spfa()
{
    for(int i=1;i<=T;i++)
    inq[i]=pre[i]=0,dis[i]=inf;
    dis[S]=h=0,q[0]=S,t=1;
    int x;
    while(h^t)
    {
        inq[x=q[h++]]=0;h=h==N?0:h;
        for(int s,i=lk[x];i;i=hd[i])
        if(f[i]&&dis[s=to[i]]>dis[x]+c[i])
        {
            dis[s]=dis[x]+c[i],pre[s]=i;
            if(!inq[s])
            inq[q[t++]=s]=1,t=t==N?0:t;
        }
    }
    return dis[T]<inf;
}
int u,v,F,C;
int main()
{
    scanf("%d%d",&n,&m);S=n+1,T=n+2;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d%d",&u,&v,&C,&F);
        if(C<F)ans+=F-C,swap(C,F),add(u,v,C-F,0);
        else add(u,v,C-F,1);
        add(v,u,F,1),add(u,v,inf,2);
        deg[u]+=F,deg[v]-=F;
    }
    add(n,1,inf,0);
    for(int i=2;i<n;i++)
    if(deg[i]>0)add(i,T,deg[i],0);
    else add(S,i,-deg[i],0);
    if(deg[1]>-deg[n])add(1,T,deg[1]+deg[n],0);
    else add(S,n,-deg[n]-deg[1],0);
    while(spfa())
    {
        F=inf;
        for(int i=pre[T];i;i=pre[to[i^1]])
        F=F<f[i]?F:f[i];
        ans+=dis[T]*F;
        for(int i=pre[T];i;i=pre[to[i^1]])
        f[i]-=F,f[i^1]+=F;
    }
    printf("%d",ans);
}