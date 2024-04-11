// Problem: B. Mathematics Curriculum
// Contest: Codeforces - Codeforces Round #745 (Div. 1)
// URL: https://codeforces.com/contest/1580/problem/B
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
int dp[105][105][105],C[105][105],fac[105];
int n=read(),m=read(),k=read(),mod=read();
int solve(int c,int d,int x)
{
//	printf("%lld %lld %lld\n",c,d,x);fflush(stdout);
	if(dp[c][d][x]!=-1)return dp[c][d][x];
	if(c==0)return x==0?1:0;
	if(d==1)return x==1?fac[c]:0;
	if(x&&x+x-1>c)return 0;
	dp[c][d][x]=0;
	// if(d==m)
	// {
		// if(x!=1)return 0;
		// for(int i=0;i<c;i++)dp[c][d][x]=(dp[c][d][x]+solve(i,d+1,0)*solve(c-i-1,d+1,0))%mod;
		// printf("dp[%d][%d][%d]=%d\n",c,d,x,dp[c][d][x]);
		// return dp[c][d][x];
	// }
	for(int L=0;L<c;L++)
		for(int k=0;k<=x;k++)
			dp[c][d][x]=(dp[c][d][x]+solve(L,d-1,k)*solve(c-L-1,d-1,x-k)%mod*C[c-1][L])%mod;
//	printf("dp[%d][%d][%d]=%d\n",c,d,x,dp[c][d][x]);
	return dp[c][d][x];	
}
signed main()
{
	memset(dp,-1,sizeof(dp));
	#define c C
//	c[0][0]=1;l
fac[0]=1;
	rg(n)c[i][0]=c[i][i]=1;gr c[0][0]=1;
	rg(n)fac[i]=fac[i-1]*i%mod;gr
	rg(n)rg_(j,i-1)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;gr gr
//	oldl(solve(1,1,1));
	oldl(solve(n,m,k));
//oldl(solve(4,3,2));
	return 0;
}