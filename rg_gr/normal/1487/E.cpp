// Problem: E. Cheap Dinner
// Contest: Codeforces - Educational Codeforces Round 104 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1487/problem/E
// Memory Limit: 512 MB
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
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <assert.h>
#include <vector>
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
#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[2*n+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}
#define mgs int fa[1<<22],sz[1<<22];\
inline int f(int x){return x==fa[x]?x:fa[x]=f(fa[x]);}\
inline int u(int x,int y)\
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
inline int max(int a,int b){return a>b?b:a;}
std::vector<int>bb[200005],cc[200005],dd[200005];
int A[200005],B[200005],C[200005],D[200005],E[200005],lg[200005];
struct ST{
	int maxn[20][200005];
	inline void build(int n)
	{
		//rg(n)odb(E[i]);gr puts("");
		rg(n)maxn[0][i]=E[i];gr
		rg(19)rg_(j,n-(1<<i)+1)maxn[i][j]=max(maxn[i-1][j],maxn[i-1][j+(1<<i-1)]);gr gr
	}
	int operator()(int l,int r)
	{
		if(l>r)return 0x3f3f3f3f3f3f3f3fll;
		int d=lg[r-l+1];
		return max(maxn[d][l],maxn[d][r-(1<<d)+1]);
	}
}st;
signed main()
{
	int a=read(),b=read(),c=read(),d=read();
	rg(a)A[i]=read();gr
	rg(b)B[i]=read();gr
	rg(c)C[i]=read();gr
	rg(d)D[i]=read();gr
	rg(a)E[i]=A[i];gr
	lg[0]=-1;
	rg(150000)lg[i]=lg[i>>1]+1;gr
	int s=read();
	rg(s)int x=read(),y=read();
	bb[y].push_back(x);gr
	s=read();
	rg(s)int x=read(),y=read();
	cc[y].push_back(x);gr
	s=read();
	rg(s)int x=read(),y=read();
	dd[y].push_back(x);gr
	st.build(a);
	rg(b)bb[i].push_back(0),bb[i].push_back(a+1);
	std::sort(bb[i].begin(),bb[i].end());
	E[i]=0x3f3f3f3f3f3f3f3fll;
	int pre=-1;
	for(auto x:bb[i])
	{
		if(pre!=-1)E[i]=max(E[i],st(pre+1,x-1)+B[i]);
		pre=x;
	}
	gr
	st.build(b);
	rg(c)cc[i].push_back(0),cc[i].push_back(b+1);
	std::sort(cc[i].begin(),cc[i].end());
	E[i]=0x3f3f3f3f3f3f3f3fll;
	int pre=-1;
	for(auto x:cc[i])
	{
		if(pre!=-1)E[i]=max(E[i],st(pre+1,x-1)+C[i]);
		pre=x;
	}
	gr
	st.build(c);
	E[0]=0x3f3f3f3f3f3f3f3fll;
	rg(d)dd[i].push_back(0),dd[i].push_back(c+1);
	std::sort(dd[i].begin(),dd[i].end());
	int pre=-1;
	for(auto x:dd[i])
	{
		if(pre!=-1)E[0]=max(E[0],st(pre+1,x-1)+D[i]);
		pre=x;
	}
	gr
	oldl(E[0]>=0x3f3f3f3f3f3f3f3fll?-1ll:E[0]);
	return 0;
}