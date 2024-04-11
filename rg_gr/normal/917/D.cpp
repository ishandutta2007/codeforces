
// ![](https://static.xjoi.net/images/emoticon-1.gif)

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
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <assert.h>
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
#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[2*n+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}
#define mgs int fa[1<<22],sz[1<<22];\
inline int f(int x){return x==fa[x]?x:fa[x]=f(fa[x]);}\
inline int u(int x,int y)\
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
    while(c!='#'&&c!='.')c=getchar();
    return c=='.';
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
newe(8005);
//  5555
mgs
arr x,y,ans,pow10_xyx;
const int mod=1000000007;
int n=read();
int fac[8005],inv[8005];
int *dp[8005],*dq[8005],bp[8005],bq[8005];;
void dfs(int u,int fa)
{
    sz[u]=1;
    dp[u]=new int[sz[u]];
    dq[u]=new int[sz[u]];
    dp[u][0]=1;
    dq[u][0]=1;
    fe(u)if(v==fa)continue;dfs(v,u);
    memset(bp,0,sizeof(bp));
    memset(bq,0,sizeof(bq));
    for(int i=0;i<sz[u];i++)
        for(int j=0;j<sz[v];j++)
            bp[i+j]=(bp[i+j]+dp[u][i]*dp[v][j])%mod,
            bp[i+j+1]=(bp[i+j+1]+dp[u][i]*dq[v][j]+dq[u][i]*dp[v][j])%mod,
            bq[i+j]=(bq[i+j]+dq[u][i]*dp[v][j])%mod,
            bq[i+j+1]=(bq[i+j+1]+dq[u][i]*dq[v][j])%mod;
    sz[u]+=sz[v];
    delete[] dp[u];
    delete[] dq[u];
    dp[u]=new int[sz[u]];
    dq[u]=new int[sz[u]];
    rrg(sz[u])dp[u][i]=bp[i],dq[u][i]=bq[i];
    delete[] dp[v];
    delete[] dq[v];
    gr
}
inline int C(int n,int m)
{
    if(n==m||m==0)return 1;
    if(n<m)return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main()
{
	pow10_xyx[0]=1;
	rg(n)pow10_xyx[i]=pow10_xyx[i-1]*n%1000000007;gr
	// rg(n-1)int x=read(),y=read();
	// addedge(x,y,i-1),addedge(y,x,i-1);gr
	rg(n-1)x[i]=read(),y[i]=read();
    addedge(x[i],y[i],1);
    addedge(y[i],x[i],1);
    gr
    dfs(1,1);
    // int ans=0;
    // rg(n)odb(dp[1][i-1]); gr
    // oldl(ans);
    // return 0;
	// for(int i=0;i<(1<<n-1)-1;i++)
	// {
	// 	rg(n)sz[i]=1,fa[i]=i;gr
	// 	rg_(_,n-1)if((i>>_-1)&1)u(x[_],y[_]);gr
	// 	int s=1;
	// 	rg(n)if(fa[i]==i)s=s*sz[i]%1000000007;gr
	// 	int pigstdwinwinwiwniwnwinwinwiwin=__builtin_popcount(i);
	// 	// printf("%lld %lld %lld\n",i,pigstdwinwinwiwniwnwinwinwiwin,s);
	// 	ans[pigstdwinwinwiwniwnwinwinwiwin]=(ans[pigstdwinwinwiwniwnwinwinwiwin]+pow10_xyx[(n-pigstdwinwinwiwniwnwinwinwiwin)-2]*s)%1000000007;
	// }
	// ans[n-1]=1;
	// rg(n)oldb(ans[i-1]);gr puts("");
	// rrg(n+1)C[i][i]=C[i][0]=1;
    fac[0]=inv[0]=inv[1]=1;
    rg(n)fac[i]=fac[i-1]*i%mod;gr
    rg(n)if(i>1)inv[i]=inv[mod%i]*(mod-mod/i)%mod;gr
    rg(n)inv[i]=inv[i]*inv[i-1]%mod;gr
	// rg(n)rg_(j,n)C[i][j]=C[i-1][j-1]+C[i-1][j];gr gr
	// rg(n)
	rrg(n-1)ans[i]=(pow10_xyx[n-i-2]*dp[1][i])%mod;
    ans[n-1]=1;
    // rrg(n)odb(ans[i]); puts("");
	// // gr
	// //for(int i=n-2;i>=0;i--)
	rrg(n-1)
		for(int j=i+1;j<n;j++)
			if((i+j)&1)ans[i]=(ans[i]-ans[j]*C(j,i))%1000000007;
			else ans[i]=(ans[i]+ans[j]*C(j,i))%1000000007;
	rg(n)oldb(ans[i-1]<0?ans[i-1]+1000000007:ans[i-1]);gr
	return 0;
}