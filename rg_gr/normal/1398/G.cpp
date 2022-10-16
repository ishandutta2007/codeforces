// Problem: G. Running Competition
// Contest: Codeforces - Educational Codeforces Round 93 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1398/G
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
#include <math.h>
#define int long long
struct I{
	double a,b;
	I(double a=0,double b=0):a(a),b(b){}
	I operator+(const I& x)const
	{
		return (I){(a+x.a),(b+x.b)};
	}
	I operator-(const I& x)const
	{
		return (I){(a-x.a),(b-x.b)};
	}
	I operator*(const I& x)const
	{
		return (I){(a*x.a-b*x.b),(b*x.a+a*x.b)};
	}
};
template<typename T>
T qp(T x,int p)
{
	T res(1);
	while(p)
	{
		if(p&1)res=res*x;
		x=x*x;
		p>>=1;
	}
	return res;
}
int r[4000005];I t,pp;
const double p=3.1415926535897932;
void FFT(int o,I* a,int C)
{
	for(int i=0;i<o;i++)
		if(i<r[i])t=a[i],a[i]=a[r[i]],a[r[i]]=t;
	for(int i=1;i<o;i<<=1)
	{
		I x(cos(p/i),C*sin(p/i));
		for(int j=0;j<o;j+=(i<<1))
		{
			I y(1,0);
			for(int k=0;k<i;k++,y=y*x)
			{
				t=a[j+i+k]*y;pp=a[j+k];
				a[j+k]=pp+t;a[j+i+k]=pp-t;
			}
		}
	}
}
I a[4000005],b[4000005];
int ans[4000005],o;
void EFT(int n,int m)
{
	int l=0;
	o=1;while(o<=n+m)o<<=1,l++;    
	for(int i=0;i<o;i++)r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	FFT(o,a,1);FFT(o,b,1);
	for(int i=0;i<=o;i++)a[i]=a[i]*b[i];
	FFT(o,a,-1);
}
#ifdef DEBUG
const int N=101;
#else 
const int N=200005;
#endif
int res[1000005];
signed main()
{
	int n=read(),x=read(),y=read(),l=0;
	for(int i=0;i<=n;i++)l=read(),a[l+N].a=1,b[N-l].a=1;;
	// rg(N<<1)odb((int)a[i].a);gr puts("");
	// rg(N<<1)odb((int)b[i].a);gr puts("");
	EFT(N<<1,N<<1);
	for(int i=0;i<=x;i++)//printf("%lld ",(long long)(a[i].a/o+0.5));
		ans[i]=(long long)(a[i+N+N].a/o+0.5);//odl(ans[i]);
	memset(res,-1,sizeof(res));
	rg(x)
	if(ans[i]==0)continue;
	int t=i+y<<1;
	for(int j=t;j<=1000000;j+=t)res[j]=t;
	gr
	int m=read();rg(m)odb(res[read()]);gr
	// rg(x)odb(ans[i]);gr puts("");
	return 0;
}