#include <stdio.h>
#include <stdlib.h>
#define P 1000000007
using namespace std;

int f[55][1005][1005],sum[50][1005];
int C[2005][2005];
int T,n,i,j,k;
long long ans,fac[1005];

int main()
{
	C[0][0]=1;
	for(i=0;i<=2000;++i)
	for(j=0;j<=i;++j)
	{
		C[i][j]%=P;
		C[i+1][j]+=C[i][j];
		C[i+1][j+1]+=C[i][j];
	}
	for(i=0;i<=1000;++i)f[1][i][i]=1;
	for(i=2;i<=50;++i)
	{
		for(j=0;j<=1000;++j)
		for(k=0;k<=j;++k)
		f[i][j+k+1][k+1]=(f[i][j+k+1][k+1]+f[i-1][j][k])%P;
		for(j=0;j<=1000;++j)
		for(k=0;k<=j;++k)
		f[i][j+1][k+1]=(f[i][j+1][k+1]+f[i][j][k])%P;
	}
	for(fac[0]=1,i=1;i<=50;++i)fac[i]=fac[i-1]*i%P;
	for(i=1;i<=50;++i)
	for(j=0;j<=1000;++j)
	for(k=0;k<=j;++k)
	sum[i][j]=(sum[i][j]+f[i][j][k])%P;
	scanf("%d",&T);
	for(;T;--T)
	{
		scanf("%d%d",&n,&k);
		n-=k;ans=0;
		if(k>=50){printf("0\n");continue;}
		if(n<0){printf("0\n");continue;}
		for(i=0;i<=n;++i)ans=(ans+fac[k]*sum[k][i]%P*C[n-i+k][k]%P)%P;
		printf("%I64d\n",ans);
	}
}