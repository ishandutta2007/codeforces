// Problem: F. Strange Instructions
// Contest: Codeforces - Hello 2022
// URL: https://codeforces.com/contest/1621/problem/F
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
int a[1000005];
struct pair{
	int x,y;
	bool operator<(const pair&b)const{
		return x<b.x;
	}
}tmp[1000005];
int ss[10000005];
const int Tq=71941944790;
signed main()
{
	int T=read();rg(T)
	int n=read(),A=read(),B=read(),C=read();
	rg(n)a[i]=re1d();gr
	rg(n)ss[i]=a[i];gr
	int sz[2]={},seg[2]={};
	int cc=0;
	int dd=0;
	for(int l=1,r=1;l<=n;l=r+1)
	{
		while(a[r+1]==a[l]&&r<n)r++;
		seg[a[l]]++;
		sz[a[l]]+=r-l+1;
		if(a[l]==0&&l>1&&r<n)tmp[++cc]=(pair){r-l,l};
		else if(a[l]==0)dd++;
	}
	// odp(sz[0]-seg[0],sz[1]-seg[1]);
	int aa=sz[0]-seg[0],bb=sz[1]-seg[1];
	// if(aa==bb)
	int ans=min(aa,bb)*(A+B);
	if(aa>bb)
	{
		// odp(aa,bb);
		std::sort(tmp+1,tmp+1+cc);
		int d=min(aa,bb);
		rg(cc)
		if(d>=tmp[i].x)
		{
			int from=tmp[i].y;
			for(int j=from;j<from+tmp[i].x;j++)a[j]=2;
			d-=tmp[i].x;
		}
		gr
		// rg(n)odb(a[i]);gr puts("");
		rg(n)if(a[i]&&a[i-1])a[i]=2;gr
		std::stable_sort(a+1,a+1+n,[&](int x,int y){return (x<2)>(y<2);});
		int s=n;while(a[s]==2)s--;
		// rg(s)odb(a[i]);gr puts("");
		if(C>=B)
		{
			oldl(ans+A);
			goto qwq;
		}
		//01-seg
		a[n+1]=2;
		// odl(s);
		// rg(s)od(a[i]);gr puts("");
		
		rg(s)if(a[i]==0&&a[i-1]==1&&a[i+1]==1)ans+=B-C;gr
		oldl(ans+A);
		goto qwq;
	}
	else if(aa==bb)
	{
		if(C>=B)
		{
			oldl(ans);
			goto qwq;
		}
		oldl(ans+(B-C)*max(0,min(seg[0],seg[1]-1)));
	}
	else
	{
		if(C>=B)
		{
			oldl(ans+B);
			goto qwq;
		}
		// odl();
		
		oldl(ans+B+(B-C)*min(cc+dd,max(0,sz[1]-2-min(aa,bb))));
	}
	qwq:;
	gr
	return 0;
}