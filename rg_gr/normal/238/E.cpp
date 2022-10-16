// Problem: E. Meeting Her
// Contest: Codeforces - Codeforces Round #148 (Div. 1)
// URL: https://codeforces.com/problemset/problem/238/E
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
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#define newe(n) struct Edge{int v,w,nxt;}e[n*n*2+5];\
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
    while(c<48||c>49)c=getchar();
    return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
newe(101);
arr a,maxn,samp,dis,S,T;
arr D0,D1,V;
int G[2][106][106];

int n=read(),m=read(),s=read(),t=read();
void dfs(int u,int *d,int ss)
{
	// memset(V,0,sizeof(V));
	// odl(u);
	if(G[ss][u][0]==1)
	{
		memcpy(d,G[ss][u],sizeof(a));
		return;
	}
	memset(d,0x3f,sizeof(a));
	d[u]=0;std::queue<int>q;//V[u]=1;
	q.push(u);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		// odl(u);
		fe(u)if(e[i].w!=ss)continue;
		if(d[v]==0x3f3f3f3f)d[v]=d[u]+1,q.push(v);//V[v]=1;
		gr
	}
	memcpy(G[ss][u],d,sizeof(a));
	G[ss][u][0]=1;
}
arr tmp;
#include <vector>
std::vector<int>H[105];
signed main()
{
	memset(dis,0x3f,sizeof(dis));
	rg(m)
	int u=read(),v=read();
	addedge(u,v,1);
	addedge(v,u,0);gr
	dis[t]=0;
	int q=read();
	rg(q)S[q-i+1]=read(),T[q-i+1]=read();gr
	rg_(Q,q)
	rg(q)int s=S[i],t=T[i];
	dfs(s,D0,1);
	dfs(t,D1,0);
	rrg(1+n)samp[i]=maxn[i]=a[i]=0;
	int dist=D0[t];
	if(dist==0x3f3f3f3f)continue;
	// printf(": %d %d\n",s,t);
	// rg(n)odp(D0[i],D1[i]);gr puts("");
	// continue;
	memset(tmp,0x3f,sizeof(tmp));
	rrg(n+1)H[i].clear();
	rg(n)
	if(D0[i]+D1[i]==dist)
	{
		a[D0[i]]++;
		samp[D0[i]]=i;
		// maxn[D0[i]]=max(maxn[D0[i]],dis[i]);
		tmp[i]=dis[i];
		H[D0[i]].push_back(i);
	}
	gr
	for(int i=dist-1;i>=0;i--)
	{
		for(auto u:H[i])
		{
			int d=0x3f3f3f3f+1;int I=i;
			fe(u)if(D0[v]!=I+1||D0[v]+D1[v]!=dist)continue;if(d==0x3f3f3f3f+1)d=tmp[v];else d=max(tmp[v],d);gr
			tmp[u]=min(tmp[u],d);
			// fe(u)tmp[u]=min(tmp[u],tmp[v]);gr
			maxn[D0[u]]=max(maxn[D0[u]],tmp[u]);
		}
	}
	// rg(n)odb(tmp[i]);gr puts("");
	// continue;
	// for(int i=dist-1;i>=1;i--)maxn[i]=min(maxn[i],maxn[i+1]);
	rg(n)
	if(D0[i]+D1[i]==dist&&a[D0[i]]==1)
	{
		// odl(i);
		// if(D0[i]!=dist)dis[i]=min(dis[i],maxn[D0[i]+1]+1);
		if(D0[i]!=dist)dis[i]=min(dis[i],tmp[i]+1);
		// for(int j=D0[i]+1;j<=dist;j++)
		// {
			// dis[i]=min(dis[i],maxn[j]+1);
			// odp(i,maxn[j]);
		// }
	}
	gr
	// rg(n)odb(dis[i]==0x3f3f3f3f?-1:dis[i]);gr puts("");
	// ol("");
	gr
	
	gr
	// hehezhou()
	if(dis[s]==0x3f3f3f3f)print(-1);
	else print(dis[s]);
	return 0;
}