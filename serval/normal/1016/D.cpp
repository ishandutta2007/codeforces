#include <cstdio>
using namespace std;
int n,m,i,j,ret;
int a[105],b[105];
int x[105][105];
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ret^=a[i];
	}
	for (i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		ret^=b[i];
	}
	if (ret>0)
	{
		printf("NO\n");
		return 0;
	}
	for (i=2;i<=n;i++)
		x[i][1]=a[i];
	for (i=2;i<=m;i++)
		x[1][i]=b[i];
	for (i=2;i<=n;i++)
		b[1]^=a[i];
	for (i=2;i<=m;i++)
		a[1]^=b[i];
	if (a[1]!=b[1])
	{
		printf("NO\n");
		return 0;
	}
	x[1][1]=b[1];
	printf("YES\n");
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			printf(j<m?"%d ":"%d\n",x[i][j]);
	return 0;
}