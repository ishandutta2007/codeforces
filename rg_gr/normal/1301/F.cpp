// Problem: CF1301F Super Jaber
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1301F
// Memory Limit: 250 MB
// Time Limit: 5000 ms
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
//#define int long long
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
//#include <stdarg.h>
inline int min(int a,int b,int c,int d,int e)
{
	return min(a,min(b,min(c,min(d,e))));
}
inline int max(int a,int b){return a<b?b:a;}
int a[1005][1005],G[45][1005][1005],col[45][45];
newe(2000005);
inline void buildGraph(int v,int n,int m)
{
	memset(G[v],0x3f,sizeof(G[v]));
	std::queue<int>q;
	rg(n)rg_(j,m)if(a[i][j]==v)G[v][i][j]=0,q.push(i*m+j);gr gr
	while(!q.empty())
	{
		int s=q.front();q.pop();
		int j=s%m,i=s/m;
		if(j==0)j=m,i--;
		if(col[v][a[i][j]]==0&&G[v][i][j])
		{
			rg_(I,n)rg_(J,m)if(a[I][J]==a[i][j]&&(i!=I||j!=J)&&G[v][I][J]==0x3f3f3f3f)G[v][I][J]=G[v][i][j]+1,q.push(I*m+J);gr gr
			col[v][a[i][j]]=1;
		}
		if(i<n&&G[v][i+1][j]==0x3f3f3f3f)G[v][i+1][j]=G[v][i][j]+1,q.push((i+1)*m+j);
		if(i>1&&G[v][i-1][j]==0x3f3f3f3f)G[v][i-1][j]=G[v][i][j]+1,q.push((i-1)*m+j);
		if(j<m&&G[v][i][j+1]==0x3f3f3f3f)G[v][i][j+1]=G[v][i][j]+1,q.push((i)*m+j+1);
		if(j>1&&G[v][i][j-1]==0x3f3f3f3f)G[v][i][j-1]=G[v][i][j]+1,q.push((i)*m+j-1);
	}
}
#define dp G
signed main()
{
	int n=read(),m=read(),k=read();
	rg(n)rg_(j,m)a[i][j]=read();gr gr
	rg(k)buildGraph(i,n,m);
//	rg_(k,n)rg_(j,m)odb(G[i][k][j]);gr puts("");gr puts("");
	gr
	int q=read();
	rg(q)int r1=read(),c1=read(),r2=read(),c2=read();
	if(r1==r2&&c1==c2){puts("0");continue;}
	if(a[r1][c1]==a[r2][c2]){puts("1");continue;}
	int ans=(r2>r1?r2-r1:r1-r2)+(c2>c1?c2-c1:c1-c2);
	rg(k)ans=min(ans,G[i][r1][c1]+G[i][r2][c2]+1);gr
	odl(ans);
	gr
	return 0;
}