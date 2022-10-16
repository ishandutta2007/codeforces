// Problem: G. Pawns
// Contest: Codeforces - Educational Codeforces Round 90 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1373/G
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
std::set<int>G[200005];
std::multiset<int>s;
const int N=600002;
typedef int arr[N*4+5];
arr tag,maxn;
int n;
void maintain(int o)
{
	maxn[o]=max(maxn[o<<1],maxn[o<<1|1]);
}
void build(int o,int l,int r)
{
	if(l==r)maxn[o]=l;
	else 
	{
		int m=l+r>>1;
		build(o<<1,l,m);
		build(o<<1|1,m+1,r);
		maintain(o);
	}
}
void pushdown(int o)
{
	tag[o<<1]+=tag[o];
	tag[o<<1|1]+=tag[o];
	maxn[o<<1]+=tag[o];
	maxn[o<<1|1]+=tag[o];
	tag[o]=0;
}
void add(int o,int l,int r,int L,int R,int v)
{
	if(L<=l&&r<=R)
	{
		tag[o]+=v;
		maxn[o]+=v;
		return;
	}
	pushdown(o);
	int m=l+r>>1;
	if(L<=m)add(o<<1,l,m,L,R,v);
	if(m<R)add(o<<1|1,m+1,r,L,R,v);
	maintain(o);
}
int qmax(int o,int l,int r,int L,int R)
{
	if(L<=l&&r<=R)return maxn[o];
	int m=l+r>>1,res=0;
	pushdown(o);
	if(L<=m)res=max(res,qmax(o<<1,l,m,L,R));
	if(m<R)res=max(res,qmax(o<<1|1,m+1,r,L,R));
	return res;
}
signed main()
{
	n=read();int m=read(),k=read(),N=n+k+n;
	s.insert(n);
	build(1,1,N);
	rg(k)
	int x=read(),y=read(),d=0;
	x-=m;
	int pos=y+(x>0?x:-x);
	x+=m;
	if(G[x].count(y))G[x].erase(y),d=1,s.erase(s.lower_bound(pos)),add(1,1,N,1,pos,-1);
	else G[x].insert(y),d=-1,s.insert(pos),add(1,1,N,1,pos,1);
	// odl(pos);
	auto xd=s.end();xd--;
	// rg(N)odb(qmax(1,1,N,i,i));gr puts("");
	// odl(*xd);
	odl(max(qmax(1,1,N,1,*xd)-n-1,0));
	// odl(pos);
	gr
	return 0;
}