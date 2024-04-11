#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k;
int son[100005],next[100005],size[100005];
double ans[100005];

void dfs(int x)
{
	size[x]=1;
	for(int i=son[x];i;i=next[i])dfs(i),size[x]+=size[i];
}

void dfs2(int x,double y)
{
	ans[x]=y+1;
	for(int i=son[x];i;i=next[i])dfs2(i,y+1+(size[x]-1-size[i])/2.0);
}

int main()
{
	scanf("%d",&n);
	for(i=2;i<=n;++i)
	{
		scanf("%d",&k);
		next[i]=son[k];son[k]=i;
	}
	dfs(1);dfs2(1,0);
	for(i=1;i<=n;++i)printf("%.9lf ",ans[i]);
}