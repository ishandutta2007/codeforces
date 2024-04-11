#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1010
int n,m,px[N],py[N],pz[N],p[N*2],L;
#define N2 2010
#define M2 2010*10
int he[N2],ne[M2],ad[M2],di[M2],wi[M2];
void addE(int x,int y,int z,int w)
{
    static int t=1;
    ++t,ne[t]=he[x],he[x]=t,ad[t]=y,di[t]=z,wi[t]=w,
    ++t,ne[t]=he[y],he[y]=t,ad[t]=x,di[t]=0,wi[t]=-w;
}
#define INF 1000000007
int q[N2*N2],pr[N2],ed[N2],d[N2];bool v[N2];
bool spfa(int s,int t,int c)
{
    memset(v,0,sizeof v);
    for(int i=1;i<=c;i++)d[i]=INF;
    int l=1,r=1;q[1]=s,v[s]=1,d[s]=0;
    while(l<=r)
    {
        int x=q[l++];v[x]=0;
        for(int p=he[x];p;p=ne[p])if(di[p])
            if(d[x]+wi[p]<d[ad[p]])
            {
                d[ad[p]]=d[x]+wi[p],pr[ad[p]]=x,ed[ad[p]]=p;
                if(!v[ad[p]])v[ad[p]]=1,q[++r]=ad[p];
            }
    }
    return d[t]<0;
}
int ff(int s,int t,int c)
{
    int S=0;
    while(spfa(s,t,c))
    {
        int nf=INF;
        for(int i=t;i!=s;i=pr[i])nf=min(nf,di[ed[i]]);
        S+=nf*d[t];
        for(int i=t;i!=s;i=pr[i])di[ed[i]]-=nf,di[ed[i]^1]+=nf;
    }
    return S;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d%d%d",px+i,py+i,pz+i),py[i]=py[i]+px[i];
    for(int i=1;i<=n;i++)p[L++]=px[i],p[L++]=py[i];
    sort(p,p+L),L=unique(p,p+L)-p;
    for(int i=1;i<=n;i++)
    {
        int u=lower_bound(p,p+L,px[i])-p,v=lower_bound(p,p+L,py[i])-p;
        addE(u+1,v+1,1,-pz[i]);
    }
    for(int i=1;i<L;i++)addE(i,i+1,m,0);
    int le=L+1,ri=L;
    addE(le,1,m,0);
    ff(le,ri,ri);
    for(int i=1;i<=n;i++)printf("%d%c",1-di[i*2],i==n?'\n':' ');
}