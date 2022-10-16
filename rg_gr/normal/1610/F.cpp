// Problem: F. Mashtali: a Space Oddysey
// Contest: Codeforces - Codeforces Global Round 17
// URL: https://codeforces.com/contest/1610/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
struct edge{
	int v,id;
	bool operator<(const edge& b)const{
		return v==b.v?(id<b.id):v<b.v;
	}
};
std::multiset<edge> s[2][200005];
int dir[1000005];
int cc;
mgs
void prework(int u,int S)
{
	// 
	// odl(u);dflush(stdout);
	auto& st=s[S][u];
	while(st.size()>1)
	{
		// puts("?");dflush(stdout);
		debug('?');dflush(stdout);
		auto x=st.begin();debug('?');dflush(stdout);
		edge a=*x;st.erase(x);debug('?');dflush(stdout);
		x=st.begin();edge b=*x;st.erase(x);debug('?');dflush(stdout);
		//shan biandebug('?');dflush(stdout);
		int v1=a.v,v2=b.v;debug('?');dflush(stdout);
		debug(u,' ',v1,' ',v2,' ',S,'\n');
		x=s[S][v1].lower_bound((edge){u,0});debug('?');dflush(stdout);
		int id1=x->id;s[S][v1].erase(x);debug('?');dflush(stdout);
		x=s[S][v2].lower_bound((edge){u,0});debug('?');dflush(stdout);
		int id2=x->id;s[S][v2].erase(x);debug('?');dflush(stdout);
		++cc;debug('?');dflush(stdout);//print(cc,'\n');
		// printf("add %d %d , delete %d %d and %d %d\n",v1,v2,u,v1,u,v2);
		if(v1!=v2)s[S][v1].insert((edge){v2,cc*2-2});debug('?');dflush(stdout);
		if(v1!=v2)s[S][v2].insert((edge){v1,cc*2-1});debug('?');dflush(stdout);
		if(v1==v2)dir[cc*2-2]=1;
		fa[cc*2-2]=cc*2-2;debug('?');dflush(stdout);
		fa[cc*2-1]=cc*2-1;debug('?');dflush(stdout);
		fa[id1]=cc*2-2;debug('?');dflush(stdout);
		fa[id2^1]=cc*2-2;debug('?');dflush(stdout);
		fa[id1^1]=cc*2-1;debug('?');dflush(stdout);
		fa[id2]=cc*2-1;debug('?');dflush(stdout);
		prework(v1,S);debug('?');dflush(stdout);
		prework(v2,S);debug('?');dflush(stdout);
		debug('\n');
	}
}
int U[1000005],V[1000005],W[1000005],deg[1000005],vis[1000005],G[1000005];
void dfs(int u,int S)
{
	if(vis[u])return;vis[u]=1;
	if(s[S][u].size()==0)return;
	auto x=s[S][u].begin();
	int id=x->id,v=x->v;
	dfs(v,S^1);
	if(S)dir[id]=1,debug('+',id,'\n');
	else dir[id]=1,debug('+',id,'\n');
}
signed main()
{
	int n=read(),m=read();cc=m;
	rg(m)int u=read(),v=read(),w=read()-1;
	U[i]=u,V[i]=v,W[i]=w;if(w==0)G[u]^=1,G[v]^=1;
	s[w][u].insert((edge){v,i*2-2});
	s[w][v].insert((edge){u,i*2-1});gr
	rrg(m+m)fa[i]=i;
	rg(n)prework(i,0);gr
	// print('\n');
	// int C0=cc;cc=m;int& C1=cc;C1=m;
	rg(n)prework(i,1);gr
	int ans=0;
	rg(n)ans+=G[i];gr
	odl(ans);
	// rg(n)if(deg)
	// rg(n)for(auto x:s[0][i])print(i,' ',x.v,' ',1,'\n');gr
	// rg(n)for(auto x:s[1][i])print(i,' ',x.v,' ',2,'\n');;gr
	// rg(cc)print(f(i*2-2),'\n',f(i*2-1),'\n');gr
	rg(n)for(auto x:s[0][i])deg[x.v]++;gr
	rg(n)for(auto x:s[1][i])deg[x.v]++;gr
	rg(n)if(!vis[i]&&deg[i]==1)dfs(i,s[0][i].size()?0:1);gr
	rg(n)if(!vis[i]&&deg[i]==2)dfs(i,1);gr
	rg(m)print(dir[f(i*2-2)]+1);gr
	return 0;
}