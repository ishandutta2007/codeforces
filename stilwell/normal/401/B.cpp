#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,ans;
int f[5000];

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d",&j);
		scanf("%d",&k);
		f[k]=1;
		if(j==1)
		{
			scanf("%d",&k);
			f[k]=1;
		}
	}
	ans=0;
	for(i=1;i<n;++i)
	if(!f[i])
	{
		++ans;
		if(!f[i+1])f[i+1]=2;
	}
	printf("%d ",ans);
	ans=0;
	for(i=1;i<n;++i)
	if(f[i]!=1)++ans;
	printf("%d\n",ans);
}