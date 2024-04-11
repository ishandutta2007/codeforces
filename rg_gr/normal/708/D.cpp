//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
#define od(x) printf("%d",x)
#define odb(x) printf("%d ",x)
#define odl(x) printf("%d\n",x)
#define odp(x,y) printf("%d %d\n",x,y)
#define ol(x) puts("")
#define old(x) printf("%lld",x)
#define oldb(x) printf("%lld ",x)
#define oldl(x) printf("%lld\n",x)
#define oldp(x,y) printf("%lld %lld\n",x,y)
#define rg(x) for(int i=1;i<=(x);i++){
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
struct Edge{
	int v,w,nxt,c;
}e[1000005],E[100005];
int h[1000005],cnt=2,H[1005],CNT;
int a[200005],vv;
inline void addedge(int u,int v,int w,int c)
{//	oldb(u),oldb(v),oldp(min(w,1000000007),c);
	e[cnt]=(Edge){v,w,h[u],c};
	h[u]=cnt++;
}
int dis[100005],cur[100005],inq[100005];
inline bool devin(int s,int t)
{
	memset(dis,0x3f,sizeof(dis));
	memcpy(cur,h,sizeof(cur));
	int inf=dis[0];
	std::queue<int>q;
	q.push(s);dis[s]=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		inq[u]=0;
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(e[i].w&&dis[v]>dis[u]+e[i].c)
			{
				dis[v]=dis[u]+e[i].c;
				if(!inq[v])
				{
					inq[v]=1;
					q.push(v);
				}
			}
		}
	}
	return dis[t]!=inf;
}
#define vis inq
int dfs(int u,int t,int flow,int& cost)
{
	if(u==t)return flow;
	vis[u]=1;
	int ans=0;
	for(int& i=cur[u];i&&ans<flow;i=e[i].nxt)
	{
		int v=e[i].v;
		if(!vis[v]&&e[i].w&&dis[v]==dis[u]+e[i].c)
		{
			int fl=dfs(v,t,min(e[i].w,flow-ans),cost);
			if(fl)cost+=fl*e[i].c,e[i].w-=fl,e[i^1].w+=fl,ans+=fl;
		}
	}
	vis[u]=0;
	return ans;
}
const int qwq=(1<<31)-1;
inline void pig(int u,int v,int w,int c)
{
//	oldb(u),oldp(v,w);
	addedge(u,v,w,c);
	addedge(v,u,0,-c);
}
int fl[114514];
int n=read(),m=read(),flow=0,mincost=0,x,s=0,t=n+1,S=1,T=n,lxl=m+4;
inline void add(int u,int v,int l,int r,int c)
{
	pig(u,v,r-l,c);
	fl[u]-=l;
	fl[v]+=l;
	mincost+=c*l;
}
const int inf=0x3f3f3f3f;
inline void rebuild()
{
	rg(n+n)fl[i]>0?pig(s,i,fl[i],0):pig(i,t,-fl[i],0);gr
	pig(T,S,inf,0);
}
signed main()
{
	rg(m)int u=read(),v=read(),f=read(),c=read();
	add(u,v,c,c,0);
	if(c<=f)
	{
		pig(v,u,c,1);
		pig(u,v,f-c,1);
		pig(u,v,inf,2);
	}
	else
	{
		mincost+=c-f;
		pig(u,v,inf,2);
		pig(v,u,c-f,0);
		pig(v,u,f,1);
	}gr
	rebuild();
	while(devin(s,t))while(x=dfs(s,t,0x3f3f3f3f,mincost))flow+=x;
	odl(mincost);
}