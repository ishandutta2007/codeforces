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
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
//#define int long long
#define newe(n) struct Edge{int v,nxt;}e[n*2+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v){e[cnt]=(Edge){v,h[u]};h[u]=cnt++;}
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
newe(1000005);
arr a,c,d,sz,hson,s,ans,vv,U,qwq,f,dep;
int *q[1000005];
#include <set>
std::set<int> sq[1000005];
void add(int u,int fa)
{
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa)continue;
		add(v,u);
	}
	sq[dep[u]].insert(f[u]);
}
void dfs(int u,int fa)
{
	sz[u]=1;dep[u]=dep[fa]+1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u);
		sz[u]+=sz[v];
		sz[v]>sz[hson[u]]&&(hson[u]=v);
	}
}
void dfs2(int u,int fa)
{
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v!=hson[u]&&v!=fa)dfs2(v,u);
	}
	if(hson[u])dfs2(hson[u],u);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v!=hson[u]&&v!=fa)add(v,u);
	}
	sq[dep[u]].insert(f[u]);
	rg(s[u])ans[q[u][i]]=sq[dep[u]+vv[q[u][i]]].size();gr
	if(hson[fa]!=u)for(int i=dep[u];sq[i].size();i++)sq[i].clear();
}
#include <map>
struct string{
	char c[22];
	bool operator<(const string& b)const
	{
		rg(114514)if(c[i]==0&&b.c[i]==0)return 0;
		if(c[i]==b.c[i])continue;
		return c[i]<b.c[i];gr
		return 0;
	}
};
std::map<string,int>mp;
signed main()
{
	int n=read(),pigstd=0;
	rg(n)
	string x;
	scanf("%s",x.c+1);
	if(!mp.count(x))mp[x]=++pigstd;
	f[i]=mp[x];
	int xx=read();addedge(xx,i);gr
	int m=read();
	rg(m)U[i]=read(),vv[i]=read();
	s[U[i]]++;gr
	rg(n)q[i]=new int[s[i]+1];gr
	rg(m)q[U[i]][++qwq[U[i]]]=i;gr
	dfs(0,0);dfs2(0,0);
	rg(m)odl(ans[i]);gr
	rg(n)delete[] q[i];gr
	return 0;
}