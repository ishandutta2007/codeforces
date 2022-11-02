#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

double p[1005],f[205][405],g[205][405],ans;
int a[1005],i,j,n,l,k;

int main()
{
	scanf("%d%d%d",&n,&l,&k);
	f[0][200+min(n,k)]=1;
	for(i=1;i<=n;++i)scanf("%lf",&p[i]),p[i]/=100;
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=n;++i)
	{
		memset(g,0,sizeof(g));
		for(j=0;j<=i;++j)
		for(k=200-i;k<=200+n;++k)
		{
			g[j][k]+=f[j][k]*(1-p[i]);
			g[j+1][min(200+n,k+a[i])]+=f[j][k]*p[i];
		}
		memcpy(f,g,sizeof(f));
	}
	for(j=l;j<=n;++j)
	for(k=200;k<=200+n;++k)
	ans+=f[j][k];
	printf("%.9lf\n",ans);
}