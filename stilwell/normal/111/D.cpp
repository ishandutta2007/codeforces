#include <stdio.h>
#include <stdlib.h>
#define p 1000000007
using namespace std;

int n,m,K,i,j,k;
long long fac[1000005],fac_inv[1000005];
long long f[1005][1005],g[1005],ans;

long long Power(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b%2)ans=ans*a%p;
		a=a*a%p;
		b/=2;
	}
	return ans;
}
long long C(int n,int m)
{
	if(m>n)return 0;
	return fac[n]*fac_inv[m]%p*fac_inv[n-m]%p;
}

int main()
{
	fac[0]=1;
	for(i=1;i<=1000000;++i)fac[i]=fac[i-1]*i%p;
	fac_inv[1000000]=Power(fac[1000000],p-2);
	for(i=1000000;i>=1;--i)fac_inv[i-1]=fac_inv[i]*i%p;
	scanf("%d%d%d",&n,&m,&K);
	if(m==1)
	{
		printf("%I64d\n",Power(K,n));
		return 0;
	}
	f[1][1]=1;
	for(i=1;i<n;++i)
	for(j=1;j<=i;++j)
	{
		f[i+1][j]=(f[i+1][j]+f[i][j]*j)%p;
		f[i+1][j+1]=(f[i+1][j+1]+f[i][j]*(j+1))%p;
	}
	if(m==2)g[0]=1;
	for(i=1;i<=n;++i)
	{
		g[i]=Power(i,(m-2)*n);
		for(j=0;j<i;++j)g[i]=(g[i]+p-g[j]*C(i,j)%p)%p;
	}
	for(i=1;i<=n;++i)
	for(j=0;j<=i;++j)
	ans=(ans+C(K,j)*C(K-j,i-j)%p*C(K-j,i-j)%p*f[n][i]%p*f[n][i]%p*g[j]%p)%p;
	printf("%I64d\n",ans);
}