// Problem: C. Region Separation
// Contest: Codeforces - Codeforces Round #511 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1034/C
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
#ifdef int 
#define inf 0x3f3f3f3f3f3f3f3fll
#else 
#define inf 0x3f3f3f3f
#endif
#define newe(n) struct Edge{int v,w,nxt;}e[2*n+5];\
typedef int arr[n+5];\
arr h;\
int cnt=2;\
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
newe(1000000);
arr a,sz,faa,s,fm;int cc=0;
//void qwq(int u,int fa=0,int from=0)
//{
//	sz[u]=1;
//	s[++cc]=u;
//	faa[u]=fa;
//	fm[u]=from;
//	fe(u)if(v!=fa&&e[i].w)qwq(v,u,i),sz[u]+=sz[v];gr
//}
void qwq(int u,int fa=0)
{
	sz[u]=a[u];
	fe(u)if(v!=fa)qwq(v,u),sz[u]+=sz[v];gr
}
// int solve(int u)
// {
	// cc=0;
	// qwq(u);
	// rg(cc)if(sz[s[i]]*2==sz[u])
	// {
		// int v=s[i];
		// int id=fm[v];
		// e[id].w=e[id^1].w=0;
		// return solve(v)*solve(faa[v])+1;
	// }gr
	// return 1;
// }
arr tt;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
signed main()
{
	int n=read(),g=0;
	rg(n)a[i]=read();g+=a[i];gr
	rg(n)if(i>1)
	{
		int x=read();
		addedge(x,i,1);addedge(i,x,1);
	}gr
	// odl(solve(1));
	// odl(g);
	int t;
	rg(inf)
	if(i*i>g)break;
	t=i;
	if(g%i==0)
	{
		s[++cc]=i;
	}
	gr
	rg_(j,t)
	int i=t-j+1;
	if(g%i==0&&i*i!=g)
	{
		s[++cc]=g/i;
	}
	gr
	// rg(cc)odb(s[i]);gr
	while(s[cc]>n)cc--;
	qwq(1);
	// if(n==923354)return 0;
	//assert(cc<=10000);
	rg(n)
	int t=g/gcd(g,sz[i]);
	if(t<=n)faa[t]++;
	gr
	rg(n)rg_(j,n/i)fm[j*i]+=faa[i];gr gr
	rg(cc)
	// int t=0;
	// rg_(j,n)if(sz[j]%(g/s[i])==0)t++;gr
	// odp(s[i],t);
	// if(t==s[i])tt[i]++;
	tt[i]=(s[i]==fm[s[i]]);
	gr
	// rg(cc)odb(s[i]);gr puts("");
	// rg(cc)odb(tt[i]);gr puts("");
	// std::reverse(s+1,s+1+cc);
	rg(cc)if(!tt[i])continue;
	rg_(j,i-1)if(j>1&&s[i]%s[j]==0)tt[i]+=tt[j];gr gr
	int ans=0;
	rg(cc)ans+=tt[i];gr 
	oldl(ans);
	return 0;
}