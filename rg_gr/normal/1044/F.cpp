// Problem: F. DFS
// Contest: Codeforces - Lyft Level 5 Challenge 2018 - Final Round
// URL: https://codeforces.com/problemset/problem/1044/F
// Memory Limit: 512 MB
// Time Limit: 6000 ms
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
newe(1000000)
arr minn,tag,cc;
void build(int o,int l,int r)
{
    if(l==r)
    {
        minn[o]=tag[o]=0;
        cc[o]=1;
        return;
    }
    int m=l+r>>1;
    build(o<<1,l,m);
    build(o<<1|1,m+1,r);
    minn[o]=tag[o]=0;
    cc[o]=cc[o<<1]+cc[o<<1|1];
}
void pushdown(int o,int l,int r)
{
    if(l==r)
    {
        minn[o]+=tag[o];
        tag[o]=0;
        cc[o]=1;
        return;
    }
    tag[o<<1]+=tag[o];
    tag[o<<1|1]+=tag[o];
    minn[o<<1]+=tag[o];
    minn[o<<1|1]+=tag[o];
    tag[o]=0;
}
void maintain(int o,int l,int r)
{
    if(minn[o<<1]==minn[o<<1|1])minn[o]=minn[o<<1],cc[o]=cc[o<<1]+cc[o<<1|1];
    else if(minn[o<<1]<minn[o<<1|1])minn[o]=minn[o<<1],cc[o]=cc[o<<1];
    else minn[o]=minn[o<<1|1],cc[o]=cc[o<<1|1];
}
void add(int o,int l,int r,int L,int R,int x)
{
    if(L<=l&&r<=R)
    {
        tag[o]+=x;
        minn[o]+=x;
        return;
    }
    pushdown(o,l,r);
    int m=l+r>>1;
    if(L<=m)add(o<<1,l,m,L,R,x);
    if(m<R)add(o<<1|1,m+1,r,L,R,x);
    maintain(o,l,r);
}
inline int query()
{
    if(minn[1]==0)return cc[1];
    return 0;
}
arr dfn,l,r;
int dd;
#include <vector>
std::vector<int>vw[1000005];
arr idfn;
void dfs(int u,int fa)
{
	dfn[u]=++dd;l[u]=dd;
	idfn[dd]=u;
	fe(u)if(v!=fa)dfs(v,u),vw[u].push_back(l[v]);gr
	r[u]=dd;
}
#include <set>
std::set<int>g[1000005];

signed main()
{
	int n=read(),m=read();rg(n-1)
	int u=read(),v=read();
	addedge(u,v,1),addedge(v,u,1);
	gr
	dfs(1,0);
	build(1,1,n);
	rg(m)
	int u=read(),v=read();
	if(dfn[u]>dfn[v])u^=v^=u^=v;
	int w=1;
	if(g[u].count(v))g[u].erase(v),w=-1;
	else g[u].insert(v);
	if(r[u]>=dfn[v])
	{
		int t=std::upper_bound(vw[u].begin(),vw[u].end(),dfn[v])-vw[u].begin()-1;
		u=idfn[vw[u][t]];
		add(1,1,n,l[u],r[u],w);
		add(1,1,n,l[v],r[v],-w);
	}
	else
	{
		add(1,1,n,1,n,w);
		add(1,1,n,l[u],r[u],-w);
		add(1,1,n,l[v],r[v],-w);
	}
	odl(query());
	gr
	return 0;
}