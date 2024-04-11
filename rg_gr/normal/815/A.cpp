// Problem: A. Karen and Game
// Contest: Codeforces - Codeforces Round #419 (Div. 1)
// URL: https://codeforces.com/contest/815/problem/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
int a[105][105],p[105][105],minn[105];
signed main()
{
	int n=read(),m=read();
	if(n>m)
	{
		rg(n)rg_(j,m)a[j][i]=read();gr gr n^=m^=n^=m;
		rg(n)rg_(j,m)p[i][j]=a[i][j]-a[i][1];gr gr
		rg_(j,m)rg(n)if(p[i][j]!=p[1][j])return puts("-1")&0;gr gr
		rg(n)minn[i]=0x3f3f3f3f;rg_(j,m)minn[i]=min(minn[i],a[i][j]);gr gr
		int cc=0;
		rg(n)rg_(j,minn[i])cc++;gr gr
		rg(m)rg_(j,a[1][i]-minn[1])cc++;gr gr odl(cc);
		rg(n)rg_(j,minn[i])printf("col %d\n",i);gr gr
		rg(m)rg_(j,a[1][i]-minn[1])printf("row %d\n",i);gr gr
		return 0;
	}
	rg(n)rg_(j,m)a[i][j]=read();gr gr
	rg(n)rg_(j,m)p[i][j]=a[i][j]-a[i][1];gr gr
	rg_(j,m)rg(n)if(p[i][j]!=p[1][j])return puts("-1")&0;gr gr
	rg(n)minn[i]=0x3f3f3f3f;rg_(j,m)minn[i]=min(minn[i],a[i][j]);gr gr
	int cc=0;
	rg(n)rg_(j,minn[i])cc++;gr gr
	rg(m)rg_(j,a[1][i]-minn[1])cc++;gr gr odl(cc);
	rg(n)rg_(j,minn[i])printf("row %d\n",i);gr gr
	rg(m)rg_(j,a[1][i]-minn[1])printf("col %d\n",i);gr gr
	return 0;
}