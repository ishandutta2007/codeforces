// Problem: G. Double Tree
// Contest: Codeforces - Educational Codeforces Round 62 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1140/G
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
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
#define newe(n) struct Edge{int v,w0,w1,nxt;}e[2*n+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w0,int w1){e[cnt]=(Edge){v,w0,w1,h[u]};h[u]=cnt++;}
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
newe(1000000);
int fa[1000005][21],dp[21][1000005][2][2];
arr trans,dep,a;
void dfs(int u,int faa)
{
	fa[u][0]=faa;
	dep[u]=dep[faa]+1;
	for(int i=1;(1<<i)<=dep[u];i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	trans[u]=a[u];
	fe(u)if(v!=faa)dfs(v,u),trans[u]=min(trans[u],trans[v]+e[i].w0+e[i].w1);gr
}
void dfs3(int u,int faa,int from)
{
	if(faa)trans[u]=min(trans[u],e[from].w0+e[from].w1+trans[faa]);
	fe(u)if(v!=faa)dfs3(v,u,i);gr
}
void dfs2(int u,int faa,int from)
{
	if(faa)
	{
		dp[0][u][0][0]=min(e[from].w0,trans[u]+trans[faa]+e[from].w1);
		dp[0][u][1][1]=min(e[from].w1,trans[u]+trans[faa]+e[from].w0);
		dp[0][u][0][1]=min(trans[u]+e[from].w1,trans[faa]+e[from].w0);
		dp[0][u][1][0]=min(trans[u]+e[from].w0,trans[faa]+e[from].w1);
	}
	for(int i=1;(1<<i)<=dep[u];i++)
	{
		for(int j=0;j<=1;j++)
			for(int k=0;k<=1;k++)
			{
				dp[i][u][j][k]=0x3f3f3f3f3f3f3f3fll;
				for(int d=0;d<=1;d++)dp[i][u][j][k]=min(dp[i][u][j][k],dp[i-1][u][j][d]+dp[i-1][fa[u][i-1]][d][k]);
			}
	}
	
	fe(u)if(v!=faa)dfs2(v,u,i);gr
}
void S(int *a,int *b)
{
	int c=*a;*a=*b;*b=c;
	a++,b++;
	c=*a;*a=*b;*b=c;
}
int R=1;
signed main()
{
	int n=read();
	rg(n)a[i]=read();gr
	rg(n-1)
	int u=read(),v=read(),w0=read(),w1=read();
	addedge(u,v,w0,w1);
	addedge(v,u,w0,w1);
	gr
	// R=read();
	dfs(R,0);
	dfs3(R,0,0);
	dfs2(R,0,0);
	// rg(n)odl(trans[i]);gr
	int q=read();rg(q)
	int u=read(),v=read(),U=0,V=0;
	if(u&1);else U++;
	if(v&1);else V++;
	u++,v++;
	u>>=1;
	v>>=1;
	int disu[2]={},disv[2]={};
	disu[U]=0;disu[U^1]=trans[u];
	disv[V]=0;disv[V^1]=trans[v];
	if(dep[u]<dep[v])S(disu,disv),u^=v^=u^=v;
	if(dep[u]>dep[v])
	{
		int s=dep[u]-dep[v];
		for(int i=20;i>=0;i--)if((s>>i)&1)
		{
			// printf("%d %d %d %d\n",disu[0],disu[1],disv[0],disv[1]);
			int D[2]={};
			D[0]=min(dp[i][u][0][0]+disu[0],dp[i][u][1][0]+disu[1]);
			D[1]=min(dp[i][u][0][1]+disu[0],dp[i][u][1][1]+disu[1]);
			u=fa[u][i];
			disu[0]=D[0];
			disu[1]=D[1];
			// printf("%d %d %d %d\n",disu[0],disu[1],disv[0],disv[1]);
		}
	}
	if(u==v)
	{
		oldl(min(disu[0]+disv[0],disu[1]+disv[1]));
	}
	else
	{
		for(int i=20;i>=0;i--)if(fa[u][i]!=fa[v][i])
		{
			// printf("%d %d %d %d\n",disu[0],disu[1],disv[0],disv[1]);
			int D[2]={};
			D[0]=min(dp[i][u][0][0]+disu[0],dp[i][u][1][0]+disu[1]);
			D[1]=min(dp[i][u][0][1]+disu[0],dp[i][u][1][1]+disu[1]);
			u=fa[u][i];
			disu[0]=D[0];
			disu[1]=D[1];
			D[0]=min(dp[i][v][0][0]+disv[0],dp[i][v][1][0]+disv[1]);
			D[1]=min(dp[i][v][0][1]+disv[0],dp[i][v][1][1]+disv[1]);
			v=fa[v][i];
			disv[0]=D[0];
			disv[1]=D[1];
			// printf("%d %d %d %d\n",disu[0],disu[1],disv[0],disv[1]);
		}
		int i=0;
		int D[2]={};
		D[0]=min(dp[i][u][0][0]+disu[0],dp[i][u][1][0]+disu[1]);
		D[1]=min(dp[i][u][0][1]+disu[0],dp[i][u][1][1]+disu[1]);
		u=fa[u][i];
		disu[0]=D[0];
		disu[1]=D[1];
		D[0]=min(dp[i][v][0][0]+disv[0],dp[i][v][1][0]+disv[1]);
		D[1]=min(dp[i][v][0][1]+disv[0],dp[i][v][1][1]+disv[1]);
		v=fa[v][i];
		disv[0]=D[0];
		disv[1]=D[1];
		oldl(min(disu[0]+disv[0],disu[1]+disv[1]));
	}
	gr
	return 0;
}