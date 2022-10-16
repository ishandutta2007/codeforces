// Problem: E. Playoff Restoration
// Contest: Codeforces - Educational Codeforces Round 113 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1569/problem/E
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
#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[n*2+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}
#define mgs int fa[1<<22],sz[1<<22],t[1<<22];\
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
inline int max(int a,int b){return a<b?b:a;}
const int mod=998244353;
struct qwq{
	int hash;
	int bin;
	bool operator<(const qwq&b)const
	{
		return hash<b.hash;
	}
};
int a[33],res[33],p[33],winner;
int getfinal(int start,int val,int n,int d=0)
{
	rg(1<<n)a[i]=i;res[i]=0;gr
	int cc=0,l=1,r=2,lim=1<<n,f=1<<n;f++;
	while(cc<(1<<n)-1)
	{
//		odb(f),odp(a[l],a[r]);;
		if((val>>cc)&1)a[r>>1]=a[l],res[a[r]]=f;
		else res[a[l]]=f,a[r>>1]=a[r];
		l+=2,r+=2;
		if(l>lim)l=1,r=2,lim>>=1,f=f+1>>1;
		cc++;
	}
	rg(1<<n)if(res[i]==0)res[i]=d?1:2,winner=i;gr
	int hash=0;
//	rg(1<<n)odb(res[i]);gr puts("");
	rg(1<<n)hash=(hash+(i+start)*p[res[i]]%mod)%mod;gr
	return hash;
}
std::set<qwq> mp[2][2];
signed main()
{
	int n=read(),A=read(),r=read();
	p[0]=1;rg(1<<n)p[i]=(p[i-1]*A)%mod;gr
	for(int i=0;i<(1<<((1<<n-1)-1));i++)
	{
		int h=getfinal(0,i,n-1);
		qwq x=(qwq){h,i};
//		odl(h);
		mp[0][0].insert(x);
	}
//	puts("");
	for(int i=0;i<(1<<((1<<n-1)-1));i++)
	{
		int h=getfinal(0,i,n-1,1);
		qwq x=(qwq){h,i};
		mp[0][1].insert(x);
//		odl(h);
	}
//	puts("");
	for(int i=0;i<(1<<((1<<n-1)-1));i++)
	{
		int h=getfinal(1<<(n-1),i,n-1);
		qwq x=(qwq){h,i};
		mp[1][0].insert(x);
//		odl(h);
	}
//	puts("");
	for(int i=0;i<(1<<((1<<n-1)-1));i++)
	{
		int h=getfinal(1<<(n-1),i,n-1,1);
		qwq x=(qwq){h,i};
		mp[1][1].insert(x);
//		odl(h);
	}
//	puts("");
	for(auto x:mp[0][0])
	{
		int hash=x.hash;
		int y=(r-hash+mod)%mod;
		qwq s=(qwq){y,0};
		if(mp[1][1].count(s))
		{
			getfinal(0,x.bin,n-1);
			rg(1<<n-1)odb(res[i]);gr
			getfinal(1<<n-1,mp[1][1].find(s)->bin,n-1,1);
			rg(1<<n-1)odb(res[i]);gr
			return 0;
		}
	}
	for(auto x:mp[1][0])
	{
		int hash=x.hash;
		int y=(r-hash+mod)%mod;
		qwq s=(qwq){y,0};
		if(mp[0][1].count(s))
		{
			getfinal(0,mp[0][1].find(s)->bin,n-1,1);
			rg(1<<n-1)odb(res[i]);gr
			getfinal(1<<n-1,x.bin,n-1);
			rg(1<<n-1)odb(res[i]);gr
			return 0;
		}
	}
	puts("-1");
	return 0;
}