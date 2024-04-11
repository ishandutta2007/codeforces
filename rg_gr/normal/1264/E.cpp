// Problem: E. Beautiful League
// Contest: Codeforces - Codeforces Round #604 (Div. 1)
// URL: https://codeforces.com/contest/1264/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//  - /

/*
+
++
+++
++++
+++++
++++++
+++++++
++++++++
+++++++++
++++++++++
+++++++++++
++++++++++++
+++++++++++++
++++++++++++++
+++++++++++++++
++++++++++++++++
+++++++++++++++++
++++++++++++++++++
+ +++++++++++++++++
+  ++++++++++++++ ++
+   +++++++++++++  ++
+    ++++++++++++   ++
+     +++++++++++    ++
+      ++++++++++     ++
+       +++++++++      ++
+        ++++++++       ++
+         +++++++++++++++++
+          +++++++++++++++++
+           ++++++++++++++
+            +++++++++++
+             ++++++++
+              +++++
+               ++
+               +
+               +
+              ++
+             +++
+            ++++
+           +++++
+           +++++
+           +++++
+           +++++
+     +     +++++
+    +++    +++++
+   ++ ++   +++++
+  ++   ++  +++++
+ ++  +  ++ +++++
+++  +++  +++++++
++  ++ ++  ++++++
 
 
 ++++++++      +++++++++++     +++      +++        ++++++++        ++++++++
+++++++++     +++++++++++++    +++      +++       +++    +++      +++    +++
+++          +++   +++   +++   +++      +++      +++   ++++++    +++      +++
+++          +++   +++   +++   +++      +++      +++ +++  +++           +++
+++          +++   +++   +++   +++ ++   +++ ++   ++++++   +++         +++
+++++++++    +++   +++   +++   +++ ++   +++ ++    +++    +++        +++    ++
 ++++++++    +++   +++   +++   +++++    +++++      ++++++++       +++++++++++
*/
#ifndef ONLINE_JUDGE
#define DEBUG
#endif
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <assert.h>
#include <set>
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
#define rg_(i,x) for(int i=1;i<=(x);i++){
#define fe(u) for(int i=h[u];i;i=e[i].nxt){int v=e[i].v;
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
template<typename T>
void print(T x){}
template<>
void print<int>(int x){od(x);}
template<>
void print<const int>(const int x){od(x);}
template<>
void print<long long>(long long x){old(x);}
template<>
void print<const long long>(const long long x){old(x);}
template<>
void print<char>(char x){putchar(x);}
template<>
void print<const char>(const char x){putchar(x);}
template<>
void print<double>(double x){printf("%.12lf",x);}
template<typename T,typename... qwq>
void print(T x,qwq ...args)
{
	print(x);
	print(args...);
}
#ifdef DEBUG
template<typename T>
void debug(T x){}
template<>
void debug<int>(int x){od(x);}
template<>
void debug<const int>(const int x){od(x);}
template<>
void debug<long long>(long long x){old(x);}
template<>
void debug<const long long>(const long long x){old(x);}
template<>
void debug<char>(char x){putchar(x);}
template<>
void debug<const char>(const char x){putchar(x);}
template<>
void debug<double>(double x){printf("%.12lf",x);}
template<typename T,typename... qwq>
void debug(T x,qwq ...args)
{
	debug(x);
	debug(args...);
}
#define dflush fflush
#else
#define dflush(...) 0
template<typename T,typename... qwq>
void debug(T x,qwq ...args)
{
	
}
#endif
//#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[2*n+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}
#define mgs int fa[1<<22],sz[1<<22];\
inline int f(int x){return x==fa[x]?x:fa[x]=f(fa[x]);}\
inline int uf(int x,int y)\
{\
    int fx=f(x),fy=f(y);\
    if(fx==fy)return 0;\
    if(sz[fx]>sz[fy])fx^=fy^=fx^=fy;\
    fa[fx]=fy,sz[fy]+=sz[fx];\
    return 1;\
}
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=num*10+(c^48),c=getchar();
    return num*f;
}
inline int re1d()
{
    char c=getchar();
    while(c<48||c>49)c=getchar();
    return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
struct Edge{
	int v,w,nxt,c;
}e[200005];
int h[200005],cnt=2;
inline void addedge(int u,int v,int w,int c)
{
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
int G[55][55],ans[55][55],ed[55][55];
void zky(int u,int v,int w,int c)
{
	// printf("%d %d (%d,%d)\n",u,v,w,c);
	addedge(u,v,w,c);
	addedge(v,u,0,-c);
}
signed main()
{
	int n=read(),m=read(),s=0,t=n*n+1,flow=0,mincost=0,x,cc=n;
	while(m--)
	{
		int u=read(),v=read();
		G[u][v]=1;
		ans[u][v]=1;
		G[v][u]=-1;
	}
	rg(n)rg_(j,n)zky(i,t,1,2*j-1);gr gr
	rg(n)rg_(j,i-1)
	++cc;zky(s,cc,1,0);
	// if(!G[i][j])ed[i][j]=cnt-2,ed[j][i]=cnt-1;
	if(G[i][j]!=-1)zky(cc,i,1,0),ed[i][j]=cnt-1;
	if(G[j][i]!=-1)zky(cc,j,1,0),ed[j][i]=cnt-1;
	gr gr
	int qwq=n*(n-1)*(n-2)/3+n*(n-1)/2;
	// odl(qwq);
	while(devin(s,t))while(x=dfs(s,t,0x3f3f3f3f,mincost))flow+=x;
	// printf("%d %d\n",flow,mincost);
	qwq=qwq-mincost;qwq=qwq/2*3;
	e[0].w=1;
	// odl(qwq);
	#define u i
	#define v j
	rg(n)rg_(j,n)od(i==j?0:(G[u][v]?ans[u][v]:e[ed[i][j]].w));gr puts("");gr
}