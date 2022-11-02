#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k;
long long a[200005],cost[200005][2],ans;
int aim[200005][2];
bool done[200005],t[200005][2];

void dfs(int x,bool f)
{
	if(t[x][f])
	{
		aim[x][f]=-2;
		return; 
	}
	t[x][f]=true;
	int tmp;
	if(f)tmp=x-a[x];
	else tmp=x+a[x];
	if(tmp<=0||tmp>n)
	{
		aim[x][f]=-1;
		cost[x][f]=a[x];
		return;
	}
	if(tmp==1)
	{
		if(f)aim[x][f]=1;
		else aim[x][f]=2;
		cost[x][f]=a[x];
		return;
	}
	if(!aim[tmp][!f])dfs(tmp,!f);
	aim[x][f]=aim[tmp][!f];
	cost[x][f]=cost[tmp][!f]+a[x];
}

int main()
{
	scanf("%d",&n);
	for(i=2;i<=n;++i)scanf("%I64d",&a[i]);
	for(i=2;i<=n;++i)
	{
		if(!aim[i][0])dfs(i,0);
		if(!aim[i][1])dfs(i,1);
	}
	for(a[1]=1;a[1]<n;++a[1])
	{
		ans=a[1]+cost[1+a[1]][1];
		k=aim[1+a[1]][1];
		if(k==-2){printf("-1\n");continue;}
		if(k==1){printf("-1\n");continue;}
		if(k==-1){printf("%I64d\n",ans);continue;}
		ans+=a[1];
		printf("%I64d\n",ans);
	}
}