// Problem: D2. Gregor and the Odd Cows (Hard)
// Contest: Codeforces - Codeforces Round #736 (Div. 1)
// URL: https://codeforces.com/contest/1548/problem/D2
// Memory Limit: 256 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//  /

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
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
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
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
//#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[n*2+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}
#define mgs int fa[1<<22],sz[1<<22],t[1<<22];\
inline int f(int x){return x==fa[x]?x:fa[x]=f(fa[x]);}\
inline int u(int x,int y)\
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
long long a111,a110,a000,a001,a010,a011,a100,a101;
signed main()
{
	int n=read();
	long long a00=0,a01=0,a10=0,a11=0;
	rg(n)int xx=read(),yy=read();
	int x=xx&2,y=yy&2;
	int q=(xx&4)^(yy^4);
	if(x&&y){a11++;if(q)a111++;else a110++;}
	else if(x){a10++;if(q)a101++;else a100++;}
	else if(y){a01++;if(q)a011++;else a010++;}
	else {a00++;if(q)a001++;else a000++;}
	gr
//	oldp(a00,a01);
//	oldp(a10,a11);
	long long ans=0;
	ans+=a00*(a00-1)/2*(a11+a01+a10);
	ans+=a01*(a01-1)/2*(a11+a00+a10);
	ans+=a10*(a10-1)/2*(a11+a01+a00);
	ans+=a11*(a11-1)/2*(a00+a01+a10);
	ans+=a00*(a00-1)/2*(a00-2)/3;
	ans+=a01*(a01-1)/2*(a01-2)/3;
	ans+=a10*(a10-1)/2*(a10-2)/3;
	ans+=a11*(a11-1)/2*(a11-2)/3;
	oldl(ans);
	return 0;
}