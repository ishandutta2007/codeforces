// Problem: D. Shop
// Contest: Codeforces - Codeforces Round #295 (Div. 1)
// URL: https://codeforces.com/problemset/problem/521/D
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
#define int __int128
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
int a[200005],c[200005],d[200005],v[200005];
struct op{
	int id,o,v;long double x;
	int p;
	bool operator<(const op &b)const
	{
		return v>b.v;
	}
};
std::vector<op> G[200005];
op b[200005],f[200005];
const int mod=1000000007;
signed main()
{
	int n=read(),m=read(),k=read();
	rg(n)d[i]=a[i]=read();G[i].push_back((op){0,1,0,0,i});gr
	rg(m)b[i].o=read(),b[i].p=read(),b[i].v=read(),b[i].id=i;
	if(b[i].o==1)
	{
		if(b[i].v-a[b[i].p]>c[b[i].p])
		c[b[i].p]=b[i].v-a[b[i].p],G[b[i].p][0]=(op){i,1,b[i].v-a[b[i].p],0,b[i].p};
	}
	gr
	rg(m)if(b[i].o==2)G[b[i].p].push_back((op){i,2,b[i].v,0,b[i].p});gr
	rg(n)std::sort(G[i].begin(),G[i].end());gr
	//rg(n)for(auto x:G[i])printf("%d %d %d %d\n",x.id,x.o,x.v,x.p);gr
	rg(n)for(auto &x:G[i]){int N=d[i]+x.v;x.x=1.0L*N/d[i];d[i]=N;}gr
	rg(m)if(b[i].o==3)G[b[i].p].push_back((op){i,3,b[i].v,b[i].v,b[i].p});gr
	int ff=0;
	rg(n)for(auto x:G[i])f[++ff]=x;gr
	std::sort(f+1,f+1+ff,[&](op x,op y){return x.x>y.x;});
	rg(k)v[f[i].id]=1;gr
	v[0]=0;
	int t=0;
	rg(n)std::sort(G[i].begin(),G[i].end(),[&](op x,op y){return x.o<y.o;});gr
	rg(n)for(auto x:G[i])if(v[x.id])t++;gr
	odl((signed)t);
	rg(n)for(auto x:G[i])if(v[x.id])odb((signed)x.id);gr
	// rg(n)for(auto x:G[i])if(v[x.id])x.o==3?a[i]=a[i]*x.v%mod:a[i]=(a[i]+x.v)%mod;gr
	// int ans=1;
	// rg(n)ans=ans*a[i]%mod;gr
	// oldl(ans);
	return 0;
}