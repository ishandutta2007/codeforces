// Problem: E. Capitalism
// Contest: Codeforces - Codeforces Global Round 12
// URL: https://codeforces.com/problemset/problem/1450/E
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
#ifndef ONLINE_JUDGE
#define DEBUG
#endif
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
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;debug(u,' ',v,' ',w,'\n');}
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
    while(c<48||c>49)c=getchar();
    return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
newe(200000)
int inq[10005],dis[10005],c[100005];
inline int stO_zhoukangyang_Orz_zaky_txdy_orzorzorztql(int s,int n)
{
	std::queue<int> q;
	memset(dis,-0x3f,sizeof(dis));
	dis[s]=0,inq[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();q.pop();inq[u]=0;
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(dis[v]<dis[u]+e[i].w)
			{
				dis[v]=dis[u]+e[i].w;
				if(inq[v])continue;
				inq[v]=1,c[v]++;
				if(c[v]==n+1)return 0;
				q.push(v);
			}
		}
	}
	return 1;
}
#define addedge _
int G[205][205];
void _(int u,int v,int w){G[u][v]=w;}
signed main()
{
	int n=read(),m=read();
	memset(G,0x3f,sizeof(G));
	for(int i=1;i<=n;i++)G[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read(),w=read();
		// addedge(y,x,w);
		if(w)addedge(x,y,1),addedge(y,x,-1);
		else addedge(y,x,1),addedge(x,y,1);
	}
	rg_(k,n)rg(n)rg_(j,n)if(G[i][k]+G[k][j]<G[i][j])
	{
		if((G[i][k]+G[k][j]+G[i][j]&1)&&G[i][j]<=0x1f3f3f3f)return puts("NO"),0;
		G[i][j]=G[i][k]+G[k][j];
	}gr gr gr
	rg(n)if(G[i][i]<0)return puts("NO"),0;gr
	int ans=-1,pos=0,M=0;
	rg(n)
	int maxn=0,minn=n+1;
	rg_(j,n)maxn=max(maxn,G[i][j]),minn=min(minn,G[i][j]);gr
	maxn=maxn-minn;
	if(ans<maxn)ans=maxn,pos=i,M=minn;
	gr
	puts("YES");
	odl(ans);rg(n)odb(G[pos][i]-M);gr
	// if(!stO_zhoukangyang_Orz_zaky_txdy_orzorzorztql(0,n))printf("NO");
	// else for(int i=1;i<=n;i++)printf("%lld ",dis[i]);
	// puts("");
}