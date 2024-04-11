// Problem: F. Koala and Notebook
// Contest: Codeforces - Codeforces Round #584 - Dasha Code Championship - Elimination Round (rated, open for everyone, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1209/problem/F
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
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}//printf("%d %d %d\n",u,v,w);}
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
newe(1400005);
const int mod=1000000007;
arr dis,ans,pre,F,q,t;
int multiply(int u,int v,int w)
{
	addedge(u,v,w);
	// addedge(v,u,w);
}
#define addedge multiply
signed main()
{
	int n=read(),m=read(),cc=n;
	rg(m)int u=read(),v=read(),id=i,t[7]={},d=0;
	while(id)t[++d]=id%10,id/=10;
	if(d==1)
	{
		addedge(u,v,t[1]);
		addedge(v,u,t[1]);
		continue;
	}
	++cc;addedge(u,cc,t[d]);
	for(int e=d-1;e>1;e--)addedge(cc,cc+1,t[e]),cc++;
	addedge(cc,v,t[1]);
	u^=v^=u^=v;id=i;d=0;
	while(id)t[++d]=id%10,id/=10;
	if(d==1)
	{
		addedge(u,v,t[1]);
		addedge(v,u,t[1]);
		continue;
	}
	++cc;addedge(u,cc,t[d]);
	for(int e=d-1;e>1;e--)addedge(cc,cc+1,t[e]),cc++;
	addedge(cc,v,t[1]);
	gr
	// std::queue<int>q;q.push(1);
	int head=1,tail=1;q[head]=1;
	int predis=0;
	while(head<=tail)
	{
		// printf("? [%d %d]\n",head,tail);
		// int u=q.front();q.pop();
		int u=q[head++];
		if(dis[u]!=predis)
		{
			// odp(head,tail);
			head--;
			predis=dis[u];
			int *a=q+head-1,L=tail-head+1;
			std::sort(a+1,a+1+L,[&](int x,int y){return ans[x]<ans[y];});
		//	rg(L)odb(a[i]);gr puts("");
			ans[0]=100;
			
			rg(L)
			if(i==1)t[a[i]]=20;
			else t[a[i]]=(ans[a[i-1]]!=ans[a[i]]?t[a[i-1]]+20:t[a[i-1]]);gr
			rg(L)F[a[i]]=F[pre[a[i]]]*10+ans[a[i]]%10;F[a[i]]%=mod;gr
			continue;
		}
		// ans[u]=ans[pre[u]]
		fe(u)
		if(v==1)continue;
		if(dis[v]==dis[u]+1||dis[v]==0)
		{
			int w=t[u]+e[i].w;
			// ans[v]=(ans[v]==0?w:min(ans[v],w));
			if(ans[v]==0||ans[v]>w)
			{
				ans[v]=w;
				pre[v]=u;
			}
		}
		if(dis[v])continue;
		dis[v]=dis[u]+1;//q.push(v);
		q[++tail]=v;
		gr
	}
	// rg(n)odb(dis[i]);gr puts("");
	// rg(n)odb(t[i]);gr puts("");
	// rg(n)odb(ans[i]);gr puts("");
	// rg(n)odb(pre[i]);gr puts("");
	rg(n-1)odl(F[i+1]);gr
	return 0;
}