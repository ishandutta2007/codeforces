// Problem: D. Two Sets
// Contest: Codeforces - Codeforces Round #153 (Div. 1)
// URL: https://codeforces.com/problemset/problem/251/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int a[100005];
struct qwq{
	int a[64],b[64],uu[100005];
	// std::bitset<70>f[70];
	int f[64];
	int insert(int x,int v)
	{
		// int tmp[70]={},cc=0;
		// std::bitset<70>tmp;
		int tmp=0;
		for(int i=61;i>=0;i--)
		{
			if((x>>i)&1)
			{
				if(a[i]==0)
				{
		// printf("ins %d %d %d\n",x,v,i);
					a[i]=x;
					b[i]=v;
					// anss[v]=1;
					// memcpy(f[i],tmp,sizeof(f[i]));
					// tmp.set(i);
					f[i]=tmp|(1ll<<i);
					return 1ll<<i;
				}
				x^=a[i];
				tmp^=f[i];
				// tmp[++cc]=b[i];
				
			}
			// tmp
		}
		return 0;
	}
	void clear()
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(f,0,sizeof(f));
		memset(uu,0,sizeof(uu));
	}
	int calc()
	{
		int ans=0,tmp=0;
		// for(int i=)
		for(int i=61;i>=0;i--)
		{
			if(!a[i])continue;
			if(ans<(ans^a[i]))
			{
				ans^=a[i];
				tmp^=f[i];
				// odb(ans),odp(i,b[i]);
			}
		}
		for(int i=0;i<=61;i++)
		{
			if((tmp>>i)&1)uu[b[i]]=1;
		}
		return ans;
	}
}s,t,z;
int ret[100005];
const unsigned long long tyy=(1ull<<62)-1;
signed main()
{
	int n=read(),X=0,ans=0;
	rg(n)a[i]=read();if(s.insert(a[i],i));X^=a[i];gr
	rg(n);if(t.insert(a[i]&(X^tyy),i));gr
	// rg()
	// oldl(X);
	ans=t.calc();
	memcpy(ret,t.uu,sizeof(ret));
	// oldl(ans+(ans^X));
	for(int i=61;i>=0;i--)
	{
		int g=1ll<<i;
		if((X>>i)&1);else continue;
		if((ans>>i)&1)continue;
		z.clear();
		rg(n)z.insert(a[i]&(((tyy)^X)|ans|(g)),i);gr
		// odl((((unsigned long long)-1)^X)|ans|(g));
		int d=z.calc();
		if((d==ans)||((d&(ans))!=(ans)))continue;
		// oldl(d);
		memcpy(ret,z.uu,sizeof(ret));
		ans=d;
	}
	// oldp(ans,(X^ans));
	int s=0;
	rg(n)odb(ret[i]+1);if(ret[i])s^=a[i];gr 
	puts("");
	// oldl(s);
	// oldl(s+(X^s));
	// odl(a[21]^a[28]^a[4]^a[9]^a[10]^a[3]);
	//2078098915129555874
	return 0;
}