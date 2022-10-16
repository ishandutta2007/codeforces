// Problem: A. The Beatles
// Contest: Codeforces - Codeforces Round #549 (Div. 1)
// URL: https://codeforces.com/contest/1142/problem/A
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
#define nln puts("")
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
const int mod=998244353;
#ifdef int 
#define inf 0x3f3f3f3f3f3f3f3fll
#else 
#define inf 0x3f3f3f3f
#endif
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
#define cmlSEGMIN
#define cmlSEGMAX
#define cmlSEGSUM
class SegTreeAl{
#ifdef cmlSEGMIN
	int minn[1000005<<2];
#endif
#ifdef cmlSEGMAX
	int maxn[1000005<<2];
#endif
#ifdef cmlSEGSUM
	int sum[1000005<<2];
#endif
	int tag[1000005<<2];
#ifdef cmlSEGSUM
	void pushdown(int o,int l,int r)
#else 
	void pushdown(int o)
#endif
	{
		int&t=tag[o];
#ifdef cmlSEGMIN
		minn[o<<1]+=t;
		minn[o<<1|1]+=t;
#endif
#ifdef cmlSEGMAX
		maxn[o<<1]+=t;
		maxn[o<<1|1]+=t;
#endif
#ifdef cmlSEGSUM
		int m=l+r>>1;
		sum[o<<1]+=t*(m-l+1);
		sum[o<<1|1]+=t*(r-m);
#endif
		tag[o<<1]+=t;
		tag[o<<1|1]+=t;
		t=0;
	}
	void add(int o,int l,int r,int L,int R,int v)
	{
		if(L<=l&&r<=R)
		{
#ifdef cmlSEGMAX
			maxn[o]+=v;
#endif
#ifdef cmlSEGMIN
			minn[o]+=v;
#endif
#ifdef cmlSEGSUM
			sum[o]+=v*(r-l+1);
#endif
			tag[o]+=v;
			return;
		}
		int m=l+r>>1;
#ifdef cmlSEGSUM
		pushdown(o,l,r);
#else
		pushdown(o);
#endif
		if(L<=m)add(o<<1,l,m,L,R,v);
		if(m<R)add(o<<1|1,m+1,r,L,R,v);
#ifdef cmlSEGMAX
		maxn[o]=max(maxn[o<<1],maxn[o<<1|1]);
#endif
#ifdef cmlSEGMIN
		minn[o]=min(minn[o<<1],minn[o<<1|1]);
#endif
#ifdef cmlSEGSUM
		sum[o]=sum[o<<1]+sum[o<<1|1];
#endif
	}
#ifdef cmlSEGMIN
	int qmin(int o,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R)
		{
			return minn[o];
		}
		int m=l+r>>1,res=inf;
#ifdef cmlSEGSUM
		pushdown(o,l,r);
#else
		pushdown(o);
#endif
		if(L<=m)res=min(res,qmin(o<<1,l,m,L,R));
		if(m<R)res=min(res,qmin(o<<1|1,m+1,r,L,R));
#ifdef cmlSEGMAX
		maxn[o]=max(maxn[o<<1],maxn[o<<1|1]);
#endif
#ifdef cmlSEGMIN
		minn[o]=min(minn[o<<1],minn[o<<1|1]);
#endif
#ifdef cmlSEGSUM
		sum[o]=sum[o<<1]+sum[o<<1|1];
#endif
		return res;
	}
#endif

#ifdef cmlSEGMAX
	int qmax(int o,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R)
		{
			return maxn[o];
		}
		int m=l+r>>1,res=-inf;
#ifdef cmlSEGSUM
		pushdown(o,l,r);
#else
		pushdown(o);
#endif
		if(L<=m)res=max(res,qmax(o<<1,l,m,L,R));
		if(m<R)res=max(res,qmax(o<<1|1,m+1,r,L,R));
#ifdef cmlSEGMAX
		maxn[o]=max(maxn[o<<1],maxn[o<<1|1]);
#endif
#ifdef cmlSEGMIN
		minn[o]=min(minn[o<<1],minn[o<<1|1]);
#endif
#ifdef cmlSEGSUM
		sum[o]=sum[o<<1]+sum[o<<1|1];
#endif
		return res;
	}
#endif

#ifdef cmlSEGSUM
	int qsum(int o,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R)
		{
			return sum[o];
		}
		int m=l+r>>1,res=0;
#ifdef cmlSEGSUM
		pushdown(o,l,r);
#else
		pushdown(o);
#endif
		if(L<=m)res+=qsum(o<<1,l,m,L,R);
		if(m<R)res+=qsum(o<<1|1,m+1,r,L,R);
#ifdef cmlSEGMAX
		maxn[o]=max(maxn[o<<1],maxn[o<<1|1]);
#endif
#ifdef cmlSEGMIN
		minn[o]=min(minn[o<<1],minn[o<<1|1]);
#endif
#ifdef cmlSEGSUM
		sum[o]=sum[o<<1]+sum[o<<1|1];
#endif
		return res;
	}
#endif
};
#define newe(n) struct Edge{int v,w,nxt;}e[2*n+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}\
struct node{\
	int u,d;\
	bool operator<(const node&b)const{return d>b.d;}\
};\
void dij(int s,int *d,int N)\
{\
	memset(d,0x3f,sizeof(int)*(N+3));\
	d[s]=0;std::priority_queue<node>q;q.push((node){s,0});\
	while(!q.empty())\
	{\
		int u=q.top().u,D=q.top().d;q.pop();if(D!=d[u])continue;\
		for(int i=h[u];i;i=e[i].nxt){int v=e[i].v,w=e[i].w;\
		if(d[u]+w<d[v])d[v]=d[u]+w,q.push((node){v,d[v]});\
		}\
	}\
}
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
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int maxn=0,minn=inf;
int test(int x,int y)
{
	if(x==0)return 0;
	int z=y/gcd(x,y);
	maxn=max(maxn,z);
	minn=min(minn,z);
	return 0;
}
signed main()
{
	int n=read(),k=read(),a=read(),b=read();
	int x=a-b,y=a+b,z=-a-b,w=-a+b;
	x+=10*k;z+=10*k;x%=k,z%=k;
	y+=10*k;w+=10*k;y%=k,w%=k;
	rg_(t,n+1)int i=t-1;
	test(x+i*k,n*k);
	test(y+i*k,n*k);
	test(z+i*k,n*k);
	test(w+i*k,n*k);
	gr
	oldp(minn,maxn);
	return 0;
}