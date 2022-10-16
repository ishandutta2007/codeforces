// Problem: E. Off by One
// Contest: Codeforces - Educational Codeforces Round 108 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1519/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
#include <map>
#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[2*n+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}//if(u<=v)printf("%d %d %d\n",u,v,w);}
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
struct frac{
	int x,y;
	bool operator<(const frac& b)const{
		return (__int128)x*b.y<(__int128)y*b.x;
	}
};
// typedef int arr[1000050];
newe(1000005);
std::map<frac,int>mp;
int cc;
int id(frac x)
{
	if(mp.count(x))return mp[x];
	return mp[x]=++cc;
}
arr vis,dep,ff;
void dfs(int u,int fa=0)
{
	vis[u]=1;dep[u]=dep[fa]+1;
	fe(u)if(!vis[v])dfs(v,u),ff[v]=e[i].w;gr
}
arr ax,ay;int dd;
void join(int x,int y)
{
	dd++;
	ax[dd]=x;
	ay[dd]=y;
}
int djwj(int u,int fa=0)
{
	// odl(u);
	int pre=0;
	fe(u)
	// if(dep[u]==dep[v])odp(u,v);
	// assert(dep[v]!=dep[u]);
	if(ff[v]!=e[i].w)continue;
	int s=djwj(v,e[i].w);
	if(!s)continue;
	if(pre)
	{
		join(pre,e[i].w);
		pre=0;
	}
	else pre=e[i].w;
	gr
	fe(u)
	// if(dep[u]==dep[v])odp(u,v);
	// assert(dep[v]!=dep[u]);
	if(dep[v]<=dep[u]||ff[v]==e[i].w)continue;
	// int s=djwj(v,e[i].w);
	// if(!s)continue;
	if(pre)
	{
		join(pre,e[i].w);
		pre=0;
	}
	else pre=e[i].w;
	gr
	if(pre==0)return 1;
	if(fa==0)return 0;
	join(fa,pre);
	return 0;
}
void solve(int x)
{
	dfs(x);
	// rg(cc)odl(dep[i]);gr
	djwj(x);
	// puts("");
}
signed main()
{
	int n=read();
	rg(n)int a=read(),b=read(),c=read(),d=read();
	int A=id((frac){(a+b)*d,b*c});
	int B=id((frac){a*d,(c+d)*b});
	addedge(A,B,i);
	addedge(B,A,i);
	gr
	// return 0;
	rg(cc)
	if(!vis[i])solve(i);
	gr
	odl(dd);
	rg(dd)oldp(ax[i],ay[i]);gr
	return 0;
}