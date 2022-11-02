#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int n,m,i,j,k,tot,ans,sum;
char s[55][55];
bool vis[55][55];

void dfs(int x,int y)
{
	if(vis[x][y])return;
	if(s[x][y]!='#')return;
	vis[x][y]=true;
	++tot;
	dfs(x-1,y);
	dfs(x+1,y);
	dfs(x,y-1);
	dfs(x,y+1);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	if(s[i][j]=='#')
	++tot;
	if(tot<=2)
	{
		printf("-1\n");
		return 0;
	}
	sum=tot;
	ans=4;
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	if(s[i][j]=='#')
	{
		tot=0;
		if(s[i-1][j]=='#')++tot;
		if(s[i+1][j]=='#')++tot;
		if(s[i][j-1]=='#')++tot;
		if(s[i][j+1]=='#')++tot;
		if(tot<ans)ans=tot;
	}
	for(i=1;i<=n&&ans>1;++i)
	for(j=1;j<=m;++j)
	if(s[i][j]=='#')
	{
		tot=0;
		memset(vis,false,sizeof(vis));
		vis[i][j]=true;
		if(s[i-1][j]=='#')dfs(i-1,j);else
		if(s[i+1][j]=='#')dfs(i+1,j);else
		if(s[i][j-1]=='#')dfs(i,j-1);else
		dfs(i,j+1);
		if(tot!=sum-1){ans=1;break;}
	}
	printf("%d\n",ans);
}