#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
#define MAXN 20005
int S,T;int n,m,g;int sex[MAXN];int init;
int INF=1000000000;
int tot=1;int head[MAXN],next[MAXN*20],p[MAXN*20],flow[MAXN*20];
int dis[MAXN];int q[MAXN];
void L(int a,int b,int v)
{
	tot++;p[tot]=b;next[tot]=head[a];head[a]=tot;flow[tot]=v;
	tot++;p[tot]=a;next[tot]=head[b];head[b]=tot;flow[tot]=0;
}
int BFS()
{
	memset(dis,-1,sizeof dis);dis[S]=0;q[q[0]=1]=S;
	for(int i=1;i<=q[0];i++)
	{
		int x=q[i];
		for(int u=head[x];u;u=next[u])
		if(dis[p[u]]==-1&&flow[u])
		{
			dis[p[u]]=dis[x]+1;q[++q[0]]=p[u];
		}
	}
	return dis[T];
}
int dinic(int x,int flo)
{
	if(x==T)return flo;
	int ret=0;
	for(int u=head[x];u;u=next[u])
	if(dis[p[u]]==dis[x]+1)
	if(flow[u])
	{
		int res=dinic(p[u],min(flo,flow[u]));
		flo-=res;flow[u]-=res;flow[u^1]+=res;ret+=res;
	}
	if(!ret)dis[x]=-1;
	return ret;
}
int main()
{
	scanf("%d%d%d",&n,&m,&g);S=0;T=n+m+1;
	rep(i,1,n)scanf("%d",&sex[i]);
	rep(i,1,n){
		int v;scanf("%d",&v);
		if(sex[i]){
			L(i,T,v+1);
			L(S,i,1);
		}
		else{
			L(i,T,1);
			L(S,i,v+1);
		}
	}
	init=n;
	rep(i,1,m){
		int qx,money,k;
		scanf("%d%d%d",&qx,&money,&k);
		init+=money;
		if(qx){
			rep(j,1,k){
				int v;scanf("%d",&v);
				L(v,n+i,INF);
			}
			int fri;scanf("%d",&fri);
			if(fri)L(n+i,T,g+money);
			else L(n+i,T,money);
		}
		else{
			rep(j,1,k){
				int v;scanf("%d",&v);
				L(n+i,v,INF);
			}
			int fri;scanf("%d",&fri);
			if(fri)L(S,n+i,g+money);
			else L(S,n+i,money);
		}
	}
	while(BFS()!=-1)
	{
		int p=dinic(S,INF);
		while(p){init-=p;p=dinic(S,INF);}
	}
	printf("%d\n",init);
	return 0;
}