// Problem: F. The Chocolate Spree
// Contest: Codeforces - Manthan, Codefest 16
// URL: https://codeforces.com/problemset/problem/633/F
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
#define int long long
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
int ans;
newe(100005);
arr A,B,AB,a;
struct qwq{
	int v=0,i=0;
	void reset(int a,int b){v=a,i=b;}
}ta[100005],tb[100005],tab[100005];
// arr ta,tb,tab;
void dfs(int u,int fa)
{
	int BB=0;
	int cc=0;
	fe(u)if(v==fa)continue;
	dfs(v,u);gr
	// odp(u,v);
	rg(12)ta[i].reset(0,i),tb[i].reset(0,i),tab[i].reset(0,i);gr
	fe(u)if(v==fa)continue;
	++cc;
	// odl(cc);
	// odp(v,a[v]);
	ta[cc].v=A[v];
	tb[cc].v=B[v];
	tab[cc].v=AB[v];
	ta[cc].i=cc;
	tb[cc].i=cc;
	tab[cc].i=cc;
	
	// rg(cc)odb(ta[i].v);gr puts("");
	// printf("%d:\n",A[v]);
	gr
	// rg(cc)odb(ta[i].v);gr puts("");
	std::sort(ta+1,ta+1+cc,[&](qwq x,qwq y){return x.v>y.v;});
	std::sort(tb+1,tb+1+cc,[&](qwq x,qwq y){return x.v>y.v;});
	std::sort(tab+1,tab+1+cc,[&](qwq x,qwq y){return x.v>y.v;});
	// rg(cc)odb(ta[i].v);gr puts("");
	A[u]=ta[1].v+a[u];
	B[u]=max(tb[1].v,ta[1].v+ta[2].v+a[u]);
	// odp(u,ta[3].v);
	// AB[u]=max(tab[1].v+a[u],ta[1].v+ta[2].v+ta[3].v+a[u]);
	ans=max(ans,ta[1].v+ta[2].v+ta[3].v+a[u]);
	AB[u]=tab[1].v+a[u];
	rg(10)rg_(j,10)if(tb[i].i!=ta[j].i)AB[u]=max(AB[u],a[u]+tb[i].v+ta[j].v);gr gr
	ans=max(ans,tb[1].v+tb[2].v);
	rg(10)rg_(j,10)if(ta[i].i!=tab[j].i)ans=max(ans,ta[i].v+tab[j].v+a[u]);gr gr
	AB[u]=max(AB[u],max(A[u],B[u]));
	ans=max(ans,AB[u]);
	rg(5)rg_(j,5)rg_(k,5)if(ta[i].i!=tb[j].i&&tb[j].i!=ta[k].i&&ta[i].i!=ta[k].i)ans=max(ans,a[u]+ta[i].v+tb[j].v+ta[k].v);gr gr gr
	// printf("%d : %d %d %d (%d)\n",u,A[u],B[u],AB[u],ans);
}
signed main()
{
	int n=read();
	rg(n)a[i]=read();gr
	rg(n-1)int u=read(),v=read();addedge(u,v,1),addedge(v,u,1);
	// printf("%d(%d) %d(%d)\n",u,a[u],v,a[v]);
	gr
	dfs(1,1);
	oldl(ans);
	return 0;
}