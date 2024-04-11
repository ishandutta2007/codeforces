#include <stdio.h>
#include <stdlib.h>
#define p 1000000007
using namespace std;

long long c[105][105],C[105][105],f[105][10005],m;
int n,K,i,j,k;

long long Power(long long a,long long b)
{
	b%=p-1;
	long long ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ans;
}

int main()
{
	scanf("%d%I64d%d",&n,&m,&K);
	c[0][0]=1;
	for(i=0;i<=n;++i)
	for(j=0;j<=i;++j)
	{
		c[i][j]%=p;
		c[i+1][j]+=c[i][j];
		c[i+1][j+1]+=c[i][j];
	}
	for(i=1;i<=n;++i)
	for(j=0;j<=n;++j)
	C[i][j]=Power(c[n][j],m/n+(m%n>=i));
	f[0][0]=1;
	for(i=1;i<=n;++i)
	for(j=0;j<=K;++j)
	for(k=0;k<=n;++k)
	if(j>=k)
	f[i][j]=(f[i][j]+f[i-1][j-k]*C[i][k])%p;
	printf("%I64d\n",f[n][K]);
}