// Problem: C. New Language
// Contest: Codeforces - Codeforces Round #315 (Div. 1)
// URL: https://codeforces.com/contest/568/problem/C
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
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#define FAIL 0
#define SUCCESS 1
//#define int long long
#define newe(n) struct Edge{int v,nxt;}e[n*n*2+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v){e[cnt]=(Edge){v,h[u]};h[u]=cnt++;}
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
    while(c<'A'||c>'Z')c=getchar();
    return c=='C';
}
inline int re1c()
{
    char c=getchar();
    while(c<'A'||c>'Z')c=getchar();
    return c;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int n,m;
struct Z_SAT{
newe(405);
arr c,low,dfn,st;
int s,t,r;
void tarjan(int u)
{
	low[u]=dfn[u]=++s;
	st[++t]=u;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=(low[u]<low[v]?low[u]:low[v]);
		}
		else if(!c[v])low[u]=low[u]<dfn[v]?low[u]:dfn[v];
	}
	if(low[u]==dfn[u])
	{
		c[u]=++r;
		while(st[t]!=u)c[st[t]]=r,t--;
		t--;
	}
}
#define ms(dfn )memset(dfn,0,sizeof(dfn));
int Generate()
{
	ms(dfn)
	ms(low)
	ms(c)
	t=0;
	s=0;
	r=0;
	for(int i=1;i<=n+n;i++)if(!dfn[i])tarjan(i);
    for(int i=1;i<=n;i++)if(c[i]==c[i+n])
    {
        return FAIL;
    }
    return SUCCESS;
}
void PushQuery()
{
	
}
void PopQuery()
{
	
}
#define cp(c) memcpy(c,b.c,sizeof(c));
Z_SAT& operator=(const Z_SAT &b)
{
	cp(c);
	cp(low);
	cp(dfn);
	s=b.s;t=b.t;r=b.r;cnt=b.cnt;
	cp(h);
	// cp(e);
	memcpy(e,b.e,sizeof(Edge)*(cnt+3));
	return *this;
}
}solver,Solver;
int belong[128];
int nextc[128][2];
char temp[1280];
int main()
{
	scanf("%s",temp+1);
	int L=strlen(temp+1);
	rg(L)belong[i]=(temp[i]=='C');gr
	n=read(),m=read();rg(m)
	int x=read(),a=re1d()^1,y=read(),b=re1d();
	solver.addedge(x+n*a,y+n*(b^1));
    solver.addedge(y+n*b,x+n*(a^1));
    gr
    for(int i=L;i>=1;i--)
    	for(int j=1;j<=i;j++)nextc[j][belong[i]]=i;
    scanf("%s",temp+1);
    rg(n)temp[i]-=96;gr
    if(nextc[1][0]==0||nextc[1][1]==0)
    {
	    rg(n)
    	if(nextc[1][0]==0)solver.addedge(i+n,i);
	    if(nextc[1][1]==0)solver.addedge(i,i+n);
    	gr
	    if(solver.Generate()==FAIL)
	    {
	    	puts("-1");
	    	return 0;
	    }
	    rg(n)putchar(temp[i]+96);gr 
	    return 0;
    }
    if(solver.Generate()==FAIL)
    {
    	puts("-1");
    	return 0;
    }
	rg(n+1)
	//
	//
	int pos=n-i+1;
	Solver=solver;
	rg_(j,pos)Solver.addedge(j+n*belong[temp[j]],j+n*(1^belong[temp[j]]));
	// odp(j,belong[temp[j]]);
	gr
	if(pos!=n)
	{
		if(nextc[temp[pos+1]+1][belong[temp[pos+1]]]==0)
			Solver.addedge(pos+1+n*(belong[temp[pos+1]]^1),pos+1+n*(belong[temp[pos+1]]));
		if(nextc[temp[pos+1]+1][belong[temp[pos+1]]^1]==0)
			Solver.addedge(pos+1+n*(belong[temp[pos+1]]),pos+1+n*(1^belong[temp[pos+1]]));
	}
	if(Solver.Generate()==FAIL)continue;
	// pos is valid ~
	// odl(pos);
	
	// rg(n)odb(Solver.c[i]<Solver.c[i+n]);gr puts("");
	rg(pos)putchar(temp[i]+96);gr
	// if(pos!=n)putchar(nextc[temp[i+1]][])
	solver=Solver;
	for(int i=pos+1;i<=n;i++)
	{
		int lim=(i==pos+1?temp[i]+1:1);
		char t=127;
		if(nextc[lim][0])
		{
			Solver=solver;
			Solver.addedge(i,i+n);
			if(Solver.Generate()==SUCCESS)
			{
				t=min(t,nextc[lim][0]+96);
			}
		}
		if(nextc[lim][1])
		{
			Solver=solver;
			Solver.addedge(i+n,i);
			if(Solver.Generate()==SUCCESS)
			{
				t=min(t,nextc[lim][1]+96);
			}
		}
		putchar(t);
		if(belong[t-96])solver.addedge(i+n,i);
		else solver.addedge(i,i+n);
	}
	return 0;
	// return 0;
	gr
	puts("-1");
	/*for(int i=1;i<=n;i++)
		for(int j=h[i];j;j=e[j].nxt)
			if(c[i]!=c[e[j].v])R[c[e[j].v]]=1;
	for(int i=1;i<=r;i++)if(!R[i])ans=S[i],T++;
	if(T==1)printf("%d\n",ans);
	else puts("0");*/
    // puts("POSSIBLE");
    // for(int i=1;i<=n;i++)putchar((c[i]<c[i+n]?49:48)),putchar(32);
    // puts("");
	return 0;
}
// signed main()
// {
// 	
	// return 0;
// }