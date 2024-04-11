// Problem: A. Road to Cinema
// Contest: Codeforces - Codeforces Round #380 (Div. 1, Rated, Based on Technocup 2017 - Elimination Round 2)
// URL: https://codeforces.com/contest/737/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int c[200005],v[200005],g[200005],r[200005];
inline int chack(int w,int m,int t)
{
	int ct=0;
	rg(m)
	int d=g[i]-g[i-1];
	if(w<d)
	{
		ct=0x3f3f3f3f3f3f3f3fll;
		break;
	}
	int v=min(w,d*2);
	int x=d+d-v;
	ct+=x+d;
	gr
	return ct<=t;
}
signed main()
{
	int n=read(),m=read(),s=read(),t=read();
	rg(n)c[i]=read(),v[i]=read();gr
	rg(m)g[i]=read();gr g[++m]=s;
	std::sort(g+1,g+1+m);
	int ans=0,p=0x3f3f3f3f3f3f3f3fll;
	int l=0,r=2000000001,kuaikule=r;
	while(l<=r)
	{
		int M=l+r>>1;
		if(chack(M,m,t))kuaikule=M,r=M-1;
		else l=M+1;
	}
//	odl(kuaikule);
	rg(n)if(v[i]>=kuaikule)p=min(p,c[i]);gr
/*	rg(n)
	int ct=0;
	int w=v[i];
	
	if(ct>t)continue;
	if(c[i]<p)p=c[i],ans=i;
	gr*/
	if(p!=0x3f3f3f3f3f3f3f3fll)oldl(p);
	else puts("-1");
	return 0;
}