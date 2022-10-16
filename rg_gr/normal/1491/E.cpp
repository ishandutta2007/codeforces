// Problem: E. Fib-tree
// Contest: Codeforces - Codeforces Global Round 13
// URL: https://codeforces.com/problemset/problem/1491/E
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
// #define DEBUG
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
newe(200005);
arr fib,ifib,sz,faa,t,tag,g;
#undef fe
#define fe(x) for(auto v:G[x]){
std::set<int>G[200005];
void a1ddedge(int u,int v,int w)
{
	G[u].insert(v);
	G[v].insert(u);
}
int cc,Cc,n;
void dfs(int u,int fa)
{
	g[u]=0;
	t[++Cc]=u;
	sz[u]=1;
	fe(u)
	if(v==fa)continue;
	dfs(v,u);sz[u]+=sz[v];faa[v]=u;
	g[u]=max(g[u],sz[v]);
	gr
}
void dfs2(int u,int fa)
{
	fe(u)
	if(v==fa)continue;
	dfs2(v,u);
	gr
	tag[u]=cc;
}
void rmv(int u,int v)
{
	G[u].erase(v);
	G[v].erase(u);
}
void solve(int x,int d)
{
	// printf("(%d %d)\n",x,d);
	// odp(x,d);
	if(d==-1)
	{
		puts("NO");
		exit(0);
	}
	if(d<=1)return;
	// if(d==0)
	// {
		// puts("NO");
		// exit(0);
	// }
	Cc=0;
	dfs(x,x);
	int root;
	rg(Cc)
	int u=t[i];
	g[u]=max(g[u],Cc-sz[u]);
	if(g[u]*2<=Cc)root=u;
	gr
	Cc=0;
	dfs(root,root);
	// printf(": ");odp(root,d);
	// rg(Cc)odb(t[i]);gr puts("");
	// rg(Cc)odb(faa[i]);gr puts("");
	rg(Cc)
	if(sz[t[i]]==fib[d-2])
	{
		rmv(t[i],faa[t[i]]);
		int tt=faa[t[i]];
		solve(t[i],d-2);
		solve(tt,d-1);
		return;
	}
	// if(sz[t[i]]==fib[d-1])
	// {
		// rmv(t[i],faa[t[i]]);
		// solve(t[i],d-1);
		// solve(faa[t[i]],d-2);
		// return;
	// }
	gr
	puts("NO");
	// if(n==fib[25])printf("no on %d %d.\n",x,d);
	exit(0);
}
signed main()
{
	n=read();rg(n-1)int u=read(),v=read();a1ddedge(u,v,1),a1ddedge(v,u,1);gr
	fib[0]=fib[1]=1;
	memset(ifib,-1,sizeof(ifib));
	rg(26)if(i>1)fib[i]=fib[i-1]+fib[i-2];gr
	rg(26)ifib[fib[i]]=i;gr
	// odl(fib[25]);
	// tag[1]=cc=1;
	solve(1,ifib[n]);
	puts("YES");
	return 0;
}