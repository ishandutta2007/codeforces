#include<stdio.h>
#include<cstring>
using namespace std;
long n;long s;long t;long ans=0;
long f[101][101];
int main()
{
	scanf("%ld",&n);
	memset(f,63,sizeof f);
	for(long i=1;i<=n;i++)
	{
		f[i][i]=0;
		scanf("%ld",&f[i][(i%n)+1]);
		f[(i%n)+1][i]=f[i][(i%n)+1];
	}
	for(long k=1;k<=n;k++)
	for(long i=1;i<=n;i++)
	for(long j=1;j<=n;j++)
	if(f[i][k]+f[k][j]<f[i][j])
	{
		f[i][j]=f[i][k]+f[k][j];
	}
	scanf("%ld%ld",&s,&t);
	printf("%ld\n",f[s][t]);
	return 0;
}