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
#define newe(n) struct Edge{int v,nxt;}e[n*2+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v){e[cnt]=(Edge){v,h[u]};h[u]=cnt++;deg[v]++;}
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
#define fe(u) for(int i=h[u];i;i=e[i].nxt){int v=e[i].v;

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
int **a,**b;
int ans[100005],deg[1000005];
newe(500000)
inline void topo(int n,int m)
{
	std::queue<int>q;
	int cc=0;
	rg(n*m+1)
	if(deg[i-1]==0)q.push(i-1);
	gr
	while(!q.empty())
	{
		int u=q.front();
		if(1<=u&&u<=m)ans[++cc]=u;
		q.pop();
		fe(u)deg[v]--;
		if(deg[v]==0)q.push(v);
		gr
	}
}
#define ae addedge
signed main()
{
	int n=read(),m=read();
	int cc=m;
	a=new int*[n+1];b=new int*[n+1];
	rg(n)a[i]=new int[m+1];b[i]=new int[m+1];
	rg_(j,m)int x=read();if(x==-1)x=1000000007;b[i][j]=a[i][j]=x;gr gr
	rg(n)std::sort(b[i]+1,b[i]+1+m);
	int len=std::unique(b[i]+1,b[i]+1+m)-b[i];
	rg_(j,m)if(a[i][j]<1000000007)a[i][j]=std::lower_bound(b[i]+1,b[i]+len,a[i][j])-b[i];gr gr
//	rg(n)rg_(j,m)odb(a[i][j]);gr puts("");gr
	rg(n)rg_(j,m)
	if(a[i][j]==1)ae(0,j),ae(j,m*i+1);
	else if(a[i][j]<1000000007)ae(m*i+a[i][j]-1,j),ae(j,m*i+a[i][j]);
	gr gr
	topo(n,m);
	rg(m)if(ans[i]==0)return puts("-1")&0;gr
	rg(m)odb(ans[i]);gr
	return 0;
}