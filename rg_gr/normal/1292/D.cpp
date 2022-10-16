// Problem: D. Chaotic V.
// Contest: Codeforces - Codeforces Round #614 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1292/D
// Memory Limit: 512 MB
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
int a[5005];
int d[5005][5005];
int p[111],cc;
void init(int n)
{
	p[++cc]=2;
	p[++cc]=3;
	p[++cc]=5;
	p[++cc]=7;
	p[++cc]=11;
	p[++cc]=13;
	p[++cc]=17;
	p[++cc]=19;
	p[++cc]=23;
	p[++cc]=27;
	p[++cc]=29;
	p[++cc]=31;
	p[++cc]=37;
	p[++cc]=41;
	p[++cc]=43;
	p[++cc]=47;
	p[++cc]=53;
	p[++cc]=59;
	p[++cc]=61;
	p[++cc]=67;
	p[++cc]=71;
	p[++cc]=73;
	p[++cc]=79;
	p[++cc]=83;
	p[++cc]=89;
	p[++cc]=97;
	//10026
	rg(n)
	rg_(j,n)d[i][j]=d[i-1][j];gr
	d[i][0]=d[i-1][0];
	int dd=i;
	rg_(j,cc)while(dd%p[j]==0)d[i][0]++,d[i][p[j]]++,dd/=p[j];gr
	if(dd>1)d[i][dd]++,d[i][0]++;
	gr
}
int pat[5005],isp[5005];
signed main()
{
	int n=read();
	init(5000);
	rg(n)a[read()]++;gr
	int ans=0;
	rg(5000)ans+=a[i]*d[i][0];gr
	rg(5000)if(i>1)for(int j=i+i;j<=5000;j+=i)isp[j]=1;
	gr
	// rg(50)printf("%d : ",d[i][0]);rg_(j,50)odb(d[i][j]);gr puts("");gr
	for(int i=5000;i>=1;)
	{
		if(isp[i])
		{
			i--;
			continue;
		}
		int t=0;
		rg_(j,5000)if(pat[j])continue;
		if(d[j][i])t+=a[j];
		gr
		if(t+t>n)
		{
			// odl(i);
			rg_(j,5000)if(pat[j])continue;
			if(d[j][i])d[j][i]--;
			else pat[j]=1;
			gr
			ans=ans-t+(n-t);
		}
		else
		{
			rg_(j,5000)if(pat[j])continue;
			if(d[j][i])pat[j]=1;
			gr
			i--;
		}
		if(i<=50)
		{
			// odl(i);
			// rg(50)odb(pat[i]);gr puts("");
		}
	}
	oldl(ans);
	return 0;
}