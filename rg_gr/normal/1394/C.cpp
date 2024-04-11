// Problem: C. Boboniu and String
// Contest: Codeforces - Codeforces Round #664 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1394/C
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
char a[1000005];
int x[1000005],y[1000005];
#define c(x,y,op) x=op(x,y)
int sec(int l,int r,int L,int R)
{
	// odp(l,r);
	// odp(L,R);
	if(r<L||R<l)return 0;
	return 1;
}
signed main()
{
	int n=read();
	int ymx=-inf,ymn=inf,xmx=-inf,xmn=inf,xymx=-inf,xymn=inf;
	rg(n)scanf("%s",a+1);int m=strlen(a+1);
	rg_(j,m)if(a[j]=='B')x[i]++;else y[i]++;gr
	c(ymx,y[i],max);
	c(xmx,x[i],max);
	c(xymx,y[i]-x[i],max);
	c(ymn,y[i],min);
	c(xmn,x[i],min);
	c(xymn,y[i]-x[i],min);
	gr
	// odp(xmn,xmx);
	// odp(ymn,ymx);
	// odp(xymn,xymx);
	rrg(2000001)
	{
		#define g(x) int x##l=x##mx-i,x##r=x##mn+i
		g(x);g(y);g(xy);
		// xl=max(xl,1);
		// yl=max(yl,1);
		int Y=yl;yl=max(yl,1);
		if(sec(xyl,xyr,yl-xr,yr-xl)&&xl<=xr&&yl<=yr&&xyl<=xyr)
		{
			odl(i);
			//
			int l=xl,r=xr;
			for(int xl=l,xr=l;xl<=r;xl++,xr++)
			{
				if(sec(xyl,xyr,yl-xr,yr-xl)&&xl<=xr&&yl<=yr&&xyl<=xyr)
				{
					l=yl,r=yr;
					for(int yl=l,yr=l;yl<=r;yl++,yr++)
					if(sec(xyl,xyr,yl-xr,yr-xl)&&xl<=xr&&yl<=yr&&xyl<=xyr)
					{
						rg(xl)putchar('B');gr
						rg(yl)putchar('N');gr
						return 0;
					}
				}
			}
			return 0;
		}
		yl=Y;xl=max(xl,1);

		if(sec(xyl,xyr,yl-xr,yr-xl)&&xl<=xr&&yl<=yr&&xyl<=xyr)
		{
			odl(i);
			//
			int l=xl,r=xr;
			for(int xl=l,xr=l;xl<=r;xl++,xr++)
			{
				if(sec(xyl,xyr,yl-xr,yr-xl)&&xl<=xr&&yl<=yr&&xyl<=xyr)
				{
					l=yl,r=yr;
					for(int yl=l,yr=l;yl<=r;yl++,yr++)
					if(sec(xyl,xyr,yl-xr,yr-xl)&&xl<=xr&&yl<=yr&&xyl<=xyr)
					{
						rg(xl)putchar('B');gr
						rg(yl)putchar('N');gr
						return 0;
					}
				}
			}
			return 0;
		}
	}
	return 0;
}