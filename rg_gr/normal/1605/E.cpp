// Problem: B. Mathematics Curriculum
// Contest: Codeforces - Codeforces Round #745 (Div. 1)
// URL: https://codeforces.com/contest/1580/problem/B
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
#define fe(u) for(int i=h[u];i;i=e[i].nxt){int v=e[i].v;
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
int a[200005],b[200005],c[200005],k[200005];
//b[1]=x;
//f[i]=|cx+d|
struct qwq{
	int k,b;
	bool operator<(const qwq &v)const{
		// if(v.k==0)return v.b>0;
		// if(k==0)return b<0;
		// -b/k
		if(b==0&&v.b==0)return 0;
		if((b==0)^(v.b==0))return v.b==0;
		return -b*v.k>-v.b*k;
	}
}e[1000005];
int preb[200005],prex[200005];
// #define read dd
// int read(){return rand()%1000000;}
signed main()
{
	int n=read();
	// int n=200;
	//this solution will boom long long
	rg(n)a[i]=read();gr
	int w=a[1];
	rg(n)a[i]=read()-a[i];gr
	rg(n)if(i==1)k[i]=1,b[i]=-w;
	else b[i]+=a[i];
	for(int j=i+i;j<=n;j+=i)b[j]-=b[i],k[j]-=k[i];gr
	rg(n)if(k[i]<0||(k[i]==0&&b[i]<0))k[i]=-k[i],b[i]=-b[i];gr
	rg(n)e[i]=(qwq){k[i],b[i]};gr
	std::sort(e+1,e+1+n);
	int q=read();
	// int q=20;
	rg(n)preb[i]=preb[i-1]+e[i].b;gr
	rg(n)prex[i]=prex[i-1]+e[i].k;gr
	// rg(n)odp(e[i].k,e[i].b);gr
	// return 0;
	rg(q)int x=read();
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int m=l+r>>1;
		if(e[m].k*x+e[m].b<0)ans=m,l=m+1;
		else r=m-1;
	}
	 // odl(ans);
	oldl(-(preb[ans]+x*prex[ans]-x*(prex[n]-prex[ans])-(preb[n]-preb[ans])));
	gr
	return 0;
}