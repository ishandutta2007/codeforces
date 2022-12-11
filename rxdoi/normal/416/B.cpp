#include<cstdio>
#include<iostream>
using namespace std;

const int M=50000+19,N=6;
int F[M][N],t[M][N],n,m;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) scanf("%d",&t[i][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			F[i][j]=max(F[i-1][j],F[i][j-1])+t[i][j];
	for (int i=1;i<=n;i++) printf("%d ",F[i][m]);
	printf("\n");
	return 0;
}