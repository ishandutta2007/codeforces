#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k,u,v;
int son[100005],next[200005],ed[200005],tot;
bool vis[100005];
double ans;

void dfs(int x,int y)
{
	vis[x]=true;
	ans+=1.0/y;
	for(int i=son[x];i;i=next[i])
	if(!vis[ed[i]])dfs(ed[i],y+1);
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
	dfs(1,1);
	printf("%.20lf\n",ans);
}