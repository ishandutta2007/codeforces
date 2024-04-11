// Problem: G. A Stroll Around the Matrix
// Contest: Codeforces - Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1609/problem/G
// Memory Limit: 256 MB
// Time Limit: 6000 ms
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
int a[105],b[100005],n,m,k;
struct BIT{
	int a[200005];
	void add(int x,int p)
	{
		while(x<=m)a[x]+=p,x+=x&-x;
	}
	int que(int x)
	{
		int res=0;
		while(x>0)res+=a[x],x-=x&-x;
		return res;
	}
	int pigstd_bu_hui_de_dong_xi(int x)
	{
		int d=0;
		for(int i=20;i>=0;i--)
		{
			int dd=d;dd+=1<<i;
			if(dd<=m)
			{
				if(a[dd]<=x)x-=a[dd],d=dd;
			}
		}
		return d;
	}
}t1,t2;
signed main()
{
	n=read(),m=read(),k=read();
	rg(n)a[i]=read();gr
	rg(m)b[i]=read();gr
	int cur=a[1]+b[1];
	cur*=(n+m-1);
	rg(n)a[i]=a[i+1]-a[i];gr
	rg(m)cur+=b[i];gr 
	cur-=b[1]*m;
	rg(m)b[i]=b[i+1]-b[i];gr
	// for(int i=n;i>=1;i--)a[i]-=a[i-1];
	// for(int i=m;i>=1;i--)b[i]-=b[i-1];
	// cur=0;
	n--,m--;
	// rg(n)odb(a[i]);gr puts("");
	// rg(m)odb(b[i]);gr puts("");
	rg(m)t1.add(i,b[i]-b[i-1]),t2.add(i,i*(b[i]-b[i-1]));gr
	rg(k)
	// odl(cur);
	int op=read(),k=read(),d=read();
	if(op==1)
	{
		if(k==n+1)cur+=(n+m+1)*d,k--;
		rg(k)a[n-i+1]+=d;gr
	}
	else if(op==2)
	{
		if(k==m+1)cur+=(n+m+1)*d,k--;
		cur+=k*(k+1)/2*d;
		t1.add(m-k+1,d);
		t2.add(m-k+1,d*(m-k+1));
	}
	int ans=0;
	rg(n)
	int pos=t1.pigstd_bu_hui_de_dong_xi(a[i]);
	// odp(pos,t1.que(pos));
	ans+=(n+m+1-i-pos)*a[i]+(pos+1)*t1.que(pos)-t2.que(pos);
	gr
	oldl(ans+cur);
	gr
	return 0;
}