// Problem: B. Karen and Test
// Contest: Codeforces - Codeforces Round #419 (Div. 1)
// URL: https://codeforces.com/contest/815/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[n*2+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}
#define mgs int fa[1<<22],sz[1<<22],t[1<<22];\
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
	while(c<48||c>49)c=getchar();
	return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
const int mod=1000000007,inv2=mod/2+1;
int fac[200005],inv[200005];
int a[100][100];
inline int C(int n,int m)
{
	if(n<m)return 0;
	if(n==m||m==0)return 1;
	return inv[m]*inv[n-m]%mod*fac[n]%mod;
}
#define a qwq
int a[200005],cc[200005];
signed main()
{
	/*int n=read();
	for(int i=1;i<=n;i++){
	//rg(n)a[1][i]=read();gr
	memset(a,0,sizeof(a));
	a[1][i]=1;
	int f=0;
	rg(n)if(i==1)continue;rg_(j,n-i+1)
	if(f==0)a[i][j]=a[i-1][j]+a[i-1][j+1];
	else a[i][j]=a[i-1][j]-a[i-1][j+1];
	f^=1;;gr gr
	odb(a[n][1]);
	}
	*/
	int n=read();fac[0]=1;inv[1]=1;
	rg(n)fac[i]=fac[i-1]*i%mod;gr
	rg(n)if(i>1)inv[i]=inv[mod%i]*(mod-mod/i)%mod;gr
	rg(n)if(i>1)inv[i]*=inv[i-1],inv[i]%=mod;gr
//	int n=read();
	rg(n)a[i]=read();gr
//	oldl(C());
	int ans=0;
	if(n%4==1)
	{
		rg((n+1)>>1)ans=ans+C((n)>>1,i-1)*(a[i*2-1])%mod,ans%=mod;gr
	}
	else if(n%4==2)
	{
		rg(n>>1)ans=ans+C((n>>1)-1,i-1)*(a[i*2-1]+a[i*2])%mod,ans%=mod;gr
	}
	else if(n%4==3)
	{
		int base=(n-3)/2;
		rg(n>>1)cc[i<<1]=C(base,i-1)*2%mod;gr
		rg(n)if(i&1)cc[i]=(cc[i+1]-cc[i-1])*inv2%mod;
		ans+=cc[i]*a[i]%mod;ans%=mod;gr
	}
	else 
	{
		rg(n>>1)ans=ans+C((n>>1)-1,i-1)*(a[i*2-1]-a[i*2])%mod,ans%=mod;gr
	}
	ans%=mod;ans+=mod;ans%=mod;
	oldl(ans);
	return 0;
}