#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k;
int C[105][5];
bool a[105][105];

int calc(int x)
{
	int i;
	for(i=1;C[i][x]<=m;++i);
	return i-1;
}

int main()
{
	C[0][0]=1;
	for(i=0;i<=100;++i)
	for(j=0;j<=3;++j)
	C[i+1][j]+=C[i][j],C[i+1][j+1]+=C[i][j];
	scanf("%d",&m);
	k=calc(3);
	m-=C[k][3];
	n=k;
	for(i=1;i<=k;++i)
	for(j=1;j<=k;++j)
	if(i!=j)a[i][j]=true;
	for(;m;)
	{
		k=calc(2);
		++n;
		for(i=1;i<=k;++i)a[i][n]=a[n][i]=true;
		m-=C[k][2];
	}
	printf("%d\n",n);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)printf("%d",a[i][j]);
		printf("\n");
	}
}