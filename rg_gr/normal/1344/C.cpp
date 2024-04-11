// Problem: C. Quantifier Question
// Contest: Codeforces - Codeforces Round #639 (Div. 1)
// URL: https://codeforces.com/contest/1344/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
#define DEBUG
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <assert.h>
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
template<typename T>
void print(T x){}
template<>
void print<int>(int x){od(x);}
template<>
void print<const int>(const int x){od(x);}
template<>
void print<long long>(long long x){old(x);}
template<>
void print<const long long>(const long long x){old(x);}
template<>
void print<char>(char x){putchar(x);}
template<>
void print<const char>(const char x){putchar(x);}
template<>
void print<double>(double x){printf("%.12lf",x);}
template<typename T,typename... qwq>
void print(T x,qwq ...args)
{
	print(x);
	print(args...);
}
#ifdef DEBUG
template<typename T>
void debug(T x){}
template<>
void debug<int>(int x){od(x);}
template<>
void debug<const int>(const int x){od(x);}
template<>
void debug<long long>(long long x){old(x);}
template<>
void debug<const long long>(const long long x){old(x);}
template<>
void debug<char>(char x){putchar(x);}
template<>
void debug<const char>(const char x){putchar(x);}
template<>
void debug<double>(double x){printf("%.12lf",x);}
template<typename T,typename... qwq>
void debug(T x,qwq ...args)
{
	debug(x);
	debug(args...);
}
#define dflush fflush
#else
#define dflush(...) 0
template<typename T,typename... qwq>
void debug(T x,qwq ...args)
{
	
}
#endif
//#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[2*n+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}
#define mgs int fa[1<<22],sz[1<<22],sz1[1<<22],sz2[1<<22];\
inline int f(int x){return x==fa[x]?x:fa[x]=f(fa[x]);}\
inline int uf(int x,int y)\
{\
    int fx=f(x),fy=f(y);\
    if(fx==fy)return 0;\
    fa[fx]=fy,sz[fy]+=sz[fx];\
    sz1[fy]+=sz1[fx];\
    sz2[fy]+=sz2[fx];\
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
newe(400005);
mgs
// int ans[1<<22];
arr ans,vis,deg,D,All,Exist,dd;
void dfs(int u)
{
	vis[u]=1;
	fe(u)if(e[i].w==0)continue;D[v]--;if(D[v]==0)dfs(v);gr
}
signed main()
{
	int n=read(),m=read();
	
	rg(n+n)fa[i]=i,sz[i]=1;sz1[i]=i<=n,sz2[i]=sz1[i]^1;gr
	rg(m)int u=read(),v=read();
	uf(u+n,v);uf(u,v+n);
	addedge(u,v,1);addedge(v,u,0);deg[v]++;dd[u]++;gr
	rg(n)D[i]=deg[i];gr
	rg(n)if(deg[i]==0&&!vis[i])dfs(i);gr
	rg(n)if(D[i])return puts("-1"),0;gr
	rg(n)D[i]=deg[i];gr
	std::queue<int>q;
	// fe(u)
	rg(n)if(deg[i]==0)q.push(i);All[i]=i;gr
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		fe(u)
		if(e[i].w==0)continue;
		deg[v]--;
		if(deg[v]==0)q.push(v);
		All[v]=min(All[v],All[u]);
		// All[v]+=Exist[u];
		// Exist[v]+=max(Exist[u],All[u]);
		gr
	}
	rg(n)deg[i]=dd[i];gr
	rg(n)if(deg[i]==0)q.push(i);Exist[i]=i;gr
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		fe(u)
		if(e[i].w==1)continue;
		deg[v]--;
		if(deg[v]==0)q.push(v);
		Exist[v]=min(Exist[v],Exist[u]);
		// All[v]+=Exist[u];
		// Exist[v]+=max(Exist[u],All[u]);
		gr
	}
	int s=0;
	rg(n)if(All[i]==i&&Exist[i]==i)s++;gr
	odl(s);
	rg(n)if(All[i]==i&&Exist[i]==i)putchar('A');else putchar('E');gr
	return 0;
}