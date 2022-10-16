// Problem: D1. Beautiful Bracket Sequence (easy version)
// Contest: Codeforces - Codeforces Round #604 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1264/D1
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
#define rG(x) for(int i=x;i>=(1);i--){
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
const int mod=998244353;
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
    while(c!='('&&c!=')'&&c!='?')c=getchar();
    return c=='?'?2:c==')';
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int f[3][1000005],a[1000005];
int fac[2000005],inv[2000005];
// int pre[2005][2005],suf[2005][2005],h[2005][2005],g[2005][2005],pr[2005][2005],sf[2005][2005];
// int c[2005][2005];
int _(int m,int n)
{
	if(n<m||m<0)return 0;
	if(n==m||m==0)return 1;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
char t[1000005];
signed main()
{
	scanf("%s",t+1);int n=strlen(t+1);rg(n)if(t[i]=='(')a[i]=0;else if(t[i]==')')a[i]=1;else a[i]=2;gr
	fac[0]=inv[0]=inv[1]=1;rg(n+n)fac[i]=fac[i-1]*i%mod;if(i>1)inv[i]=inv[mod%i]*(mod-mod/i)%mod;gr
	rg(n+n)inv[i]=inv[i-1]*inv[i]%mod;gr
	rg(n)f[0][i]=f[0][i-1],f[1][i]=f[1][i-1],f[2][i]=f[2][i-1],f[a[i]][i]++;gr
	int ans=0;
	rg(n-1)
	int A=f[0][i],B=f[2][i],C=f[1][n]-f[1][i],D=f[2][n]-f[2][i];
	ans+=A*_(C+D-A,B+D)+B*_(C+D-A-1,B+D-1);
	ans%=mod;
	gr
	// rg(n)printf("? %d %d %d\n",f[0][i],f[1][i],f[2][i]);gr
	// rg(n)rg_(j,n)pre[i][j]=(pre[i-1][j]+(pr[i][j]=a[i]!=10?C(j-f[0][i-1]-1,f[2][i-1]):0))%mod;gr gr
	// printf("%d %d\n",2-f[0][3],f[2][3]);
	// rG(n)rg_(j,n)suf[i][j]=(suf[i+1][j]+(sf[i][j]=a[i]!=10?C(j-(f[1][n]-f[1][i])-1,f[2][n]-f[2][i]):0))%mod;gr gr
	// rg(n)rg_(j,n)pre[i][j]=(pre[i-1][j]+(pr[i][j]=a[i]!=10?C(j-f[0][i],f[2][i]):0))%mod;gr gr
	// rG(n)rg_(j,n)suf[i][j]=(suf[i+1][j]+(sf[i][j]=a[i]!=10?C(j-(f[1][n]-f[1][i-1]),f[2][n]-f[2][i-1]):0))%mod;gr gr
	//brute
	// rg(n)rg_(j,n)odb(pr[i][j]);gr puts("");gr puts("");
	// rg(n)rg_(j,n)odb(sf[i][j]);gr puts("");gr puts("");
	
	// int ans=0,pos=1;
	// rg_(k,n)
	
	// rg(n)for(int j=i+1;j<=i+1;j++)if(f[1][j-1]-f[1][i]==0&&pr[i][k]&&sf[j][k])ans=(ans+k*pr[i][k]%mod*sf[j][k])%mod;gr
	// rg(n)for(int j=i+2;j<=i+2;j++)if(f[0][j-1]-f[0][i]==0&&pr[i][k]&&sf[j][k])ans=(ans+k*pr[i][k]%mod*sf[j][k])%mod;gr
	// debug(ans,'\n');
	// gr
	
	odl(ans);
	return 0;
	return 0;
}