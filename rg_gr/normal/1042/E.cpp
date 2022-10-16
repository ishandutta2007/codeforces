// Problem: E. Vasya and Magic Matrix
// Contest: Codeforces - Codeforces Round #510 (Div. 2)
// URL: http://codeforces.com/problemset/problem/1042/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
struct TiansuoHaoer{
	signed x,y,w;
	bool operator<(const TiansuoHaoer &b)const
	{
		return w<b.w;
	}
}a[1005005];
typedef int arr[1000005];
// inv[1000005],ans[1000005];
arr inv,ans,x1,x2,y1,y2;
const int mod=998244353+0;
signed main()
{
	int n=read(),m=read();
	rg(n)rg_(j,m)a[i*m-m+j]=(TiansuoHaoer){i,j,read()};gr gr
	int r=read(),c=read(),cur=0;
	std::sort(a+1,a+1+n*m);
//	int x1=0,x2=0,y1=0,y2=0,sum=0;
	inv[1]=1;rg(n*m)if(i>1)inv[i]=(mod-mod/i)*inv[mod%i]%mod;gr
	rg(n*m)while(cur+1<i&&a[cur+1].w<a[i].w)cur++;
	int t=(y2[cur]+x2[cur]-2*y1[cur]*a[i].y-2*x1[cur]*a[i].x+ans[cur]+(cur)*(a[i].x*a[i].x%mod+a[i].y*a[i].y%mod))%mod+mod;
	(t*=inv[cur])%=mod;ans[i]=ans[i-1]+t,ans[i]%=mod;
	x1[i]=x1[i-1]+a[i].x,x2[i]=x2[i-1]+a[i].x*a[i].x,y1[i]=y1[i-1]+a[i].y,y2[i]=y2[i-1]+a[i].y*a[i].y;
	x1[i]%=mod,x2[i]%=mod,y1[i]%=mod,y2[i]%=mod;
//	printf("%lld %lld %lld %lld %lld %lld\n",x1[i],x2[i],y1[i],y2[i],ans[i],(ans[i]-ans[i-1]+mod)%mod);
	if(a[i].x==r&&a[i].y==c)return oldl((long long)t)&0;gr
	return 0;
}