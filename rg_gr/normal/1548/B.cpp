// Problem: B. Integers Have Friends
// Contest: Codeforces - Codeforces Round #736 (Div. 1)
// URL: https://codeforces.com/contest/1548/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
#define int long long
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
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int f[200005][20],a[200005],lq[200005];
inline int g(int l,int r)
{
	int j=lq[r-l+1];
	return gcd(f[l][j],f[r-(1<<j)+1][j]);
}
signed main()
{
	int T=read();
	lq[0]=-1;
	rg(200000)lq[i]=lq[i>>1]+1;gr
	rg(T)
	int n=read();
	rg(n)a[i]=read();gr
	if(n==1){puts("1");continue;}
	n--;
	rg(n)f[i][0]=a[i+1]-a[i];if(f[i][0]<0)f[i][0]=-f[i][0];gr
//	rg(n)odb(f[i][0]);gr puts("");
	for(int i=1;i<=18;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			f[j][i]=gcd(f[j][i-1],f[j+(1<<i-1)][i-1]);
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int m=l+r>>1;
//		oldl(m);
		for(int i=1;i+m-1<=n;i++)
		{
			if(g(i,i+m-1)>1)
			{
				ans=m;
				l=m+1;
				goto qwq;
			}
		}
//		puts("failde");
		r=m-1;
		qwq:;
	}
	oldl(ans+1);
	gr
	return 0;
}