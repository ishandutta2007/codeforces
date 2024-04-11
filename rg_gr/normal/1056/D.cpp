#include <stdio.h>
#include <string.h> 
#include <algorithm>
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
struct Edge{
	int v,nxt;
}e[2000005];
int h[100005],cnt=2;
inline void addedge(int u,int v)
{
	e[cnt]=(Edge){v,h[u]};
	h[u]=cnt++;
}
int sz[200005];
void dfs(int u,int fa)
{
	sz[u]=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
	if(sz[u]==0)sz[u]++;
}
signed main()
{
	int n=read();//,k=read();
	for(int i=1;i<n;i++)
	{
		int u=read();//,v=read();
		addedge(u,i+1);
		//addedge(v,u);
	}
	dfs(1,-1);
	std::sort(sz+1,sz+1+n);
	for(int i=1;i<=n;i++)printf("%lld ",sz[i]);
}