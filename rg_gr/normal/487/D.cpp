// Problem: D. Conveyor Belts
// Contest: Codeforces - Codeforces Round #278 (Div. 1)
// URL: https://codeforces.com/problemset/problem/487/D
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
//#define int long long
#ifdef int 
#define inf 0x3f3f3f3f3f3f3f3fll
#else 
#define inf 0x3f3f3f3f
#endif
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
#define L 0
#define R 1
#define U 2
inline int re1d()
{
    char c=getchar();
    while(c!='<'&&c!='>'&&c!='^')c=getchar();
    return c=='<'?L:(c=='>'?R:U);
}
inline int re1p()
{
    char c=getchar();
    while(c!='A'&&c!='B'&&c!='C')c=getchar();
    return c=='C';
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int a[100005][15],endl[100005][15];
int x[100005][15],y[100005][15];
const int B=200;
int n=read(),m=read(),q=read();
void workline(int u)
{
	rg(m)endl[u][i]=-1;gr
	for(int i=0;i<=m+1;i++)
	{
		if(a[u][i]==U||i==0||i==m+1)
		{
			endl[u][i]=i;
			for(int j=i+1;j<=m&&a[u][j]==L;j++)endl[u][j]=i;
			for(int j=i-1;j>=1&&a[u][j]==R;j--)endl[u][j]=i;
		}
	}
	// rg(m)odb(endl[u][i]);gr puts("..");
}
int l[100005],r[100005],bel[100005];
void build(int u)
{
	for(int i=l[u];i<=r[u];i++)
	{
		if(i==l[u])
		{
			rg_(j,m)
			if(endl[i][j]!=-1)x[i][j]=i,y[i][j]=endl[i][j];
			else x[i][j]=-1,y[i][j]=-1;
			gr
		}
		else
		{
			rg_(j,m)
			if(endl[i][j]==0||endl[i][j]==m+1)x[i][j]=i,y[i][j]=endl[i][j];
			else if(endl[i][j]!=-1)x[i][j]=x[i-1][endl[i][j]],y[i][j]=y[i-1][endl[i][j]];
			else x[i][j]=-1,y[i][j]=-1;
			gr
		}
	}
}
signed main()
{
	rg(n)rg_(j,m)
	a[i][j]=re1d();
	gr gr
	rg(n)workline(i);gr
	int T=n/B+(!!(n%B));
	for(int i=1;i<=T;i++)
	{
		l[i]=(i-1)*B+1,r[i]=min(i*B,n);
		for(int j=l[i];j<=r[i];j++)bel[j]=i;
	}
	rg_(u,T)build(u);gr
	rg(q)
	if(re1p())
	{
		int x=read(),y=read(),c=re1d();
		a[x][y]=c;
		workline(x);
		// rg(m)odb(endl[x][i]);gr puts("..");
		build(bel[x]);
	}
	else
	{
		int xc=read(),yc=read();
		while(1)
		{
			int X=x[xc][yc],Y=y[xc][yc];
			xc=X,yc=Y;
			if(xc==-1||yc==-1)
			{
				puts("-1 -1");
				break;
			}
			if(xc==0||yc==0||yc==m+1)
			{
				odp(xc,yc);
				break;
			}
			xc--;
			
			if(xc==0||yc==0||yc==m+1)
			{
				odp(xc,yc);
				break;
			}
		}
	}
	gr
	return 0;
}