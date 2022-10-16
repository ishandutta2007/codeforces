// Problem: E. Product Sum
// Contest: Codeforces - Codeforces Round #344 (Div. 2)
// URL: https://codeforces.com/contest/631/problem/E
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
int a[1000005],f[1000005],q[1000005],head,tail,id[1000005];
double slope(int x,int y)
{
	return 1.0*(f[x]-f[y])/(id[x]-id[y]);
}
signed main()
{
	int n=read();
	rg(n)a[i]=read();gr
	rg(n)id[i]=i;gr
	id[0]=n+1;
	rg(n)f[i+1]=f[i]+a[i];gr
	int g=0;
	f[0]=1e18;
	rg(n)g+=a[i]*i;gr
	int ans=0;
	head=tail=1;q[head]=n+1;
	f[n+1]=1e18;
	id[n+1]=0;
	q[++tail]=1;
	// odl(g);
	rg(n)if(i==1)continue;
	int t=0;
	int l=head,r=tail,as=head;
	while(l<=r)
	{
		int m=l+r>>1;
		if(a[i]<=slope(q[m],q[m+1]))as=m,r=m-1;
		else l=m+1;
	}
	as=q[as];
	t=a[i]*as-f[as];
	// oldp(as,t);
	while(tail>head&&slope(q[tail-1],q[tail])>slope(q[tail],i))tail--;
	q[++tail]=i;
	// rg_(j,i-1)t=max(t,a[i]*j-f[j]);gr
	// while
	t+=f[i]-a[i]*i;
	ans=max(t,ans);
	gr
	
	int R1=(g+ans);
	
	std::reverse(a+1,a+1+n);
	rg(n)f[i+1]=f[i]+a[i];gr
	memset(q,0,sizeof(q));
	head=tail=1;
	q[tail]=n+1;
	q[++tail]=1;
	f[n+1]=-1e18;
	f[0]=-1e18;
	ans=g=0;
	rg(n)ans+=(n-i+1)*a[i];gr
	// odl(ans);
	rg(n)if(i==1)continue;
	int t=0;
	int l=head,r=tail,as=head;
	while(l<=r)
	{
		int m=l+r>>1;
		if(a[i]>=slope(q[m],q[m+1]))as=m,r=m-1;
		else l=m+1;
	}
	as=q[as];
	t=a[i]*as-f[as];
	// oldp(as,t);
	while(tail>head&&slope(q[tail-1],q[tail])<slope(q[tail],i))tail--;
	q[++tail]=i;
	// rg_(j,i-1)t=max(t,a[i]*j-f[j]);gr
	// while
	t+=f[i]-a[i]*i;
	// odl(-t);
	g=max(-t,g);
	gr
	int R2=ans+g;
	oldl(max(R1,R2));
	return 0;
}