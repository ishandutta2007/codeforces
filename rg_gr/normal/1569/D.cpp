// Problem: D. Inconvenient Pairs
// Contest: Codeforces - Educational Codeforces Round 113 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1569/problem/D
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
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <map>
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
#define newe(n) struct Edge{int v,w,nxt;}e[n*2+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}
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
int X[300005],Y[300005],x[300005],y[300005],xx[300005],yy[300005];
std::map<int,int> mpx[300005],mpy[300005];
int sumx[300005],sumy[300005];
signed main()
{
	int T=read();
	rg(T)int n=read(),m=read(),k=read();
	rg(n)X[i]=xx[i]=read();gr
	rg(m)Y[i]=yy[i]=read();gr
	rg(n)mpx[i].clear();sumx[i]=0;gr
	rg(m)mpy[i].clear();sumy[i]=0;gr
	int ans=0;
//	int dy=std::unique(yy+1,yy+1+m)-yy-1;
//	rg(m)Y[i]=std::lower_bound(yy+1,yy+1+dy,Y[i])-yy;gr
//	int dx=std::unique(xx+1,xx+1+n)-xx-1;
//	rg(n)x[i]=std::lower_bound(xx+1,xx+1+dx,x[i])-xx;gr
	rg(k)x[i]=read(),y[i]=read();
//	x[i]=std::lower_bound(xx+1,xx+1+dx,x[i])-xx;
//	y[i]=std::lower_bound(yy+1)
	//add place.
	int dx=std::lower_bound(X+1,X+1+n,x[i])-X;
	int dy=std::lower_bound(Y+1,Y+1+m,y[i])-Y;
//	odp(dx,dy);
	if(X[dx]==x[i]&&Y[dy]==y[i])continue;
	if(X[dx]!=x[i])
	{
//		puts("!");
		sumx[dx]++;
		mpx[dx][dy]++;
		ans+=(sumx[dx]-mpx[dx][dy]);
//		odp(sumx[dx],mpx[dx][dy]);
	}
	else
	{
//		puts("?");
		sumy[dy]++;
		mpy[dy][dx]++;
		ans+=(sumy[dy]-mpy[dy][dx]);
//		odp(sumy[dy],mpy[dy][dx]);
	}
//	puts("");
	gr
	oldl(ans);
	gr
	return 0;
}