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
#define int long long
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
/*
 
 
 size
*/
newe(200005);
arr a,dep,dep0,dep1;
int d0,d1,ans;
const int mod=1000000007;
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	if(dep[u]&1)dep1[u]=1,d1++;else dep0[u]=1,d0++;
	fe(u)if(v!=fa)dfs(v,u),dep0[u]+=dep0[v],dep1[u]+=dep1[v];gr
}
void dfs1(int u,int fa)
{
	fe(u)if(v==fa)continue;
	dfs1(v,u);
	if(dep[u]&1)
	{
		ans+=dep1[v]*(d1-dep1[v]-1)%mod*a[u]%mod;
		ans-=dep0[v]*(d0-dep0[v])%mod*a[u]%mod;
	}
	else
	{
		ans+=dep0[v]*(d0-dep0[v]-1)%mod*a[u]%mod;
		ans-=dep1[v]*(d1-dep1[v])%mod*a[u]%mod;
	}
	gr
	if(dep[u]&1)ans+=(d1+d1-1)*a[u]%mod,ans-=dep0[u]*(d0-dep0[u])%mod*a[u]%mod,ans+=(dep1[u]-1)*(d1-dep1[u])%mod*a[u]%mod;
	else ans+=(d0+d0-1)*a[u]%mod,ans-=dep1[u]*(d1-dep1[u])%mod*a[u]%mod,ans+=(dep0[u]-1)*(d0-dep0[u])%mod*a[u]%mod;
}
signed main()
{
	int n=read();
	rg(n)a[i]=read();gr
	rg(n-1)int x=read(),y=read();
	addedge(x,y,1),addedge(y,x,1);gr
	dfs(1,1);
	dfs1(1,1);
	oldl((ans%mod+mod)%mod);
	return 0;
}