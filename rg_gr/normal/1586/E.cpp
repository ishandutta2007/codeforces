// Problem: Moment of Bloom
// Contest: Codeforces
// URL: http://m2.codeforces.com/contest/1586/problem/E
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
//#define int long long
#define newe(n) struct Edge{int v,nxt;}e[2*n+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v){e[cnt]=(Edge){v,h[u]};h[u]=cnt++;}
#define mgs int fa[1<<22],sz[1<<22];\
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
newe(500005);
mgs;
arr a,X,Y,dep,ff;
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;ff[u]=fa;
	fe(u)if(v!=fa)dfs(v,u);gr
}
arr tu,tv;
signed main()
{
	int n=read(),m=read();
	rg(n)fa[i]=i,sz[i]=1;gr
	rg(m)int x=read(),y=read();
	if(u(x,y))addedge(x,y),addedge(y,x);
	gr
	int q=read();
	rg(q)int x=read(),y=read();
	X[i]=x,Y[i]=y;
	a[x]^=1;a[y]^=1;gr
	int ans=0;
	rg(n)if(a[i])ans++;gr
	if(ans)
	{
		puts("NO");
		odl(ans>>1);
		return 0;
	}
	puts("YES");
	dfs(1,1);
	rg(q)
	int u=X[i],v=Y[i];
	int U=0,V=0;
	#define fa ff
	while(dep[u]>dep[v])tu[++U]=u,u=fa[u];
	while(dep[u]<dep[v])tv[++V]=v,v=fa[v];
	if(u==v)
	{
		odl(U+V+1);
		rg(U)odb(tu[i]);gr
		odb(u);
		rg(V)odb(tv[V-i+1]);gr
		puts("");
		continue;
	}
	while(u!=v)
	{
		tu[++U]=u,u=fa[u];
		tv[++V]=v,v=fa[v];
	}
odl(U+V+1);
		rg(U)odb(tu[i]);gr
		odb(u);
		rg(V)odb(tv[V-i+1]);gr
		puts("");
	gr
	return 0;
}