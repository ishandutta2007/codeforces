#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k,ans;
int a[5005],f[5005][5005],g[5005];

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=0;i<=n;++i)
	for(j=0;j<=n;++j)
	f[i][j]=10000;
	f[0][0]=0;
	for(i=1;i<=n;++i)
	{
		k=a[i];if(n<k)k=n;
		for(j=0;j<=k;++j)f[i][j]=f[i-1][j];
		for(j=1;j<=k;++j)if(f[i][j-1]+1<f[i][j])f[i][j]=f[i][j-1]+1;
		for(j=0;j<=k;++j)f[i][j]+=(j!=a[i]);
		for(j=k-1;j>=0;--j)if(f[i][j+1]<f[i][j])f[i][j]=f[i][j+1];
	}
	ans=10000;
	for(i=0;i<=n;++i)if(f[n][i]<ans)ans=f[n][i];
	printf("%d\n",ans);
}