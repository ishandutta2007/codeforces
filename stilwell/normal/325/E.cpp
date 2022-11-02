#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k,tot;
int son[100005][2],ans[100005];
bool use[100005][2];

void dfs(int x)
{
	if(!use[x][0])
	{
		use[x][0]=true;
		dfs(son[x][0]);
	}
	if(!use[x][1])
	{
		use[x][1]=true;
		dfs(son[x][1]);
	}
	ans[--tot]=x;
}

int main()
{
	scanf("%d",&n);
	if(n%2){printf("-1\n");return 0;}
	for(i=0;i<n/2;++i)son[i][0]=i*2%(n/2),son[i][1]=(i*2+1)%(n/2);
	tot=n+1;dfs(0);
	for(i=1;i<n;++i)
	if(ans[i+1]==ans[i]*2%(n/2)&&ans[i]!=0)ans[i]=ans[i]*2;
	else ans[i]=ans[i]*2+1;
	for(i=0;i<=n;++i)printf("%d ",ans[i]);printf("\n");
}