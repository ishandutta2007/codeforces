#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,u,v;
int son[100005],next[200005],ed[200005],tot;
int A[100005],B[100005];
bool ans[100005],vis[100005];

void dfs(int x,int y,int z)
{
	vis[x]=true;
	if((A[x]^y)!=B[x]){++m;ans[x]=true;y^=1;}
	for(int i=son[x];i;i=next[i])
	if(!vis[ed[i]])dfs(ed[i],z,y);
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		++tot;next[tot]=son[u];son[u]=tot;ed[tot]=v;
		++tot;next[tot]=son[v];son[v]=tot;ed[tot]=u;
	}
	for(i=1;i<=n;++i)scanf("%d",&A[i]);
	for(i=1;i<=n;++i)scanf("%d",&B[i]);
	dfs(1,0,0);
	printf("%d\n",m);
	for(i=1;i<=n;++i)if(ans[i])printf("%d\n",i);
}