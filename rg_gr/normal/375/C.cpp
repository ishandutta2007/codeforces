// Problem: P2566 [SCOI2009]
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2566?contestId=59778
// Memory Limit: 225 MB
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
void print<double>(double x){printf("%.22lf",x);}
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
void debug<double>(double x){printf("%.22lf",x);}
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
    while(c<48||c>57){if(c=='.')return 0;if(c=='#')return -1;if(c=='B')return -2;if(c=='S')return -3;c=getchar();}
    return c-48;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int w[105],xx[105],yy[105],W[100005],a[22][332];
int n=read(),m=read(),c;
// int c=read();
int d[22][22][1<<10];
struct pair{
	int x,y,S;
};
int solve(int i,int j)
{
	memset(d,0x3f,sizeof(d));
	int inf=d[0][0][0];
	d[i][j][0]=0;
	std::queue<pair>q;
	q.push((pair){i,j,0});
	while(!q.empty())
	{
		auto u=q.front();q.pop();
		int x=u.x,y=u.y,S=u.S;
		// printf("%d %d: %d %d %d  %d\n",i,j,x,y,S,d[x][y][S]);
		#define test(aa,b) \
		{\
			int X=x+aa,Y=y+b;\
			if(X>=1&&X<=n&&Y>=1&&Y<=m&&a[X][Y]==0)\
			{\
				int s=S;\
				rg_(j,c)\
				if(x<X&&X==xx[j]&&Y<yy[j]||x>X&&x==xx[j]&&y<yy[j])s^=1<<j-1;\
				gr\
				if(d[X][Y][s]==inf)d[X][Y][s]=d[x][y][S]+1,q.push((pair){X,Y,s});\
			}\
		}
		test(1,0);
		test(-1,0);
		test(0,1);
		test(0,-1);	
	}
	int ans=0;int I=i;
	rrg(1<<c){
		ans=max(ans,W[i]-d[I][j][i]);
	}
	// printf("%d %d : %d\n",i,j,ans);
	return ans;
} 
signed main()
{
	int &cc=c;int sx,sy;
	rg(n)rg_(j,m)
	int t=re1d();a[i][j]=t;
	if(t>0)xx[t]=i,yy[t]=j,cc=max(cc,t);
	if(t==-3)sx=i,sy=j,a[i][j]=0;
	gr gr
	c=cc;
	rg(c)w[i]=read();gr
	rg(n)rg_(j,m)if(a[i][j]==-2)++cc,xx[cc]=i,yy[cc]=j,w[cc]=-1e9,a[i][j]=cc;gr gr
	// rg(n)rg_(j,m)odb(a[i][j]);gr puts("");gr
	// rg(c)odb(xx[i]),odp(yy[i],w[i]);gr
	// odl(c);
	rg((1<<c)-1)rg_(j,c)if((i>>j-1)&1)W[i]+=w[j];gr gr
	int ans=0;
	// rg(n)rg_(j,m)if(a[i][j]==0)ans=max(ans,solve(i,j));gr gr
	oldl(solve(sx,sy));
	return 0;
}