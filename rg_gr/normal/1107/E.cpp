// Problem: CF1107E Vasya and Binary String
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1107E
// Memory Limit: 250 MB
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
int a[105],dp[105][105][105][2],q[105][105],f[105];
signed main()
{
	int n=read();
	rg(n)a[i]=re1d();gr
	rg(n)f[i]=read();gr
	memset(dp,-0x3f,sizeof(dp));
	memset(q,-0x3f,sizeof(q));
	rg(n)dp[i][i][0][a[i]]=f[1];q[i][i]=f[1];dp[i][i][1][a[i]]=0;dp[i][i][0][a[i]^1]=f[1];gr
	rg(n)dp[i][i][0][0]=dp[i][i][0][1]=0;gr
	rg(n)q[i][i+1]=0;gr
	rg(n)rg_(j,i-1)f[i]=max(f[i],f[j]+f[i-j]);gr gr
	for(int L=2;L<=n;L++)
	{
		for(int l=1,r=L;r<=n;l++,r++)
		{
			for(int k=0;k<=L;k++)
			{
				if(k)dp[l][r][k][a[r]]=dp[l][r-1][k-1][a[r]];
				for(int s=l;s<=r;s++)
					dp[l][r][k][0]=max(dp[l][r][k][0],dp[l][s][k][0]+q[s+1][r]),
					dp[l][r][k][1]=max(dp[l][r][k][1],dp[l][s][k][1]+q[s+1][r]);
				q[l][r]=max(q[l][r],dp[l][r][k][0]+f[k]);
				q[l][r]=max(q[l][r],dp[l][r][k][1]+f[k]);
			}
			// dp[l][r]=max(dp[l+1][r],dp[l][r-1])+f[1];
			// for(int i=l+1;i<=r;i++)
				// if(a[i]==a[l])dp[l][r]=max(dp[l][r],f[i-l+1]+dp[i+1][r]);
				// else break;
			// for(int i=r-1;i>=l;i--)
				// if(a[i]==a[r])dp[l][r]=max(dp[l][r],f[r-i+1]+dp[l][i-1]);
				// else break;
			// for(int i=l+1;i<=r;i++)
			// {
				// if(a[i]!=a[l])break;
				// for(int j=r-1;j>=l;j--)
					// if(a[j]==a[r])dp[l][r]=max(dp[l][r],f[r-j+1+i+l+1]+dp[i+1][j-1]);
					// else break;
			// }
		}
	}
	// odl(dp[2][2][1][0]);
	// rg(n)rg_(j,n)if(q[i][j]>=0)printf("%4d",q[i][j]);else printf("    ");gr puts("");gr
	// rg(n)rg_(j,n)rg_(k,j-i+1)for(int p=0;p<2;p++)printf("%d %d %d %d : %d\n",i,j,k,p,dp[i][j][k][p]);
	// gr gr gr
	
	// rg(n)rg_(j,n)if(q[i][j]>=0)printf("%4d",q[i][j]);else printf("    ");gr puts("");gr
	assert(q[1][n]>=n*f[1]);
	oldl(q[1][n]);
	return 0;
}