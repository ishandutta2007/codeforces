// Problem: C. Break Up
// Contest: Codeforces - Codeforces Round #364 (Div. 1)
// URL: https://codeforces.com/problemset/problem/700/C
// Memory Limit: 256 MB
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
#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[n*n+5];\
typedef int arr[n+5];\
arr h;\
int cnt=2;\
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
#define ms0(x) memset(x,0,sizeof(x))

newe(1005);
arr qv,cur,d;
// struct Edge{
	// int v,nxt;
// }e[1000005];
// int h[200005],cnt=1,c=0;
// void addedge(int u,int v)
// {
	// e[cnt]=(Edge){v,h[u]};
	// h[u]=cnt++;
// // }
// newe(200005);
int c=0;
int dfn[100005],low[100005],gb[100005],TT,As=1e18,nodecount;
void dfs(int u,int fa)
{
	dfn[u]=low[u]=++c;
	int qaq=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(!dfn[v])
		{
			dfs(v,i);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u])
			{
				gb[i]=1;
				if(dfn[TT]>=dfn[v])
				{
					// As=min(As,e[i].w-1e14);
					if(As>e[i].w-1e14)
					{
						As=e[i].w-1e14;
						nodecount=i>>1;
					}
					e[i].w=1e18;
					e[i^1].w=1e18;
				}
			}
		}
		if((i^fa)>1)low[u]=min(low[u],dfn[v]);
	}
}
void init()
{
	ms0(h);ms0(dfn);ms0(low);ms0(gb);
	cnt=1,c=0;
}
int bfs(int s,int t)
{
    memset(qv,0,sizeof(qv));
    memset(d,0,sizeof(d));
    memcpy(cur,h,sizeof(cur));
    std::queue<int>q;
    q.push(s);
    qv[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        fe(u)if(!qv[v]&&e[i].w)qv[v]=1,d[v]=d[u]+1,q.push(v);gr
    }
    return qv[t];
}
int dfs(int u,int t,int flow)
{
    if(u==t||flow==0)return flow;
    int res=0;
    for(int& i=cur[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(d[u]+1!=d[v]||e[i].w==0)continue;
        int g=dfs(v,t,min(flow,e[i].w));
        e[i].w-=g;
        e[i^1].w+=g;
        res+=g;
        flow-=g;
        if(flow==0)return res;
        // if(!g)return res;
    }
    if(res==0)cur[u]=0;
    return res;
}
signed main()
{
	int n=read(),m=read(),s=read(),t=read();TT=t;
	rg(m)int x=read(),y=read(),w=read();
	addedge(x,y,w+1e14);addedge(y,x,w+1e14);gr
	dfs(s,0);
	// oldl(As);
	// rg(n)if(!dfn[i])dfs(i,-1);gr
	int ans=-2e14;while(bfs(s,t))ans+=dfs(s,t,1e18);
	if(ans==-2e14)
	{
		puts("0\n0");
	}
	else if(ans>1e14&&As==1e18)
	{
		puts("-1");
	}
	else if(As<ans)
	{
		oldl(As);
		odl(1);
		oldl(nodecount);
	}
	else
	{
		oldl(ans);odl(2);
		rg_(u,n)fe(u)
		if(i&1)continue;
		if(qv[u]^qv[v])oldb(i>>1);
		gr gr
	}
	// oldl(ans);
	return 0;
}