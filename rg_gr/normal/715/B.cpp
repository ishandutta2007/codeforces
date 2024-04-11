// Problem: CF715B Complete The Graph
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF715B
// Memory Limit: 250 MB
// Time Limit: 4000 ms
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
#define int long long
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
newe(500005);
arr id,dis,vis;
int QQ[1000005];
struct _{int u,d;bool operator<(const _&b)const{return d>b.d;}};
inline int dij(int s,int t)
{
	std::priority_queue<_>q;
	q.push((_){s,0});
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof(vis));dis[s]=0;
	while(!q.empty())
	{
		int u=q.top().u;q.pop();
		if(vis[u])continue;vis[u]=1;
		fe(u)if(dis[v]>dis[u]+e[i].w)dis[v]=dis[u]+e[i].w,q.push((_){v,dis[v]});gr
	}
	return dis[t];
}
inline int check(int m,int p,int s,int t)
{
	if(p){
	int Q=m%p;
	rg(p)e[id[i]].w=e[id[i]+1].w=m/p+(i<=Q);gr}
	return dij(s,t);
}
signed main()
{
	int n=read(),m=read(),L=read(),s=read(),t=read(),p=0;
	rg(m)int x=read(),y=read(),w=read();
	if(w==0)id[++p]=cnt;addedge(x,y,w),addedge(y,x,w);gr
//	odl(dij(s,t));
	int l=p,r=p*L,ans=-1;
//	odp(l,r)
	while(l<=r)
	{
		int m=l+r>>1;
		if(check(m,p,s,t)>=L)ans=m,r=m-1;
		else l=m+1;
	}
	check(ans,p,s,t);
	if(dij(s,t)==L)
	{
		puts("YES");
		rg_(u_,n)int u=u_-1;
		fe(u)QQ[i]=u;gr gr
		rg(m)Edge x=e[i*2-1];
		odb(QQ[i*2-1]),odp(x.v,x.w);gr
		
	}else puts("NO");
	return 0;
}