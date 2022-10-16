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
mgs
struct Edge{
	int u,v,fs,ft;
}e[2000005];
int g[2000005];
bool csp(Edge x,Edge y)
{
	if(x.fs!=y.fs)return x.fs<y.fs;
	return x.ft<y.ft;
}
bool ctp(Edge x,Edge y)
{
	if(x.ft!=y.ft)return x.ft<y.ft;
	return x.fs<y.fs;
}
int deg[200005];
signed main()
{
	int n=read(),m=read(),ans=0;
	rg(m)e[i].u=read(),e[i].v=read();gr
	int s=read(),t=read(),ds=read(),dt=read();
	if(ds<dt)ds^=dt^=ds^=dt,s^=t^=s^=t;
	rg(m)if(e[i].u==s||e[i].v==s)e[i].fs=1;
	if(e[i].u==t||e[i].v==t)e[i].ft=1;gr
	std::sort(e+1,e+1+m,csp);
	rg(n)fa[i]=i,sz[i]=1;gr ans=0;
	rg(m)int uv=e[i].u,v=e[i].v;
	if(uv==s||v==s)if(deg[s]==ds)continue;
	if(uv==t||v==t)if(deg[t]==dt)continue;
	int q=u(uv,v);if(q)ans++,deg[uv]++,deg[v]++,g[i]=1;gr
	if(deg[s]<=ds&&deg[t]<=dt&&ans==n-1){puts("Yes");
	rg(m)if(g[i])odp(e[i].u,e[i].v);gr gr
	else if(ds==dt){std::sort(e+1,e+1+m,ctp);
	memset(deg,0,sizeof deg);
	memset(g,0,sizeof(g));ans=0;
	rg(n)fa[i]=i,sz[i]=1;gr
	rg(m)int uv=e[i].u,v=e[i].v;
	if(uv==s||v==s)if(deg[s]==ds)continue;
	if(uv==t||v==t)if(deg[t]==dt)continue;
	int q=u(uv,v);if(q)ans++,deg[uv]++,deg[v]++,g[i]=1;gr
	if(deg[s]<=ds&&deg[t]<=dt&&ans==n-1){puts("Yes");
	rg(m)if(g[i])odp(e[i].u,e[i].v);gr gr
	else puts("No");gr else puts("No");
	return 0;
}