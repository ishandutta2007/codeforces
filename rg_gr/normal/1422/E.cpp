// Problem: E. Minlexes
// Contest: Codeforces - Codeforces Round #675 (Div. 2)
// URL: https://codeforces.com/contest/1422/problem/E
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
    fa[fx]=fy;\
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
char a[1000005];
int paired[1000005];
// mgs
std::set<int>s;
// struct 
// int b[1000005],c[1000005],d[1000005];
const int Q=11;
struct gans{
	char a[Q+4],f;
	char* b=a+Q-1;
	int L;
	void add(char x)
	{
		if(L<=Q)
		{
			for(int i=Q+1;i>1;i--)a[i]=a[i-1];
			a[1]=x;
		}
		else
		{
			for(int i=Q-1;i>1;i--)a[i]=a[i-1];
			a[1]=x;
		}
		if(a[1]!=a[2])
		{
			f=(a[1]<a[2]);
		}
		L++;
		if(L==Q)
		{
			b--;
			
		}
		if(L==Q+1)b++;
		// odl(b-a);
	}
	bool operator<(const gans& c)const
	{
		for(int i=1;i<=10;i++)if(a[i]!=c.a[i])return a[i]<c.a[i];
		return c.f;
	}
}ans[1000005];
signed main()
{
	scanf("%s",a+1);int n=strlen(a+1);
	// rg(n+1)fa[i]=i;gr
	rg(n+1)s.insert(i);gr
	int L=n;
	for(int i=n;i>=1;i--)
	{
		if(a[i]!=a[i+1])
		{
			ans[i]=ans[i+1];
			ans[i].add(a[i]);
		}
		else
		{
			gans b=ans[i+2];
			b.add(a[i]);b.add(a[i]);
			if(b<ans[i+2])ans[i]=b;
			else ans[i]=ans[i+2];
		}
	}
	rg(n)
	odb(ans[i].L);
	// odl((ans[i].b-ans[i].a)/sizeof(char));
	if(ans[i].L<=Q-1)printf("%s\n",ans[i].a+1);
	else printf("%c%c%c%c%c...%c%c\n",ans[i].a[1],ans[i].a[2],ans[i].a[3],ans[i].a[4],ans[i].a[5],ans[i].a[ans[i].L==Q?Q-1:Q],ans[i].a[ans[i].L==Q?Q:Q+1]);
	gr
	// // rg(100000)
		// // int g=0;
		// // // for(int i='z';i>='a';i--)
		// // // {
			// // // for(int j=n;j>=2;j--)
			// // auto x=s.end();
			// // for(--x;x!=s.begin();)
			// // {
				// // // if(!s.count(j))continue;
				// // int j=*x;
				// // // odl(j);fflush(stdout);
				// // // auto it=s.lower_bound(j);
				// // auto it=x;
				// // --it;
				// // int k=*it;
				// // ++it;
				// // ++it;
				// // int l=*it;			
				// // if(a[j]==a[k]&&a[j]>a[l])
				// // {
					// // paired[k]=j;
					// // paired[j]=k;
					// // --x;
					// // --x;
					// // s.erase(j);
					// // s.erase(k);
					// // L-=2;
					// // g=1;
				// // }
				// // else x--;
			// // }
		// // if(!g)break;
	// // gr
	// // s.erase(n+1);
	// rg(n)
	// // odl(n);
	// // assert(L==s.size());
	// // odp(L,s.size());
	// odb(L);
	// if(s.size()<=10)
	// {
		// for(auto x:s)putchar(a[x]);
	// }
	// else
	// {
		// auto it=s.begin();
		// putchar(a[*it]);++it;
		// putchar(a[*it]);++it;
		// putchar(a[*it]);++it;
		// putchar(a[*it]);++it;
		// putchar(a[*it]);++it;
		// it=s.end();--it;--it;
		// printf("...");
		// putchar(a[*it]);++it;
		// putchar(a[*it]);++it;
	// }
	// puts("");
	// if(paired[i])
	// {
		// L++;
		// paired[paired[i]]=0;
		// s.insert(paired[i]);
	// }
	// else L--,s.erase(i);
	// gr
	return 0;
}