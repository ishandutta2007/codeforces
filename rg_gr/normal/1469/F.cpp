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
int a[200005];
const int N=400002;
typedef int arr[N*4+5];
arr tag,sum;
void build(int o,int l,int r)
{
	
}
void maintain(int o)
{
	sum[o]=sum[o<<1]+sum[o<<1|1];
}
void pushdown(int o,int l,int r)
{
	int m=l+r>>1;
	tag[o<<1]+=tag[o];
	tag[o<<1|1]+=tag[o];
	sum[o<<1|1]+=tag[o]*(r-m);
	sum[o<<1]+=tag[o]*(m-l+1);
	tag[o]=0;
}
void add(int o,int l,int r,int L,int R,int v)
{
	if(L<=l&&r<=R)
	{
		tag[o]+=v;
		sum[o]+=(r-l+1)*v;
		return;
	}
	pushdown(o,l,r);
	int m=l+r>>1;
	if(L<=m)add(o<<1,l,m,L,R,v);
	if(m<R)add(o<<1|1,m+1,r,L,R,v);
	maintain(o);
}
int kth(int o,int l,int r,int k)
{
	if(l==r)return l;
	pushdown(o,l,r);
	int m=l+r>>1;
	if(sum[o<<1]>=k)return kth(o<<1,l,m,k);
	return kth(o<<1|1,m+1,r,k-sum[o<<1]);
}
int qmin(int o,int l,int r)
{
	return kth(o,l,r,1);
}
int ssum()
{
	return sum[1];
}
signed main()
{
	int n=read(),k=read();
	rg(n)a[i]=read();gr
	std::sort(a+1,a+1+n,[&](int x,int y){return x>y;});
	build(1,1,N);add(1,1,N,1,1,1);
	int ans=0x3f3f3f3f3f3f3f3fll;
	rg(n)
	int d=qmin(1,1,N),w=a[i];add(1,1,N,d,d,-1);
	if(w==1)continue;
	//d+1
	if(w&1)
	{
		add(1,1,N,d+2,d+1+(w>>1),1);
		add(1,1,N,d+2,d+1+(w>>1),1);
	}
	else
	{
		if(d+2<=d+0+(w>>1))
		add(1,1,N,d+2,d+0+(w>>1),1);
		add(1,1,N,d+2,d+1+(w>>1),1);
	}
	// return 0;
	if(ssum()>=k)ans=min(ans,kth(1,1,N,k)-1);
	gr
	// odl(ans);
	if(ans==0x3f3f3f3f3f3f3f3fll)puts("-1");else oldl(ans);
	return 0;
}