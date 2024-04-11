//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
#include <math.h>
#include <stdlib.h>
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
#define rj(x) for(int j=i+1;j<=(x);j++){
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
#define int long long
int C=0;
inline int read()
{
//	if(C++)return rand()%2001-1000;
//	return 200;
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
#define db long long
struct Edge{
	int v,w,nxt;
	db c;
}e[200005];
int h[200005],cnt=2;
inline void addedge(int u,int v,int w,db c)
{
	e[cnt]=(Edge){v,w,h[u],c};
	h[u]=cnt++;
}
db dis[100005];
int cur[100005],inq[100005];
inline bool devin(int s,int t)
{
	memset(dis,0x3f,sizeof(int)*802);
	memcpy(cur,h,sizeof(int)*802);
	db inf=dis[1];
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
int dfs(int u,int t,int flow,db& cost)
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
const int qwq=(unsigned)(1<<31)-1;
inline void pig(int u,int v,int w,db c)
{
//	printf("%d %d %d %.7lf\n",u,v,w,c);
	addedge(u,v,w,c);
	addedge(v,u,0,-c);
}
int fl[114514];
struct p{int x,y;bool operator<(const p&b)const{return y<b.y;}
db operator()(p q){return (int)10000000*sqrt((x-q.x)*(x-q.x)+(y-q.y)*(y-q.y));}}a[405];
#define p a
signed main()
{
	int n=read(),flow=0,x,s=0,t=n*2+1;
	db mincost=0;
	rg(n)a[i].x=read(),a[i].y=-read();gr
	std::sort(a+1,a+1+n);//return 0;
	rg(n)pig(s,i,2,0),pig(i+n,t,1,0);gr
	rg(n)rj(n)if(p[i].y<p[j].y)pig(i,j+n,1,p[i](p[j]));gr gr
	while(devin(s,t))while(x=dfs(s,t,0x3f3f3f3f3f3f3f3fll,mincost))flow+=x;
	flow==n-1?printf("%.7lf\n",mincost/10000000.0):puts("-1");
}