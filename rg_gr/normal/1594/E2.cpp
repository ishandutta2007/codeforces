// Problem: E2. Rubik's Cube Coloring (hard version)
// Contest: Codeforces - Codeforces Round #747 (Div. 2)
// URL: https://codeforces.com/contest/1594/problem/E2
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
#define rg(x) for(int i=1;i<=(x);i++){
#define rg_(i,x) for(int i=1;i<=(x);i++){
#define fe(u) for(int i=h[u];i;i=e[i].nxt){int v=e[i].v;
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
#include <map>
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
int d[128];
inline int re1d()
{
    char c=getchar();
    while(d[c]==0)c=getchar();
    return d[c];
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
std::map<int,int>mp,m2;
int k;
struct res{
	int a[4]={};
};
const int mod=1000000007;
inline int qp(int x,int p)
{
	int res=1;//x%=mod;
	while(p)
	{
		if(p&1)res=res*x%mod;
		x=x*x%mod;
		p>>=1;
	}
	return res;
}
res solve(int o,int d)
{
	if(d==1)
	{
		res x;
		if(!m2.count(o))x.a[1]=x.a[2]=x.a[3]=2;
		else x.a[m2[o]]=1;
		return x;
	}
	if(!mp.count(o))
	{
		res x;
		x.a[1]=x.a[2]=x.a[3]=2*qp(4,d-1)%mod;
		return x;
	}
	res l=solve(o<<1,d>>1),r=solve(o<<1|1,d>>1);
	res x;
	x.a[1]=2*(l.a[2]+l.a[3])*(r.a[2]+r.a[3])%mod;
	x.a[2]=2*(l.a[1]+l.a[3])*(r.a[1]+r.a[3])%mod;
	x.a[3]=2*(l.a[1]+l.a[2])*(r.a[1]+r.a[2])%mod;
	if(m2.count(o))
	{
		int q=m2[o];
		rg(3)if(i!=q)x.a[i]=0;else x.a[i]=x.a[i]*(mod+1>>1)%mod;gr
	}
	return x;
}
int sum(res x)
{
	int ans=0;
	rg(3)ans=(ans+x.a[i])%mod;gr
	return ans;
}
signed main()
{
	d['w']=d['y']=1;
	d['r']=d['o']=2;
	d['b']=d['g']=3;
	int n=read();
	k=read();rg(k)
	int x=read();
	m2[x]=re1d();
	while(x)mp[x]=1,x>>=1;
	gr
	odl(sum(solve(1,(1ll<<n)-1)));
	//1ll!
	return 0;
}