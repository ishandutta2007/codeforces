#include<cstdio>
#include<algorithm>

using namespace std;

int n,m,i,j,a[50001][10],f[50001][10];

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			f[i][j]=max(f[i-1][j],f[i][j-1])+a[i][j];
		}
	for(int i=1;i<=n;i++)printf("%d ",f[i][m]);
}