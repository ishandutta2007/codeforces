#include <stdio.h>
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>=48&&c<=57)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return num*f;
}
//int dp[6005][2],n,c[6005];
struct Edge
{
	int v,ne,w;
}edge[400005];
int cnt=1,h[200005],n;
inline void addedge(int u,int v,int w)
{
	edge[cnt].v=v;
	edge[cnt].ne=h[u];
	edge[cnt].w=w;
	h[u]=cnt++;
}
inline int max(int a,int b){return a>b?a:b;}
int distou[200005];
void fs(int u,int fa)
{
	for(int i=h[u];i;i=edge[i].ne)
	{
		int v=edge[i].v;
		if(v==fa)continue;
		fs(v,u);
		if(edge[i].w==-1)distou[u]++;
		distou[u]+=distou[v];
	}
}
int ans=99999999,dist[200005];
void dfs(int u,int fa,int dis)
{
	dist[u]=dis;
	if(ans>dis)ans=dis;
	for(int i=h[u];i;i=edge[i].ne)
	{
		int v=edge[i].v;
		if(v!=fa)dfs(v,u,dis+edge[i].w);
	}
	//printf("for %d, choose Y = %d, N = %d\n",u,dp[u][0],dp[u][1]);
}
int main()
{
	n=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		addedge(x,y,1);addedge(y,x,-1);
	}
	fs(1,-1);
	dfs(1,-1,distou[1]);
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)if(dist[i]==ans)printf("%d ",i);
	puts("");
	return 0;
}