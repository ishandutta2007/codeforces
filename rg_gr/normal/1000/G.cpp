// Problem: G. Two-Paths
// Contest: Codeforces - Educational Codeforces Round 46 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1000/problem/G
// Memory Limit: 256 MB
// Time Limit: 3500 ms
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
#define int long long
#ifdef int 
#define inf 0x3f3f3f3f3f3f3f3fll
#else 
#define inf 0x3f3f3f3f
#endif
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
newe(333333);
arr a,dep;
int fa[333333][20],W[333333][20],tmp[333333][20];
arr f,g,fr;
void dfs1(int u,int fa)
{
	f[u]=a[u];
	fe(u)if(v==fa)continue;
	dfs1(v,u);
	f[u]+=max(0,f[v]-2*e[i].w);
	fr[u]=i;
	gr
}
void dfs2(int u,int fa,int from=0)
{
	if(fa)g[u]=max(0,g[fa]-f[u]-e[from].w+W[u][0]);
	fe(u)if(v!=fa)dfs2(v,u,i);gr
}
void dfs(int u,int faa)
{
	fa[u][0]=faa;
	dep[u]=dep[faa]+1;
	// tmp[u][0]=u;
	int q;
	for(int i=1;(1<<i)<=dep[u];i++)fa[u][i]=fa[fa[u][i-1]][i-1],
	// tmp[u][i]=fa[tmp[u][i-1]][i-1],
	// q=tmp[u][i-1],
	q=fa[u][i-1],
	// W[u][i]=W[u][i-1]+W[fa[u][i-1]][i-1]-max(0,f[q]-2*e[fr[q]].w);
	W[u][i]=W[u][i-1]+W[fa[u][i-1]][i-1]-f[q];
	fe(u)if(v!=faa)
	{
		W[v][0]=f[v]+f[u]-e[i].w-max(f[v]-2*e[i].w,0);
		dfs(v,u);
	}gr
}
signed main()
{
	int n=read(),q=read();
	rg(n)a[i]=read();gr
	rg(n-1)
	int u=read(),v=read(),w=read();
	addedge(u,v,w);addedge(v,u,w);
	gr
	dfs1(1,0);
	dfs(1,0);
	dfs2(1,0);
	// rg_(u,n)odb(f[u]),odp(g[u],W[u][0]);gr
	rg(q)
	int u=read(),v=read();
	if(dep[v]>dep[u])u^=v^=u^=v;
	int x=u,y=v;
	int s=dep[u]-dep[v];
	int ans=0;
	for(int i=0;i<20;i++)
	{
		if((s>>i)&1)
		{
			ans+=W[u][i]-f[u];
			u=fa[u][i];
		}
	}
	if(u!=v)
	{
		for(int i=19;i>=0;i--)
		{
			if(fa[u][i]!=fa[v][i])
			{
				ans+=W[u][i]-f[u];
				ans+=W[v][i]-f[v];
				u=fa[u][i];
				v=fa[v][i];
			}
		}
		for(int i=0;i>=0;i--)
		{
			if(1)
			{
				ans+=W[u][i]-f[u];
				ans+=W[v][i]-f[v];
				u=fa[u][i];
				v=fa[v][i];
			}
		}
		oldl(ans+g[u]+f[x]+f[y]-f[u]);
	}
	else
	{
		oldl(ans+g[u]+f[x]);
	}
	// ans+=g[u];
	// oldl(ans+f[u]);
	gr
	return 0;
}