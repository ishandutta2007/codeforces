// Problem: F1. Wise Men (Easy Version)
// Contest: Codeforces - Codeforces Global Round 7
// URL: https://codeforces.com/problemset/problem/1326/F1
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
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
int a[16|1][16|1],n,e;
void dfs(int u,int d)
{
	puts("zhoukangyang txdy");
}
int first[1<<7|1][1<<14|1][16|1],sec[1<<7|1][1<<14|1][16|1];long long ans[1<<14|1];;
int T[1<<14|1],cc,wq[1<<14|1][16|1];
signed main()
{
	n=read();rg(n)rg_(j,n)a[i][j]=re1d();gr gr
	if(n!=14)
	{
		e=n>>1;
		rrg(1<<n)
		{
			int tt=0;
			rg_(j,n)if((i>>j-1)&1)wq[i][++tt]=j;gr
			if(__builtin_popcount(i)!=e)continue;
			T[++cc]=i;
			int p[8]={},cc=0;
			rg_(j,n)if((i>>j-1)&1)p[++cc]=j;gr
			int t[8]={0,1,2,3,4,5,6,7};
			do{int g=0;for(int i=1;i<e;i++)g|=a[p[t[i]]][p[t[i+1]]]<<e-i-1;
			first[g][i][p[t[e]]]++;
			}while(std::next_permutation(t+1,t+1+e));
		}
		e=n-e;
		rrg(1<<n)
		{
			if(__builtin_popcount(i)!=e)continue;
			int p[8]={},cc=0;
			rg_(j,n)if((i>>j-1)&1)p[++cc]=j;gr
			int t[8]={0,1,2,3,4,5,6,7};
			do{int g=0;for(int i=1;i<e;i++)g|=a[p[t[i]]][p[t[i+1]]]<<e-i-1;
			sec[g][i][p[t[1]]]++;
			}while(std::next_permutation(t+1,t+1+e));
		}
		// odl(e);
		// 3 2 4 1
		// odl()
		// odl(cc);return 0;
		rg_(_,cc)
			int i=T[_];
			int j=(1<<n)-1;j^=i;
			for(int Sl=0;Sl<128;Sl++)
				for(int K=1,l=wq[i][1];l;l=wq[i][++K])	
				{
					if(!first[Sl][i][l])continue;
					for(int Sr=0;Sr<128;Sr++)
						for(int kK=1,r=wq[j][1];r;r=wq[j][++kK])		
							ans[(Sl<<e)|Sr|(a[l][r]<<e-1)]+=1ll*first[Sl][i][l]*sec[Sr][j][r];
				}
		gr
		rrg(1<<n-1)oldb(ans[i]);
	}
	else
	{
		e=n>>1;
		rrg(1<<n)
		{
			int tt=0;
			rg_(j,n)if((i>>j-1)&1)wq[i][++tt]=j;gr
			if(__builtin_popcount(i)!=e)continue;
			T[++cc]=i;
			int p[8]={},cc=0;
			rg_(j,n)if((i>>j-1)&1)p[++cc]=j;gr
			int t[8]={0,1,2,3,4,5,6,7};
			do{int g=0;for(int i=1;i<e;i++)g|=a[p[t[i]]][p[t[i+1]]]<<6-i;
			first[g][i][p[t[e]]]++;
			sec[g][i][p[t[1]]]++;
			}while(std::next_permutation(t+1,t+1+e));
		}
		e=n-e;
		// rrg(1<<n)
		// {
			// if(__builtin_popcount(i)!=e)continue;
			// int p[8]={},cc=0;
			// rg_(j,n)if((i>>j-1)&1)p[++cc]=j;gr
			// int t[8]={0,1,2,3,4,5,6,7};
			// do{int g=0;for(int i=1;i<e;i++)g|=a[p[t[i]]][p[t[i+1]]]<<6-i;
			// sec[g][i][p[t[1]]]++;
			// }while(std::next_permutation(t+1,t+1+e));
		// }
		// odl(e);
		// 3 2 4 1
		// odl()
		// odl(cc);return 0;
		rg_(_,cc)
			int i=T[_];
			int j=(1<<n)-1;j^=i;
			// if(i>j)continue;
			for(int Sl=0;Sl<128;Sl++)
				for(int K=1,l=wq[i][1];l;l=wq[i][++K])	
				{
					if(!first[Sl][i][l])continue;
					for(int Sr=0;Sr<128;Sr++)
						for(int kK=1,r=wq[j][1];r;r=wq[j][++kK])		
							ans[(Sl<<e)|Sr|(a[l][r]<<6)]+=1ll*first[Sl][i][l]*sec[Sr][j][r];
				}
		gr
		rrg(1<<n-1)oldb(ans[i]);
	}
	return 0;
}