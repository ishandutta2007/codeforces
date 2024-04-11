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
#define rg_(i,x) for(int i=1;i<=(x);i++){
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
#define int long long
inline int read()
{
	int num=0;char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48&&c<=57)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return num;
}
int st[1000005];
int cnt=1,h[1000005];
int low[1000005],dfn[1000005],s,n,t,c[1000005],r,S[1000005],m,ans,T,R[1000005];
struct Edge{
	int v,w,nxt;
}e[12550055];
inline void A(int u,int v)
{
//	oldp(u,v);
	e[cnt].v=v;
	e[cnt].nxt=h[u],h[u]=cnt++;
}
void tarjan(int u)
{
	low[u]=dfn[u]=++s;
	st[++t]=u;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=(low[u]<low[v]?low[u]:low[v]);
		}
		else if(!c[v])low[u]=low[u]<dfn[v]?low[u]:dfn[v];
	}
	if(low[u]==dfn[u])
	{
		c[u]=++r;
		while(st[t]!=u)c[st[t]]=r,t--;
		t--;
	}	
}
inline int id(int r,int c)
{
	return c+(r-1)*m;
}
char **G;
int deg[2000005];
signed main()
{
	n=read(),m=read();
	G=new char*[n+1];
	for(int i=0;i<=n;i++)G[i]=new char[m+2];
	rg(n)scanf("%s",G[i]+1);gr
	rg(n)rg_(j,m)if(G[i][j]=='.')continue;
	if(G[i][j-1]=='#')A(id(i,j),id(i,j-1));
	if(G[i][j+1]=='#')A(id(i,j),id(i,j+1));
	if(G[i-1][j]=='#')A(id(i,j),id(i-1,j));
	for(int k=i+1;k<=n;k++)
	{
		if(G[k][j]=='#')
		{
			A(id(i,j),id(k,j));
			break;
		}
		if(G[k][j-1]=='#')A(id(i,j),id(k,j-1));
		if(G[k][j+1]=='#')A(id(i,j),id(k,j+1));
	}gr gr
	//for(int i=1;i<=n*m;i++)
	rg(n)rg_(j,m)if(G[i][j]=='#'&&!dfn[id(i,j)])tarjan(id(i,j));gr gr
//	for(int u=1;u<=n*m;u++)
	rg(n)rg_(j,m)
	int u=id(i,j);
	if(G[i][j]!='#')continue;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(c[u]!=c[v])deg[c[v]]++;
	}gr gr
	int ans=0;
	rg(r)ans+=!(deg[i]);gr
	odl(ans);
	return 0;
}