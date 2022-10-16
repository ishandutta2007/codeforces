// Problem: F. Uniformly Branched Trees
// Contest: Codeforces - Intel Code Challenge Final Round (Div. 1 + Div. 2, Combined)
// URL: https://codeforces.com/contest/724/problem/F
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
int dp[1005][1005][15],d2[1005][1005][15];
int C[1005][1005],inv[103],mod;
int Cc(int n,int m)
{
	int ans=1;
	rg(m)ans=ans*(n-i+1)%mod*inv[i]%mod;gr
	return ans;
}
signed main()
{
	int n=read(),d=read();mod=read();
	inv[0]=inv[1]=1;
	for(int i=2;i<=d;i++)inv[i]=(inv[mod%i]*(mod-mod/i))%mod;
	C[0][0]=1;
	rg(n)C[i][i]=C[i][0]=1;gr
	rg(n)rg_(j,i-1)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;gr gr
	if(n<3)return puts("1")&0;
	// k(d-1) = n-2
	if((n-2)%(d-1))return puts("0"),0;
	// odl(Cc(5,2));
	// n=(n-2)/(d-1);
	dp[1][0][0]=1;rg(n)dp[1][i][0]=1;gr
	rg(n)if(i==1)
	{
		dp[1][0][d-1]=1;
		continue;
	}
	for(int D=1;D<=d&&D<i;D++)
	{	
		for(int sz=1;sz<=n;sz++)
		{
			dp[i][sz][D]=dp[i][sz-1][D];
			for(int u=1;u<=D&&u*sz<=i;u++)
				dp[i][sz][D]=(dp[i][sz][D]+dp[i-u*sz][sz-1][D-u]*Cc(dp[sz][sz-1][d-1]+u-1,u))%mod;
		}
	}
	gr
	int ans=dp[n][n>>1][d];
	if(n&1);
	else ans=(ans+mod-Cc(dp[n>>1][n-2>>1][d-1],2))%mod;
	oldl(ans);
	return 0;
}