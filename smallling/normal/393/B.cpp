#include<cstdio>

using namespace std;

int i,j,k,l,m,n,o,p;
double w[171][171],a[171][171],b[171][171],now;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%lf",&w[i][j]);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		now=w[i][j]+w[j][i];
		a[i][j]=a[j][i]=now/2;
		b[i][j]=w[i][j]-now/2;
		b[j][i]=-b[i][j];
		if(b[i][j]==0)b[j][i]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		printf("%.8lf ",a[i][j]);
		putchar('\n');
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		printf("%.8lf ",b[i][j]);
		putchar('\n');
	}
}