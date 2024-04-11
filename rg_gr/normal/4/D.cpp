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
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <assert.h>
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
//#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[2*n+5];\
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
typedef int arr[200005];
arr x,y,X,Y,id;
struct piar{
	int a,b,id;
	bool operator<(const piar &x)const
	{
		if(a!=x.a)return a>x.a;
		return b<x.b;
	}
}a[200005];
arr f,dp,pre,pos;
signed main()
{
	int n=read(),w=read()+1,h=read()+1;int d=0;
	rg(n)
	int p=read(),q=read();
	if(p<w||q<h)continue;++d;
	id[d]=i;
	x[d]=X[d]=p,y[d]=Y[d]=q;gr
	n=d;
	if(n==0)return puts("0"),0;
	std::sort(X+1,X+1+n);
	std::sort(Y+1,Y+1+n);
	int lx=std::unique(X+1,X+1+n)-X-1;
	int ly=std::unique(Y+1,Y+1+n)-Y-1;
	rg(n)x[i]=std::lower_bound(X+1,X+1+lx,x[i])-X;gr
	rg(n)y[i]=std::lower_bound(Y+1,Y+1+ly,y[i])-Y;gr
	rg(n)a[i]=(piar){x[i],y[i],id[i]};gr
	std::sort(a+1,a+1+n);
	f[1]=a[1].b;int s=1;pos[1]=1;
	//rg(n)odp(a[i].a,a[i].b);gr puts("");
	rg(n)if(i==1)continue;
	if(f[s]>a[i].b)f[++s]=a[i].b,pre[i]=pos[s-1],pos[s]=i;
	else 
	{
		int x=std::lower_bound(f+1,f+1+s,a[i].b,std::greater<int>())-f;f[x]=a[i].b;pre[i]=pos[x-1];pos[x]=i;
	}
	gr
	odl(s);
	n=pos[s];
	while(n)
	{
		odb(a[n].id);
		n=pre[n];
	}
	return 0;
}