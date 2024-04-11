// Problem: G. Common Divisor Graph
// Contest: Codeforces - Harbour.Space Scholarship Contest 2021-2022 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1553/problem/G
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
//#define int long long
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
mgs
// const int MAXN = 3e5, MAXM = 3e5;
// const int FULL5 = (1 << 5) - 1;
// const int FULL6 = (1 << 6) - 1;
//  
// int b1[MAXN + 5][MAXN / (1 << 11) + 5], cnt_b1;
// unsigned long long b2[MAXM + 5][FULL5 + 1];
// void add_edge(int u, int v) {
	// if (!b1[u][v >> 11]) b1[u][v >> 11] = ++cnt_b1;
	// b2[b1[u][v >> 11]][(v >> 6) & FULL5] |= 1ull << (v & FULL6);
// }
// void add__edge(int u, int v) {
	// add_edge(u,v);
	// add_edge(v,u);
// }
// int D=0,Q=0;
// bool have_edge(int u, int v) {
	// // D++;Q+=2;
	// // assert(D<=MAXN&&Q<=MAXM);
	// if (!b1[u][v >> 11]) return false;
	// return b2[b1[u][v >> 11]][(v >> 6) & FULL5] & (1ull << (v & FULL6));
// }
#include <unordered_map>
std::unordered_map<long long,int>dd;
void add__edge(int u,int v)
{
	// printf("?  ");odp(u,v);
	if(u>v)u^=v^=u^=v;
	dd[u*300000ll+v]=1;
}
int have_edge(int u,int v)
{
	if(u>v)u^=v^=u^=v;
	return dd.count(u*300000ll+v);
}
typedef int arr[1000005];
int qwq[1000005][8];
arr prime,isprime,id,a,Id,iD,szz;
signed main()
{
	int cnt=0;
	isprime[1]=1;
	rg(1000001)
	if(isprime[i]==1)continue;
	prime[++cnt]=i;id[i]=cnt;
	for(int j=i+i;j<=1000001;j+=i)isprime[j]=1;gr
	int n=read(),m=read();
	rg(n+cnt)fa[i]=i,sz[i]=1;gr
	rg(n)a[i]=read();int t=a[i];
	int *G=qwq[i];
	int &cc=szz[i];
	;rg_(j,cnt)if(prime[j]>1000)break;
	if(t%prime[j])continue;
	// odp(1+a[i],prime[j]);
	// add__edge(iD[fa[i]],iD[fa[j]]);
	while(t%prime[j]==0)t/=prime[j];
	G[++cc]=j;
	gr
	if(t>1)G[++cc]=id[t];
	// odb(cc);rg(cc)odb(G[i]);gr puts("");
	Id[i]=G[1];
	rg(cc)rg_(j,i-1)uf(G[i],G[j]);gr gr gr
	// rg(n)odb(Id[i]);gr puts("");
	int g=0;
	rg(n+cnt)f(i);gr
	// rg(n+cnt)if(fa[i]==i)++g,iD[i]=g;gr
	rg(n+cnt)iD[i]=i;gr
	rg(n)
	int G[8],cc=0;
	int t=a[i]+1;rg_(j,cnt)if(prime[j]>1000)break;
	if(t%prime[j])continue;
	// odp(1+a[i],prime[j]);
	// add__edge(iD[fa[i]],iD[fa[j]]);
	while(t%prime[j]==0)t/=prime[j];
	G[++cc]=j;
	gr
	if(t>1)G[++cc]=id[t];
	rg(cc)rg_(j,i-1)add__edge(iD[fa[G[i]]],iD[fa[G[j]]]);gr gr
	rg_(j,cc)rg_(k,szz[i])add__edge(fa[qwq[i][k]],fa[G[j]]);gr gr
	gr
	assert(g<=300000);
	rg(m)int x=read(),y=read();
	if(fa[Id[x]]==fa[Id[y]])puts("0");
	else if(have_edge(iD[fa[Id[x]]],iD[fa[Id[y]]]))puts("1");
	else puts("2");
	gr
	return 0;
}