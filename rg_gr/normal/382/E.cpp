// Problem: E. Ksenia and Combinatorics
// Contest: Codeforces - Codeforces Round #224 (Div. 2)
// URL: https://codeforces.com/problemset/problem/382/E
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
#define rg__(i,x) for(int i=0;i<=(x);i++){
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
inline int re1d()
{
    char c=getchar();
    while(c<48||c>49)c=getchar();
    return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int g[55][55],f[55][55],C[55][55];
const int mod=1000000007;
signed main()
{
	g[0][0]=1;C[0][0]=1;
	int n=read(),m=read();
	rg(n)C[i][i]=C[i][0]=1;gr
	rg(n)rg_(j,i-1)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;gr gr
	f[1][0]=1;
	rg(n)if(i==1)continue;
	rg__(j,i-1)
	int k=i-j-1;
	if(j>k)break;
	rg__(l,j)rg__(p,k)
	if(j==k&&l<p)break;
	g[i][l+p+1]=(g[i][l+p+1]+(i==n?C[i-1][j]:C[i][j]*(k+1))%mod*f[j][l]%mod*f[k][p]%mod*(j==k&&p==l?(mod+1)/2:1))%mod;
	g[i][l+p+1]=(g[i][l+p+1]+(i==n?C[i-1][j]:C[i][j]*(k+1))%mod*g[j][l]%mod*f[k][p]%mod*(j==k&&p==l?(mod+1)/2:1))%mod;
	g[i][l+p+1]=(g[i][l+p+1]+(i==n?C[i-1][j]:C[i][j]*(k+1))%mod*f[j][l]%mod*g[k][p]%mod*(j==k&&p==l?(mod+1)/2:1))%mod;
	// if(C[i][j]*g[j][l]%mod*g[k][p])printf("%d %d : %d %d %d %d\n",i,l+p,j,k,l,p);
	f[i][l+p]=(f[i][l+p]+(i==n?C[i-1][j]:C[i][j]*(k+1))%mod*g[j][l]%mod*g[k][p]%mod*(j==k&&p==l?(mod+1)/2:1))%mod;
	gr gr gr 
	// rg__(j,i)f[i][j]=f[i][j]*(mod+1)/2%mod,
	// g[i][j]=g[i][j]*(mod+1)/2%mod;gr
	gr
	// odp(f[n][m],g[n][m]);
	// rg(n)rg_(j,i)printf("(%d %d) ",f[i][j],g[i][j]);gr puts("");gr
	int ans=f[n][m]+g[n][m];
	oldl(ans%mod);
	return 0;
}