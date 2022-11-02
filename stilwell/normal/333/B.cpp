#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,u,v,ans,tmp;
int a[1005],use[1005];
bool banx[1005],bany[1005];

void dfs(int x)
{
	if(x>4)
	{
		int i,j,k;
		for(i=1;i<=2;++i)
		for(j=3;j<=4;++j)
		if(use[i]&&use[j])
		{
			if(a[i]==a[j])
			{
				if(use[i]==use[j])return;
			}
			else
			{
				if(use[i]!=use[j])return;
			}
		}
		if(use[1]&&use[2]&&a[1]==a[2])return;
		if(use[3]&&use[4]&&a[3]==a[4])return;
		k=0;
		for(i=1;i<=4;++i)if(use[i])++k;
		if(k>tmp)tmp=k;
		return;
	}
	if(x<=2)
	{
		if(!banx[a[x]])
		{
			use[x]=1;
			dfs(x+1);
			use[x]=2;
			dfs(x+1);
		}
	}
	else
	{
		if(!bany[a[x]])
		{
			use[x]=1;
			dfs(x+1);
			use[x]=2;
			dfs(x+1);
		}
	}
	use[x]=0;
	dfs(x+1);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(;m;--m)
	{
		scanf("%d%d",&u,&v);
		banx[u]=bany[v]=true;
	}
	for(i=n/2;i>1;--i)
	{
		a[1]=a[3]=i;
		a[2]=a[4]=n-i+1;
		tmp=0;
		dfs(1);
		ans+=tmp;
	}
	if(n%2)
	{
		if(!banx[n/2+1]||!bany[n/2+1])
		++ans;
	}
	printf("%d\n",ans);
}