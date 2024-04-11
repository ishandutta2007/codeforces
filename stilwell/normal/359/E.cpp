#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,x,y,i,j,k,sum,tot;
bool a[505][505],vis[505][505];
char ans[3000005];

bool dir(int x,int y,int dx,int dy)
{
	for(;;)
	{
		x+=dx;y+=dy;
		if(x<0||x>n||y<0||y>n)return false;
		if(vis[x][y])return false;
		if(a[x][y])return true;
	}
}

void dfs(int x,int y)
{
	if(!a[x][y])ans[++tot]='1',++sum;
	vis[x][y]=true;
	if(dir(x,y,-1,0))
	{
		ans[++tot]='U';
		dfs(x-1,y);
		ans[++tot]='D';
	}
	if(dir(x,y,1,0))
	{
		ans[++tot]='D';
		dfs(x+1,y);
		ans[++tot]='U';
	}
	if(dir(x,y,0,-1))
	{
		ans[++tot]='L';
		dfs(x,y-1);
		ans[++tot]='R';
	}
	if(dir(x,y,0,1))
	{
		ans[++tot]='R';
		dfs(x,y+1);
		ans[++tot]='L';
	}
	ans[++tot]='2';--sum;
}

int main()
{
	scanf("%d%d%d",&n,&x,&y);
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	{
		scanf("%d",&a[i][j]);
		if(a[i][j])++sum;
	}
	dfs(x,y);
	if(sum)printf("NO\n");
	else printf("YES\n%s\n",ans+1);
}