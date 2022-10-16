// Problem: G. Weighted Increasing Subsequences
// Contest: Codeforces - Hello 2022
// URL: https://codeforces.com/contest/1621/problem/G
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
#include <vector>
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
int n;
const int mod=1000000007;
inline int md(int a,int b){return (a+b>=mod?a+b-mod:a+b);}
inline int ms(int a,int b){return md(a,mod-b);}
struct dXqwqTree{
	int a[200005];
	void add(int x,int p)
	{
		while(x<=n)a[x]=md(a[x],p),x+=x&-x;
	}
	void reset(int x)
	{
		while(x<=n)a[x]=0,x+=x&-x;
	}
	int operator[](int x)
	{
		int ans=0;
		while(x)ans=md(ans,a[x]),x-=x&-x;
		return ans;
	}
	int operator()(int l,int r){return ms((*this)[r],(*this)[l-1]);}
	void clear()
	{
		rg(n)a[i]=0;;gr
	}
}t;
int a[200005],b[200005],tmp[200005],cc,ways[200005];
std::vector<int>v[200005];
signed main()
{
	int T=read();rg(T)
	n=read();t.clear();
	rg(n)b[i]=a[i]=read()*n+(n-i+1);gr
	std::sort(b+1,b+1+n);
	rg(n)a[i]=std::lower_bound(b+1,b+1+n,a[i])-b;gr
	cc=0;int maxn=0;
	for(int i=n;i>=1;i--)if(a[i]>maxn)maxn=a[i],tmp[++cc]=i;
	rg(n)v[i].clear();gr
	rg(n)b[i]=std::lower_bound(tmp+1,tmp+1+cc,i,[&](int x,int y){return a[x]<a[y];})-tmp;gr
	int ans=0;
	rg(n)v[tmp[b[i]]].push_back(i);gr
	rg(n)
	ways[i]=md(t[a[i]],1);
	t.add(a[i],ways[i]);
	gr
	t.clear();
	rg(n)
	if(tmp[b[i]]!=i)continue;
	std::reverse(v[i].begin(),v[i].end());
	int sz=v[i].size();sz--;
	rg_(j,sz)int u=v[i][j];
	int w=md(t(a[u],n),1);
	t.add(a[u],w);
	ans=ms(ans,ways[u]*w%mod);
	gr
	rg_(j,sz)t.reset(a[v[i][j]]);gr
	ans=ms(ans,ways[i]);
	gr
	for(int i=n;i>=1;i--)
	{
		int w=t(a[i],n)+1;
		t.add(a[i],w);
		ans=md(ans,ways[i]*w%mod);
	}
	oldl(ans);
	gr
	return 0;
}