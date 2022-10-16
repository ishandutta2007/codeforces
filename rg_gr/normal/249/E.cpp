// Problem: E. Endless Matrix
// Contest: Codeforces - Codeforces Round #152 (Div. 1)
// URL: https://codeforces.com/contest/249/problem/E
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
#define int __int128
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
const int mod=10000000000ll;
int s0(int x){return x;}
int s1(int x){x;return x*(x-1)/2;}
// int s2(int x){return (__int128)x*(x+1)/2*(x+x+1)/3;}
int s2(int x)
{
	//...
	int A=x,B=x+1,C=x+x+1;
	if(B%2)A>>=1;
	else B>>=1;
	if(A%3==0)A/=3;
	else if(B%3==0)B/=3;
	else C/=3;
	A;
	B;
	C;
	return A*B*C;
}
int q(int n,int m)
{
	if(n==0||m==0)return 0;
	if(n==m)return s1(n*n+1);
	if(n>m)
	{
		int ans=s1(m*m+1);
		int d=s2(n)-s2(m);
		ans+=d*m,ans;
		ans-=(n-m)*s1(m);
		ans;//if(ans<0)ans+=mod;
		return ans;
	}
	int ans=s1(n*n+1);
	// odl(ans);
	int d=s2(m-1)-s2(n-1);
	// odl(d);
	// odp(m-1,n-2);
	ans+=d*n,ans;
	ans+=(m-n)*s1(n+1);
	ans;//if(ans<0)ans+=mod;
	return ans;
	// return 0;
}
inline void wt(int x)
{
	if(x>9)wt(x/10);
	putchar(x%10+48);
}
void ret0(int x)
{
	if(x<=999999999)putchar(48);
	if(x<=99999999)putchar(48);
	if(x<=9999999)putchar(48);
	if(x<=999999)putchar(48);
	if(x<=99999)putchar(48);
	if(x<=9999)putchar(48);
	if(x<=999)putchar(48);
	if(x<=99)putchar(48);
	if(x<=9)putchar(48);
}
signed main()
{
	// odl(s1(4));
	// odl(q(2,3));
	int T=read();rg(T)
	int a=read(),b=read(),c=read(),d=read();
	int res=q(c,d)-q(a-1,d)-q(c,b-1)+q(a-1,b-1);
	// res+=mod*10;res;
	// wt(res);
	if(res>=10000000000ll)printf("..."),ret0(res%10000000000ll),wt(res%10000000000ll),puts("");
	else oldl((long long)res);
	gr
	return 0;
}