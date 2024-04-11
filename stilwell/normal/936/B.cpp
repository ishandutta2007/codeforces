#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,u,v;
int son[100005],Next[200005],ed[200005],tot;
int path[200005];
bool f[100005][2],vis[100005],instack[100005];

void dfs(int x,int y,int z)
{
	path[z]=x;f[x][y]=true;
	if(!son[x])
	{
		if(y)
		{
			printf("Win\n");
			for(int i=1;i<=z;++i)printf("%d ",path[i]);
			printf("\n");
			exit(0);
		}
		return;
	}
	for(int i=son[x];i;i=Next[i])
	if(!f[ed[i]][y^1])dfs(ed[i],y^1,z+1);
}

void dfs2(int x)
{
	vis[x]=instack[x]=true;
	for(int i=son[x];i;i=Next[i])
	{
		if(instack[ed[i]])
		{
			printf("Draw\n");
			exit(0);
		}
		if(!vis[ed[i]])dfs2(ed[i]);
	}
	instack[x]=false;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&k);
		for(;k;--k)
		{
			scanf("%d",&u);
			++tot;Next[tot]=son[i];son[i]=tot;ed[tot]=u;
		}
	}
	scanf("%d",&v);
	dfs(v,0,1);
	dfs2(v);
	printf("Lose\n");
}