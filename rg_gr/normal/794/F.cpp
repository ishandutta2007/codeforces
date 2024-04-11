// Problem: F. Leha and security system
// Contest: Codeforces - Tinkoff Challenge - Final Round (Codeforces Round #414, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/794/F
// Memory Limit: 512 MB
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
#define r10g(i) for(int i=0;i<=9;i++){
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
int a[100005][10],sum[400005][10],trans[400005][10];
void maintain(int o)
{
	r10g(i)sum[o][i]=sum[o<<1][i]+sum[o<<1|1][i];gr
}
void pushtag(int o,int p)
{
	int tmp[10]={};
	r10g(i)
	tmp[trans[o][i]]+=sum[p][i];
	gr
	r10g(i)
	trans[p][i]=trans[o][trans[p][i]];
	gr
	r10g(i)sum[p][i]=tmp[i];gr
}
void pushdown(int o)
{
	int l=o<<1,r=o<<1|1;
	pushtag(o,l);
	pushtag(o,r);
	r10g(i)trans[o][i]=i;gr
}
void build(int o,int l,int r)
{
	r10g(i)trans[o][i]=i;gr
	if(l==r)
	{
		r10g(i)sum[o][i]=a[l][i];gr
		return;
	}
	int m=l+r>>1;
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
	maintain(o);
}
void modify(int o,int l,int r,int L,int R,int from,int to)
{
	if(L<=l&&r<=R)
	{
		sum[o][to]+=sum[o][from];
		sum[o][from]=0;
		r10g(i)if(trans[o][i]==from)trans[o][i]=to;gr
		return;
	}
	int m=l+r>>1;
	pushdown(o);
	if(L<=m)modify(o<<1,l,m,L,R,from,to);
	if(m<R)modify(o<<1|1,m+1,r,L,R,from,to);
	maintain(o);
}
int query(int o,int l,int r,int L,int R)
{
	if(L<=l&&r<=R)
	{
		int res=0;
		r10g(i)res+=i*sum[o][i];gr
		return res;
	}
	int m=l+r>>1,res=0;
	pushdown(o);
	if(L<=m)res+=query(o<<1,l,m,L,R);
	if(m<R)res+=query(o<<1|1,m+1,r,L,R);
	return res;
}
signed main()
{
	int n=read(),m=read();rg(n)
	int x=read(),v=1;while(x)
	{
		a[i][x%10]+=v;
		x/=10;
		v=v*10;
	}
	gr
	build(1,1,n);
	// rg(n)odb(query(1,1,n,i,i));gr puts("");
	rg(m)
	int op=read();
	if(op==2)
	{
		int l=read(),r=read();
		oldl(query(1,1,n,l,r));
	}else{
		int l=read(),r=read(),from=read(),to=read();
		if(from!=to)modify(1,1,n,l,r,from,to);
	}
	// rg(n)odb(query(1,1,n,i,i));gr puts("");
	gr
	return 0;
}