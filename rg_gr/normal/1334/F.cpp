// Problem: F. Strange Function
// Contest: Codeforces - Educational Codeforces Round 85 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1334/F
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
std::vector<int>v[500005];
int a[500005],dp[500005];
int sum[2000005],tag[2000005];
void pushdown(int o,int l,int r)
{
	int&t=tag[o];
	int m=l+r>>1;
	sum[o<<1]+=t*(m-l+1);
	sum[o<<1|1]+=t*(r-m);
	tag[o<<1]+=t;
	tag[o<<1|1]+=t;
	t=0;
}
void add(int o,int l,int r,int L,int R,int v)
{
	// for(int i=L;i<=R;i++)minn[i]+=v;
	if(L<=l&&r<=R)
	{
		sum[o]+=v*(r-l+1);
		tag[o]+=v;
		return;
	}
	int m=l+r>>1;
	pushdown(o,l,r);
	if(L<=m)add(o<<1,l,m,L,R,v);
	if(m<R)add(o<<1|1,m+1,r,L,R,v);
	sum[o]=(sum[o<<1]+sum[o<<1|1]);
}
int que(int o,int l,int r,int L,int R)
{
	// if(L>R)return 0;
	// int res=minn[L];
	// for(int i=L;i<=R;i++)res=min(res,minn[i]);
	// return res;
	if(L<=l&&r<=R)
	{
		return sum[o];
	}
	int m=l+r>>1,res=0;
	pushdown(o,l,r);
	if(L<=m)res=(res+que(o<<1,l,m,L,R));
	if(m<R)res=(res+que(o<<1|1,m+1,r,L,R));
	sum[o]=(sum[o<<1]+sum[o<<1|1]);
	return res;
}
int p[2000005],t[2000005],tmp[2000005][2];
signed main()
{
	int n=read();
	rg(n)a[i+1]=read()+1;v[a[i+1]].push_back(i+1);gr
	v[1].push_back(1);
	rg(n)add(1,1,n+2,i+1,i+1,p[i+1]=read());gr
	n+=2;
	v[n].push_back(n);
	a[1]=1;a[n]=n;
	memset(dp,0x3f,sizeof(dp));
	dp[1]=0;
	int cc=1;
	int m=read();
	rg(m)t[i+1]=read()+1;gr
	t[1]=1;m++;
	t[++m]=n;
	// rg(n)odb(a[i]);gr puts("");
	// rg(n)odb(p[i]);gr puts("");
	// rg(m)odb(t[i]);gr puts("");
	// odl(que(1,1,n,3,2));
	rg(n-1)
	for(auto x:v[i])
	{
		if(p[x]>=0)add(1,1,n,x,x,-p[x]),p[x]=0;
	}
	if(t[cc]!=i)continue;
	int g=0;
	for(int j=0;j<v[i].size();j++)
	{
		int x=v[i][j];
		if(dp[x]>=1e16&&g==0)continue;
		if(g==0)
		{
			tmp[x][0]=dp[x]+p[x];
			tmp[x][1]=dp[x];
			g=1;
			// odp(-8,x);
			// odl(tmp[x][0]);
			// odl(tmp[x][1]);
		}
		else
		{
			int y=v[i][j-1];
			// odp(x,y);
			// tmp[x][0]=min(tmp[y][0]+que(1,1,n,y+1,x),tmp[y][1]+que(1,1,n,y+1,x));
			// tmp[x][0]=tmp[y][0]+que(1,1,n,y+1,x);
			tmp[x][1]=min(tmp[x][1],tmp[y][1]+que(1,1,n,y+1,x-1));
			// odl(tmp[x][0]);
			// odl(tmp[x][1]);
			dp[x]=min(dp[x],tmp[x][1]);
		}
	}
// '	for(int j=1;j<v[i].size();j++)
	// {
		// int A=v[i][j],B=v[i][j-1];
		// // dp[A]=min(dp[A],dp[B]+que(1,1,n,B+1,A));
		// dp[A]=min(dp[A],dp[B]+que(1,1,n,B,A-1));
	// }'
	int f=t[cc+1];cc++;
	for(auto x:v[i])
	{
		auto t=std::lower_bound(v[f].begin(),v[f].end(),x);
		if(t==v[f].end())break;
		dp[*t]=min(dp[*t],dp[x]+que(1,1,n,x+1,(*t)-1));
	}
	g=0;
	for(int j=0;j<v[f].size();j++)
	{
		int x=v[f][j];
		if(dp[x]>=1e16&&g==0)continue;
		if(g==0)
		{
			tmp[x][0]=dp[x]+p[x];
			tmp[x][1]=dp[x];
			g=1;
			// odp(-8,x);
			// odl(tmp[x][0]);
			// odl(tmp[x][1]);
		}
		else
		{
			int y=v[f][j-1];
			tmp[x][0]=dp[x]+p[x];
			tmp[x][1]=dp[x];
			// tmp[x][0]=min(tmp[y][0]+que(1,1,n,y+1,x),tmp[y][1]+que(1,1,n,y+1,x));
			tmp[x][0]=min(tmp[x][0],tmp[y][0]+que(1,1,n,y+1,x));
			// tmp[x][1]=min(tmp[y][0]+que(1,1,n,y+1,x-1),tmp[y][1]+que(1,1,n,y+1,x-1));
			tmp[x][1]=min(tmp[x][1],min(tmp[y][0]+que(1,1,n,y+1,x-1),tmp[y][1]+que(1,1,n,y+1,x-1)+0x3f3f3f3f3f3f3f3f));
			// odp(x,y);
			// odl(tmp[x][0]);
			// odl(tmp[x][1]);
			dp[x]=min(dp[x],tmp[x][1]);
		}
	}
	gr
	// rg(n)if(dp[i]>=0x3f3f3f3f)puts("inf");else odl(dp[i]);gr
	// puts("");
	// rg(n)if(tmp[i][0]>=0x3f3f3f3f)puts("inf");else odl(tmp[i][0]);gr
	if(dp[n]>1e16)puts("NO");
	else puts("YES"),oldl(dp[n]);
	return 0;
}