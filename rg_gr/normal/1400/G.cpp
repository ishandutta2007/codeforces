// Problem: D. Dominoes
// Contest: Codeforces - Codeforces Round #758 (Div.1 + Div. 2)
// URL: https://codeforces.com/contest/1608/problem/D
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
// #define DEBUG
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
    while(c!='?'&&c!='B'&&c!='W')c=getchar();
    return c=='W'?2:c=='B';
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int l[400005],r[400005],fac[400005],inv[400005];
int C(int n,int m)
{
	if(n<m||m<0)return 0;
	if(n==m||m==0)return 1;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int t[400005],x[22],y[22],ans[400005][44];
signed main()
{
	int n=read(),m=read();
	fac[0]=inv[0]=inv[1]=1;
	rg(400000)fac[i]=fac[i-1]*i%mod;if(i>1)inv[i]=inv[mod%i]*(mod-mod/i)%mod;gr
	rg(400000)inv[i]=inv[i]*inv[i-1]%mod;gr
	rg(n)l[i]=read(),r[i]=read();t[l[i]]++,t[r[i]+1]--;gr
	rg(n)t[i]+=t[i-1];gr
	// rg(n)odb(t[i]);gr puts("");
	rg(n)rg__(j,40)ans[i][j]=(C(t[i]-j,i-j)+ans[i-1][j])%mod;gr gr
	// rg__(j,40)rg(n)odb(ans[i][j]);gr puts("");gr
	rg(m)x[i]=read(),y[i]=read();gr
	int anss=ans[n][0];
	rg_(S,(1<<m)-1)
	int t[44]={},cc=0;
	rg(m)if((S>>i-1)&1)t[++cc]=x[i],t[++cc]=y[i];gr
	std::sort(t+1,t+1+cc);cc=std::unique(t+1,t+1+cc)-t-1;
	int L=1,R=n;
	rg(cc)L=max(L,l[t[i]]),R=min(R,r[t[i]]);gr
	if(L>R)continue;
	// printf("%d %d %d\n",L,R,cc);
	int k=ans[R][cc]+mod-ans[L-1][cc];k%=mod;
	if(__builtin_popcount(S)&1)anss=(anss+mod-k)%mod;
	else anss=(anss+k)%mod;
	gr
	oldl(anss);
	return 0;
}