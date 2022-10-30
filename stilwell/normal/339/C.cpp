#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k;
int ans[1005];
char s[15];

void dfs(int x,int y,int z,int pre)
{
	if(x>n)
	{
		printf("YES\n");
		for(i=1;i<=n;++i)printf("%d ",ans[i]);
		printf("\n");
		exit(0);
	}
	if(x%2)
	{
		for(int i=1;i<=10;++i)
		if(s[i]=='1'&&y+i>z&&i!=pre)
		ans[x]=i,dfs(x+1,y+i,z,i);
	}
	else
	{
		for(int i=1;i<=10;++i)
		if(s[i]=='1'&&z+i>y&&i!=pre)
		ans[x]=i,dfs(x+1,y,z+i,i);
	}
}

int main()
{
	scanf("%s",s+1);
	scanf("%d",&n);
	dfs(1,0,0,0);
	printf("NO\n");
}