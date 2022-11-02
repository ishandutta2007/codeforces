#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int val[1005],u,v;
int n,m,i,j,k,ans;

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",&val[i]);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		if(val[u]<val[v])ans+=val[u];
		else ans+=val[v];
	}
	printf("%d\n",ans);
}