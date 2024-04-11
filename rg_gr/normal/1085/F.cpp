// Problem: F. Rock-Paper-Scissors Champion
// Contest: Codeforces - Technocup 2019 - Elimination Round 4
// URL: https://codeforces.com/problemset/problem/1085/F
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
    while(c<'A'||c>'Z')c=getchar();
    //R 0 S 1 P 2
    return 1+(c=='P'?2:(c=='S'));
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int n=read(),m=read();
struct bit{
	int a[200005];
	void add(int x,int p)
	{
		while(x<=n)a[x]+=p,x+=x&-x;
	}
	int operator[](int x)
	{
		int res=0;
		while(x>0)res+=a[x],x-=x&-x;
		return res;
	}
	int operator()(int l,int r){return (*this)[r]-(*this)[l-1];}
}T[4];
int a[200005];
std::set<int>s[4];
void update(int x,int p)
{
	T[a[x]].add(x,-1);
	s[a[x]].erase(x);
	a[x]=p;
	s[a[x]].insert(x);
	T[a[x]].add(x,1);
}
int f(int x,int y,int z)
{
	int d=T[x][n];
	int r=s[y].size()?*s[y].begin():-1,l=s[z].size()?*s[z].begin():-1;
	if(l==-1)l=n+1;if(r==-1)r=n;
	int L=s[y].size()?*--s[y].end():-1,R=s[z].size()?*--s[z].end():-1;
	if(L==-1)L=0;if(R==-1)R=1;
	if(l>r)l=1,r=0;
	if(L>R)L=1,R=0;
	// odp(l,r);
	// odp(L,R);
	// puts("");
	if(l>L||(l==L&&r>R))l^=L^=l^=L,r^=R^=r^=R;
	if(L<=r)d-=T[x](l,R);
	else d-=T[x](l,r)+T[x](L,R);
	// puts("");
	// odl(d);
// ;	d-=max(0,T[x](max(l,L),min(r,R)));
// puts("");odp(x,d);puts("");
	return d;
}
int solve()
{
	return (f(1,2,3)+f(2,3,1)+f(3,1,2));
}
signed main()
{
	// s[1].insert(-1);
	// s[2].insert(-1);
	// s[3].insert(-1);
	rg(n)update(i,re1d());gr
	// rg(n)odb(a[i]);gr puts("");
	odl(solve());
	rg(m)
	int x=read(),t=re1d();
	update(x,t);
	odl(solve());
	gr
	return 0;
}