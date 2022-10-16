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
struct GodL{
	int maxn[800005],val[800005],pos[800005];
	inline void maintain(int o)
	{
		maxn[o]=max(maxn[o<<1|1],maxn[o<<1]);
		if(val[pos[o<<1]]>val[pos[o<<1|1]])pos[o]=pos[o<<1];
		else pos[o]=pos[o<<1|1];
	}
	void build(int o,int l,int r)
	{
		if(l==r)
		{
			maxn[o]=val[l];
			pos[o]=l;
			return;
		}
		int m=l+r>>1;
		build(o<<1,l,m);
		build(o<<1|1,m+1,r);
		maintain(o);
	}
	void modify(int o,int l,int r,int p,int v)
	{
		if(l==r)
		{
			val[l]=maxn[o]=v;
			return;
		}
		int m=l+r>>1;
		if(p<=m)modify(o<<1,l,m,p,v);
		else modify(o<<1|1,m+1,r,p,v);
		maintain(o);
	}
}t;
#define add modify
#include <vector>
std::vector<int>g[200005];
int tmp[200005],a[200005];
signed main()
{
	int n=read();
	rg(n)int x=read();
	int y=read();
	g[x].push_back(y);
	t.val[x]=y;a[x]=y;
	gr
	t.build(1,1,n);
	int q=read();
	rg(q)
	int s=read();
	rg(s)tmp[i]=read();t.add(1,1,n,tmp[i],0);gr
	int qwq=t.pos[1];
	int x;
	if(t.maxn[1]==0){odp(0,0);goto re;}
	t.add(1,1,n,qwq,0);
	x=t.maxn[1];
	odp(qwq,*(lower_bound(g[qwq].begin(),g[qwq].end(),x)));
	t.add(1,1,n,qwq,a[qwq]);
	re:;
	rg(s)t.add(1,1,n,tmp[i],a[tmp[i]]);gr
	gr
	return 0;
}