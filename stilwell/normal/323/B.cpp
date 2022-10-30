#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k;
bool a[1005][1005];

int main()
{
	scanf("%d",&n);
	if(n==4)
	{
		printf("-1\n");
		return 0;
	}
	for(i=1;i<n;++i)a[i][i+1]=true;
	for(i=1;i<=n;++i)
	for(j=i+2;j<=n;++j)
	if(i%2==j%2)a[i][j]=true;
	else a[j][i]=true;
	a[n][1]=true;a[1][n]=false;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)printf("%d ",a[i][j]);
		printf("\n");
	}
}