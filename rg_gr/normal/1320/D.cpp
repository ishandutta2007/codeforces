// Problem: D. Reachable Strings
// Contest: Codeforces - Codeforces Round #625 (Div. 1, based on Technocup 2020 Final Round)
// URL: https://codeforces.com/contest/1320/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
int a[200005],b[2][200005],pr[200005],nxt[200005],g[200005],pre[2][200005],p73[200005],id[200005];
const int base=73,mod=989244353;
int hsh(int x,int l,int r)
{
	return (b[x][r]-b[x][l-1]*p73[r-l+1]%mod+mod)%mod;
}
signed main()
{
	int n=read();
	rg(n)a[i]=re1d();gr
	p73[0]=1;rg(n)p73[i]=p73[i-1]*73%mod;gr
	int cc=0;
	rg(n)pre[0][i]=pre[0][i-1],pre[1][i]=pre[1][i-1],pre[a[i]][i]++;gr
	rg(n)if(a[i]==0)g[++cc]=i;gr
	g[++cc]=n+1;
	rg(cc)for(int j=g[i-1]+1;j<=g[i];j++)nxt[j]=g[i];gr
	rg(cc)for(int j=g[i];j<=g[i+1]-1;j++)pr[j]=g[i];gr
	cc--;
	rg(cc)b[0][i]=g[i]&1,b[1][i]=(g[i]^1)&1;gr
	// rg(cc)odp(b[0][i],b[1][i]);gr
	rg(cc)b[0][i]=(b[0][i-1]*base+b[0][i]+7)%mod;gr
	rg(cc)b[1][i]=(b[1][i-1]*base+b[1][i]+7)%mod;gr
	// rg(cc)odp(b[0][i],b[1][i]);gr
	// rg(n)
	rg(n)id[g[i]]=i;gr
	int q=read();
	rg(q)int l=read(),L=read(),d=read();
	int r=l+d-1,R=L+d-1;
	if(pre[1][r]-pre[1][l-1]!=pre[1][R]-pre[1][L-1]){puts("No");continue;}
	if(pre[0][r]-pre[0][l-1]==0){puts("Yes");continue;}
	if(nxt[l]+l+nxt[L]+L&1){puts("No");continue;}
	int lb=nxt[l],rb=pr[r],Lb=nxt[L],Rb=pr[R];
	lb=id[lb];
	Lb=id[Lb];
	rb=id[rb];
	Rb=id[Rb];
	// printf("%d %d %d %d\n",lb,rb,Lb,Rb);
	int f;
	if(l+L&1)f=hsh(0,lb,rb)==hsh(1,Lb,Rb);
	else f=hsh(1,lb,rb)==hsh(1,Lb,Rb);
	if(f)puts("Yes");else puts("No");
	gr
	return 0;
}