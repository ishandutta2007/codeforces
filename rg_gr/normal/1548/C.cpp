// Problem: C. The Three Little Pigs
// Contest: Codeforces - Codeforces Round #736 (Div. 1)
// URL: https://codeforces.com/contest/1548/problem/C
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//  /

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
int fac[3000005],inv[3000005],pinv[3000005];
const int mod=1000000007;
inline int C(int n,int m)
{
	if(n<m)return 0;
	if(m==0||n==m)return 1;
	return fac[n]*pinv[m]%mod*pinv[n-m]%mod;
}
int dp[3000005][3];
signed main()
{
	fac[0]=inv[1]=inv[0]=1;
	rg(3000003)fac[i]=fac[i-1]*i%mod;gr
	rg(3000003)if(i!=1)inv[i]=(mod-mod/i)*inv[mod%i]%mod;gr
	pinv[0]=1;
	rg(3000003)pinv[i]=inv[i]*pinv[i-1]%mod;gr
	int n=read(),m=read();
	dp[1][0]=n*(mod/2+1)%mod*(n+n+n-1)%mod;
	dp[1][1]=n*(mod/2+1)%mod*(n+n+n+1)%mod;
	dp[1][2]=n*(mod/2+1)%mod*(n+n+n+3)%mod;
	rg(n*3)if(i==1)continue;
	dp[i][0]=(fac[n+n+n+1]*pinv[n+n+n-i]%mod*inv[i+1]%mod+mod+mod+mod-((i+i)*dp[i-1][0]%mod)-i*dp[i-1][1]%mod)%mod;
	dp[i][0]=dp[i][0]*inv[3]%mod;
	dp[i][1]=(dp[i][0]+i*dp[i-1][0])%mod;
	dp[i][2]=(dp[i][1]+i*dp[i-1][1])%mod;
	gr
	rg(m)int x=read();
	oldl(dp[x][2]*pinv[x]%mod);gr
	return 0;
}