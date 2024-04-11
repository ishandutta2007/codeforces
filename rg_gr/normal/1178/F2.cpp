// Problem: F2. Short Colorful Strip
// Contest: Codeforces - Codeforces Global Round 4
// URL: https://codeforces.com/problemset/problem/1178/F2
// Memory Limit: 256 MB
// Time Limit: 998244353 ms
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
int minn[505][505],dp[505][505];
int a[1000005];
const int mod=998244353;
int solve(int *a,int n)
{
	rg(n)int pos=i;minn[i][i]=i;for(int j=i+1;j<=n;j++)
	{
		if(a[j]<a[pos])pos=j;
		minn[i][j]=pos;
	}gr
	int ans=0;
	rg(n)rg_(j,i)dp[j][i]=0;gr gr
	rg(n)dp[i][i]=dp[i][i-1]=1;gr
	dp[n+1][n]=1;
	dp[0][0]=1;
	rg_(L,n)for(int i=1,j=L;j<=n;i++,j++)
	{
		//calc
		int p=minn[i][j];
		int lans=0,rans=0;
		// sum l [i-1,p-1] dp[i][l]*dp[l+1][p-1]
		for(int l=i-1;l<=p-1;l++)lans=(lans+dp[i][l]*dp[l+1][p-1])%mod;
		for(int r=p+1;r<=j+1;r++)rans=(rans+dp[p+1][r-1]*dp[r][j])%mod;
		dp[i][j]=lans*rans%mod;
	}gr
	// rg(n)rg_(j,n)odb(dp[i][j]);gr puts("");gr
	return dp[1][n];
}
int fst[505],lst[505],test[1000005],nxt[1000005],dddd[1000005];
int tmp[505];
int getans(int l,int r)
{
	if(l>=r)return 1;
	int res=1;
	int pos=l;
	while(pos<=r)
	{
		// res=res*getans(pos+1,lst[a[pos]]-1)%mod;
		int t=pos;
		while(nxt[t])res=res*getans(t+1,nxt[t]-1)%mod,t=nxt[t];
		pos=lst[a[pos]]+1;
	}
	int L=0;
	pos=l;
	while(pos<=r)
	{
		tmp[++L]=a[pos];
		pos=lst[a[pos]]+1;
	}
	return res*solve(tmp,L)%mod;
}
#define O {puts("0");return 0;}
signed main()
{
	int n=read(),m=read();
	rg(m)a[i]=read();gr
	rg(m)lst[a[i]]=i;gr
	for(int i=m;i>=1;i--)fst[a[i]]=i;
	for(int i=m;i>=1;i--)nxt[i]=dddd[a[i]],dddd[a[i]]=i;
	rg(n)
	int l=fst[i],r=lst[i];
	for(int t=l;t<=r;t++)if(a[t]<i)O
	gr
	odl(getans(1,m));
	return 0;
}