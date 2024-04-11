// Problem: F1. Alice and Recoloring 1
// Contest: Codeforces - Codeforces Round #746 (Div. 2)
// URL: https://codeforces.com/contest/1592/problem/F1
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
// #define DEBUG
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
#define mgs int fa[1<<22],sz[1<<22];\
inline int f(int x){return x==fa[x]?x:fa[x]=f(fa[x]);}\
inline int uf(int x,int y)\
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
    while(c<'B'||c>'W')c=getchar();
    return c=='B';
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int a[505][505],b[505][505];
struct Edge{
	int v,w,nxt;
}e[2500005];
int h[100005],cnt=2;
void addedge(int u,int v,int w)
{
	e[cnt]=(Edge){v,w,h[u]};
	h[u]=cnt++;
}
int now[100005];
int vis[200005],dep[100005];
int bfs(int s,int t)
{
	std::queue<int> q;
	memset(vis,0,sizeof(vis));
	vis[s]=1,dep[s]=0,now[s]=h[s];
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(vis[v]||e[i].w==0)continue;
			dep[v]=dep[u]+1;
			now[v]=h[v];
			q.push(v);
			vis[v]=1;
			if(v==t)return 1;
		}
	}
	return 0;
}
int dfs(int u,int t,int f)
{
	if(u==t)return f;
	int l=f;
	for(int i=now[u];i;i=e[i].nxt)
	{
		now[u]=i;
		int v=e[i].v;
		if(e[i].w&&dep[v]==dep[u]+1)
		{
			int flow=dfs(v,t,e[i].w<l?e[i].w:l);
			e[i].w-=flow,e[i^1].w+=flow;
			l-=flow;
			if(l==0)break;
		}
	}
	return f-l;
}
signed main()
{
	int n=read(),m=read();
	rg(n)rg_(j,m)a[i][j]=re1d();gr gr
	rg(n)rg_(j,m)b[i][j]=a[i][j]^a[i+1][j]^a[i][j+1]^a[i+1][j+1];gr gr
	// rg(n)rg_(j,m)od(a[i][j]);gr puts("");gr
	int ans=0;
	// n--,m--;
	rg(n)rg_(j,m)ans+=b[i][j];gr gr
	// rg(n-1)rg_(j,m-1)
	// if(b[i][j]&&b[n][j]&&b[i][m]&&b[n][m])return odl(ans-1),0;
	// gr gr
	int s=0,t=n+m+1;
	rg(n-1)if(b[i][m]==1)addedge(s,i,1),addedge(i,s,0);gr
	rg(m-1)if(b[n][i]==1)addedge(i+n,t,1),addedge(t,i+n,0);gr
	rg(n-1)rg_(j,m-1)if(b[i][j])addedge(i,j+n,1),addedge(j+n,i,0);gr gr
	int A=0;while(bfs(s,t))A+=dfs(s,t,0x3f3f3f3f);
	// odl(ans);odl(A);
	int r=0x3f3f3f3f;
	if(b[n][m])
	{
		//A
		int t=ans;
		int d=b[n][m];t-=d;d^=A&1;t+=d;r=min(r,t-A);
		if(A>=1){t=ans;d=b[n][m];t-=d-1;d^=A+1&1;t+=d;r=min(r,t-A+1);}
	}
	else
	{
		int t=ans;
		int d=b[n][m];t-=d;d^=A&1;t+=d;r=min(r,t-A);
		if(A>=1){t=ans;d=b[n][m];t-=d-1;d^=A+1&1;t+=d;r=min(r,t-A+1);}
	}
	odl(r);
	return 0;
}