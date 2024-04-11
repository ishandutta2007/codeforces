// Problem: G. Find a Gift
// Contest: Codeforces - Educational Codeforces Round 87 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1354/G
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
    while(c!='R'&&c!='D'&&c!='Q')
    {
    	if(c=='W')exit(0);
    	c=getchar();
    }
    return c;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int randtest(int l,int r)
{
	
}
signed main()
{
	int T=read();rg(T)
	int n=read(),k=read();
	#ifdef DEBUG
	rg(5)
	#else 
	rg(29)
	#endif
	printf("? 1 1\n1\n%d\n",rand()%(n-1)+2);fflush(stdout);
	int op=re1d();
	if(op=='D')
	{
		printf("! 1\n");fflush(stdout);
		n=-1;break;
	}
	gr
	if(n==1)continue;
	int cur=1;
	for(int t=0;(1<<t)<=n;t++)
	{
		int st=cur+1,ed=cur<<1;
		if(ed>n)break;
		printf("? %d %d\n",cur,cur);
		for(int i=1;i<=cur;i++)odb(i);puts("");
		for(int i=1;i<=cur;i++)odb(i+cur);puts("");
		fflush(stdout);
		int op=re1d();
		if(op=='R')break;
		cur<<=1;
	}
	int l=cur+1,r=min(n,cur*2);
	while(l<=r)
	{
		// printf(": %d %d\n",l,r);
		if(l==r)
		{
			printf("! %d\n",l);fflush(stdout);break;
		}
		int m=l+r>>1;
		int ln=m-l+1;
		printf("? ");odp(ln,ln);
		rg(ln)odb(i);gr puts("");
		rg(ln)odb(i+l-1);gr puts("");
		fflush(stdout);int op=re1d();
		if(op=='R')r=m;else l=m+1;
	}
	// int l=1,r=n;
	// while(l<=r)
	// {
		// if(l==r)
		// {
			// printf("! %d\n",l);
			// fflush(stdout);
			// break;
		// }
		// int m=l+r>>1,M=m+1;
		// if((r-l+1)&1)m--;
		// printf("? %d %d\n",m-l+1,r-M+1);
		// for(int i=l;i<=m;i++)odb(i);puts("");
		// for(int i=M;i<=r;i++)odb(i);puts("");
		// fflush(stdout);
		// int op=re1d();
		// if(op=='R')
		// {
// 			
		// }
		// else if(op=='Q')
		// {
			// r=m;
			// //equal : random test L.
			// // if(randtest(l,m))r=m;
			// // else
			// // {
				// // if(randtest(M,r))
			// // }
		// }
		// else
		// {
			// // D : left
			// r=m;
		// }
	// }
	gr
	return 0;
}