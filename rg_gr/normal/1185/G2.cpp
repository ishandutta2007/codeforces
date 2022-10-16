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
// #prag
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
// int dp[3][2504];
int fac[2504],g[55][55][55][3];
int tim[55],Id[55],sz[3];
int ****dp;//what's this????
const int mod=1000000007;
signed main()
{
/*
	dp[i][j][k][l] 
	
	id i j ksum=l
	
	
	
*/
	int n=read(),m=read();
	// dp[0][0]=dp[1][0]=dp[2][0]=1;
	rg(n)int g=read(),id=read()-1;
	tim[i]=g,Id[i]=id,sz[id]++;
	// for(int i=m;i>=g;i--)dp[id][i]=(dp[id][i]+dp[id][i-g])%mod;
	gr
	// rrg(m+1)odb(dp[0][i]),odp(dp[1][i],dp[2][i]);
	// g[0][0][0][]=1;
	g[0][0][1][2]=g[1][0][0][0]=g[0][1][0][1]=1;
	rg_(s,n)
	for(int i=0;i<=s;i++)
		for(int j=0;j+i<=s;j++)
		{
			int k=s-i-j;
			(g[i][j][k+1][2]+=g[i][j][k][1]+g[i][j][k][0])%=mod;
			(g[i][j+1][k][1]+=g[i][j][k][0]+g[i][j][k][2])%=mod;
			(g[i+1][j][k][0]+=g[i][j][k][2]+g[i][j][k][1])%=mod;
		}
	gr
	
	//solve the dp???
	// printf("%d %d %d\n",sz[0],sz[1],sz[2]);fflush(stdout);
	// return 0;
	dp=new int***[sz[0]+2];
	for(int i=0;i<sz[0]+2;i++)
	{
		dp[i]=new int**[sz[1]+2];
		for(int j=0;j<sz[1]+2;j++)
		{
			dp[i][j]=new int*[sz[2]+2];
			for(int k=0;k<sz[2]+2;k++)
			{
				dp[i][j][k]=new int[m+2];
				for(int t=0;t<m+2;t++)dp[i][j][k][t]=0;
			}
		}
	}
	sz[0]=sz[1]=sz[2]=0;
	dp[0][0][0][0]=1;
	rg(n)int qwq=i;
	for(int i=sz[0];i>=0;i--)
		for(int j=sz[1];j>=0;j--)
			for(int k=sz[2];k>=0;k--)
				for(int t=m-tim[qwq];t>=0;t--)
					(dp[i+(Id[qwq]==0)][j+(Id[qwq]==1)][k+(Id[qwq]==2)][t+tim[qwq]]+=dp[i][j][k][t])%=mod;
	
	sz[Id[qwq]]++;
	gr
	fac[0]=1;
	int ans=0;
	rg(m)fac[i]=fac[i-1]*i%mod;gr
	for(int i=0;i<=sz[0];i++)
		for(int j=0;j<=sz[1];j++)
			for(int k=0;k<=sz[2];k++)
				ans=(ans+fac[i]*fac[j]%mod*fac[k]%mod*(g[i][j][k][0]+g[i][j][k][1]+g[i][j][k][2])%mod*dp[i][j][k][m])%mod;
	oldl(ans);
	// for(int i=0;i<=n;i++)
		// for(int j=0;j+i<=n;j++)
			// for(int k=0;i+j+k<=n;k++)
			// {
				// // int k=m-i-j;
				// #define G g[i][j][k]
				// if((G[0]+G[1]+G[2])==0)continue;
				// printf("%d %d %d\n",i,j,k);
				// ans=(ans+dp[0][i]*dp[1][j]%mod*dp[2][k]%mod*(G[0]+G[1]+G[2])%mod*fac[i]%mod*fac[j]%mod*fac[k])%mod;
			// }
	
	// oldl(ans);
	return 0;
}