// Problem: CF786B Legacy
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF786B
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
#define int long long
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
struct Edge{int v,w,nxt;}e[4000005];
typedef int arr[2000005];
arr h;
int cnt=1;
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}
#define addedge_(u,v,w) addedge(v,u,w)
int N;
arr id,dis,vis;
void build(int o,int l,int r)
{
	addedge(o+4*N,o,0);
	if(l==r)
	{
		id[l]=o;
		return;
	}
	int m=l+r>>1;
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
//	addedge(o,o<<1,0);
//	addedge(o,o<<1|1,0);
	addedge(o+4*N,4*N+(o<<1),0);
	addedge(o+4*N,4*N+(o<<1|1),0);
	addedge_(o,o<<1,0);
	addedge_(o,o<<1|1,0);
//	addedge_(o+4*N,4*N+(o<<1),0);
//	addedge_(o+4*N,4*N+(o<<1|1),0);
}
inline void add(int o,int l,int r,int L,int R,int v,int w)
{
	if(L<=l&&r<=R)
	{
		if(v<=N*4)addedge(v,o+4*N,w);
		else addedge(o,v,w);
		return;
	}
	int m=l+r>>1;
	if(L<=m)add(o<<1,l,m,L,R,v,w);
	if(m<R)add(o<<1|1,m+1,r,L,R,v,w);
}
struct qwq{
	int u,d;
	bool operator<(const qwq&b)const
	{
		return d>b.d;
	}
};
signed main()
{
	int n=read(),m=read(),wq=read();N=n;
	build(1,1,n);
	while(m--)
	{
		int op=read();
		if(op==1)
		{
			int u=read(),v=read(),w=read();
			addedge(id[u],id[v]+N*4,w);
		}
		else if(op==2)
		{
			int u=read(),l=read(),r=read(),w=read();
			add(1,1,n,l,r,id[u],w);
		}
		else
		{
			int u=read(),l=read(),r=read(),w=read();
			add(1,1,n,l,r,id[u]+4*N,w);
		}
	}
	memset(dis,0x3f,sizeof(dis));
	std::priority_queue<qwq>q;
	dis[id[wq]]=0;
	q.push((qwq){id[wq],0});
	while(!q.empty())
	{
		qwq x=q.top();q.pop();
		int u=x.u,d=x.d;
		if(vis[u])continue;
		vis[u]=1;
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v,w=e[i].w;
			if(vis[v])continue;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=d+w;
				q.push((qwq){v,dis[v]});
			}
		}
	}
	rg(n)oldb(dis[id[i]]==4557430888798830399ll?-1:dis[id[i]]);gr
	return 0;
}