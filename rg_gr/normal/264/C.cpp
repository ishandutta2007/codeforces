// Problem: CF264C Choosing Balls
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF264C
// Memory Limit: 250 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
int c[200005],v[200005],dp[200005];
signed main()
{
	int n=read(),m=read();
	rg(n)v[i]=read();gr
	rg(n)c[i]=read();gr
	rg(m)int a=read(),b=read();
	memset(dp,-0x0f,sizeof(dp));
	int maxn=0,mxn=0,ans=0;
	rg(n)int x=max(b*v[i],dp[c[i]]+a*v[i]);
	if(c[i]!=maxn)x=max(x,dp[maxn]+b*v[i]);
	else x=max(x,dp[mxn]+b*v[i]);
	if(x>dp[maxn])if(maxn!=c[i])mxn=maxn,maxn=c[i];
	else;else if(c[i]!=maxn&&x>dp[mxn])mxn=c[i];
	dp[c[i]]=max(dp[c[i]],x),ans=max(ans,x);gr
	oldl(ans);gr
	return 0;
}