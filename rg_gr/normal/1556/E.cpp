// Problem: E. Equilibrium
// Contest: Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1556/problem/E
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
int a[100005],b[100005],id[100005],l[100005],r[100005],ps[100005],lg[100005];
int maxn[25][100005];
int minn[25][100005];
inline int qmx(int x,int y)
{
	if(x>y)return 0;
	int l=lg[y-x+1];
	return max(maxn[l][x],maxn[l][y-(1<<l)+1]);
}
inline int qmn(int x,int y)
{
	if(x>y)return 0;
	int l=lg[y-x+1];
	return min(minn[l][x],minn[l][y-(1<<l)+1]);
}
signed main()
{
	int n=read(),m=read();
	lg[0]=-1;
	rg(n)lg[i]=lg[i>>1]+1;gr
	rg(n)a[i]-=read();gr
	rg(n)a[i]+=read();ps[i]=ps[i-1]+a[i];gr
	rg(n)maxn[0][i]=ps[i];gr
	rg_(j,20)rg(n-(1<<j)+1)maxn[j][i]=max(maxn[j-1][i],maxn[j-1][i+(1<<j-1)]);gr gr
	rg(n)minn[0][i]=ps[i];gr
	rg_(j,20)rg(n-(1<<j)+1)minn[j][i]=min(minn[j-1][i],minn[j-1][i+(1<<j-1)]);gr gr
// //	rg(n)odb(a[i]);gr puts("");
	// rg(n)if(a[i]>0)id[i]=1;else if(a[i])id[i]=-1;else id[i]=id[i-1];gr
	// int sum=0,pre=1;
	// rg(n)if(id[i]!=id[i-1])
	// {
		// for(int j=pre;j<i;j++)b[j]=sum>0?sum:-sum,l[j]=pre,r[j]=i-1;;
		// pre=i;sum=a[i];
	// }else{sum+=a[i];}gr
	// for(int j=pre;j<=n;j++)b[j]=sum>0?sum:-sum,l[j]=pre,r[j]=n;
	// rg(n)maxn[0][i]=b[i];gr
	// rg_(j,20)rg(n-(1<<j)+1)maxn[j][i]=max(maxn[j-1][i],maxn[j-1][i+(1<<j-1)]);gr gr
	rg(m)int L=read(),R=read();
	if(ps[R]-ps[L-1]){puts("-1");continue;}
	int minx=qmn(L,R);
	int maxx=qmx(L,R);
	if(minx<ps[L-1]){puts("-1");continue;}
	oldl(maxx-ps[L-1]);
	gr
}