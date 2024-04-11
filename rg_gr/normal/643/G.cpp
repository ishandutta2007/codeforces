// Problem: G. Choosing Ads
// Contest: Codeforces - VK Cup 2016 - Round 3
// URL: https://codeforces.com/contest/643/problem/G
// Memory Limit: 512 MB
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
int aa[200005];
int p;
struct GodL{
	int a[800005][6],sz[800005],qwq[800005][6],tag[800005];
	const int B=800001,C=B+1,D=C+1;
	void maintain(int o,int l,int r)
	{
		// assert(l!=D);
		// assert(r!=D);
		// assert(o!=D);
		if(sz[l]==0)
		{		
			l=r;
			sz[o]=sz[l];rg(sz[l])a[o][i]=a[l][i],qwq[o][i]=qwq[l][i];gr
			return;
		}
		sz[o]=sz[l];rg(sz[l])a[o][i]=a[l][i],qwq[o][i]=qwq[l][i];gr
		rg(sz[r])
		//find 
		int t=0;
		rg_(j,sz[l])if(a[o][j]==a[r][i]){t=j;break;}gr
		if(t)
		{
			qwq[o][t]+=qwq[r][i];
		}else if(sz[o]<p)sz[o]++,a[o][sz[o]]=a[r][i],qwq[o][sz[o]]=qwq[r][i];
		else
		{
			int minn=sz[o];
			rg(sz[o]-1)if(qwq[o][i]<qwq[o][minn])minn=i;gr
			int g=min(qwq[o][minn],qwq[r][i]);
			rg(sz[o])qwq[o][i]-=g;gr
			if(qwq[o][minn]==0)a[o][minn]=a[r][i],qwq[o][minn]=qwq[r][i]-g;
		}
		gr
	}
	void build(int o,int l,int r)
	{
		if(l==r)sz[o]=1,a[o][1]=aa[l],qwq[o][1]=1;
		else
		{
			int m=l+r>>1;
			build(o<<1,l,m);
			build(o<<1|1,m+1,r);
			maintain(o,o<<1,o<<1|1);
		}
	}
	void pushdown(int o,int l,int r)
	{
		if(tag[o]==0)return;
		int m=l+r>>1;
		tag[o<<1]=tag[o<<1|1]=tag[o];
		sz[o<<1]=sz[o<<1|1]=1;
		a[o<<1][1]=a[o<<1|1][1]=tag[o];
		qwq[o<<1][1]=qwq[o<<1|1][1]=r-m;
		tag[o]=0;
	}
	void modify(int o,int l,int r,int L,int R,int v)
	{
		if(L<=l&&r<=R)
		{
			tag[o]=a[o][1]=v;
			sz[o]=1;
			qwq[o][1]=r-l+1;
			return;
		}
		pushdown(o,l,r);
		int m=l+r>>1;
		if(L<=m)modify(o<<1,l,m,L,R,v);
		if(m<R)modify(o<<1|1,m+1,r,L,R,v);
		maintain(o,o<<1,o<<1|1);
	}
	void cpy(int to,int fr)
	{
		sz[to]=sz[fr];tag[to]=tag[fr];
		rg(sz[to])a[to][i]=a[fr][i],qwq[to][i]=qwq[fr][i];gr
	}
	void query(int o,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R)
		{
			// printf("+ %d %d %d %d %d\n",l,r,sz[o],sz[B],sz[C]);
			cpy(C,B);
			maintain(B,C,o);
			// odp(l,r);odl(sz[o]),odl(sz[C]);
			// printf("- %d %d %d %d %d\n",l,r,sz[o],sz[B],sz[C]);
			//odl(a[C][1]);
			return;
		}
		pushdown(o,l,r);
		int m=l+r>>1;
		if(L<=m)query(o<<1,l,m,L,R);
		if(m<R)query(o<<1|1,m+1,r,L,R);
		maintain(o,o<<1,o<<1|1);
	}
}t;
signed main()
{
	int n=read(),m=read();p=100/read();
	rg(n)aa[i]=read();gr t.build(1,1,n);
	rg(m)int op=read(),l=read(),r=read();
	if(op==1)t.modify(1,1,n,l,r,read());
	else 
	{
		t.cpy(t.B,t.D);
		t.query(1,1,n,l,r);
		odb(t.sz[t.B]);
		rg(t.sz[t.B])odb(t.a[t.B][i]);gr puts("");
		// t.solve()
	}
	// rg(n)t.query(1,1,n,i,i),odb(t.a[t.B][1]);gr
	gr
	return 0;
}