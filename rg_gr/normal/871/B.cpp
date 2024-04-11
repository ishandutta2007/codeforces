// Problem: B. Something with XOR Queries
// Contest: Codeforces - Codeforces Round #440 (Div. 1, based on Technocup 2018 Elimination Round 2)
// URL: https://codeforces.com/contest/871/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
//#define int long long
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
int p[5005],b[5005];
int r[5005],d[5005];
inline int q(int i,int j)
{
	printf("? %d %d\n",i,j);
	fflush(stdout);
	return read();
}

signed main()
{
	int n=read(),c=0,ans=0;
	rg(n)d[i-1]=q(i-1,i-1);if(i!=n)r[i-1]=q(i-1,i%n);gr
	rg(n)p[0]=i-1,b[0]=p[0]^d[0];
	rg(n-1)b[i]=p[i-1]^r[i-1],p[i]=b[i]^d[i];gr
	
//	rg(n)odp(p[i],b[i]);gr puts("");
	
	rg(n)if(p[i-1]<0||b[i-1]<0||p[i-1]>=n||b[i-1]>=n)goto fail;gr
	rg(n)if(b[p[i-1]]!=i-1)goto fail;gr
	c++,ans=i;
	fail:;
	gr
	puts("!");fflush(stdout);
	odl(c);fflush(stdout);
//	rg(n)
	p[0]=ans-1,b[0]=p[0]^d[0];
	rg(n-1)b[i]=p[i-1]^r[i-1],p[i]=b[i]^d[i];gr
	rg(n)odb(p[i-1]);gr puts("");fflush(stdout);
	return 0;
}