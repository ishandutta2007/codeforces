#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define inf 0x7f7f7f7f
using namespace std;

int son[500000],next[500000],ed[500000],flow[500000];
int d[50000],a[10005],v[10005],k1,k2,k3,k4;
bool s[50000];
int n,m,g,i,j,k,tot,S,T;
int ans;

inline void add(int u,int v,int f)
{
	next[++tot]=son[u];son[u]=tot;ed[tot]=v;flow[tot]=f;
	next[++tot]=son[v];son[v]=tot;ed[tot]=u;flow[tot]=0;
}

int find(int now,int Flow)
{
	if (now==T)	return Flow;
	int tmp,w=0,w0,i;
	for(i=son[now];i&&w<Flow;i=next[i])
	if((flow[i])&&(d[now]+1==d[ed[i]])&&(w0=min(Flow-w,flow[i]))&&(tmp=find(ed[i],w0)))
	flow[i]-=tmp,flow[i^1]+=tmp,w+=tmp;
	if(!w)d[now]=inf;
	return w;
}

inline void dinic(int S,int T)
{
	int queue[50000],t1,t2,tmp,i;
	while(true)
	{
		memset(s,true,sizeof(s));
		queue[1]=S;t1=0;t2=1;s[S]^=1;
		while(t1<t2&&s[T])
		for(i=son[queue[++t1]];i;i=next[i])
		if(flow[i]&&s[ed[i]])
		queue[++t2]=tmp=ed[i],d[tmp]=d[queue[t1]]+1,s[tmp]^=1;
		if(s[T])break;
		while(true)if(tmp=find(S,inf))ans-=tmp;else break;
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&g);
    S=0;T=n+m+1;tot=1;
    for(i=1;i<=n;++i)scanf("%d",&a[i]);
    for(i=1;i<=n;++i)scanf("%d",&v[i]);
    for(i=1;i<=n;++i)
    if(a[i])add(S,i,v[i]);
    else add(i,T,v[i]);
    for(;m;--m)
    {
		scanf("%d%d%d",&k1,&k2,&k3);
		for(;k3;--k3)
		{
			scanf("%d",&k4);
			if(!k1)add(k4,n+m,inf);
			else add(n+m,k4,inf);
		}
		scanf("%d",&k4);
		if(!k1)add(n+m,T,k2+k4*g);
		else add(S,n+m,k2+k4*g);
		ans+=k2;
	}
	dinic(S,T);
	printf("%d\n",ans);
	return 0;
}