#include <stdio.h>
#include <stdlib.h>
#define p 1000000007
using namespace std;

int nm,n,m,K,i,j,k,l,r;
int C[105][105];
long long f[55][55][55][105],now,ans;

int main()
{
	C[0][0]=1;
	for(i=0;i<=100;++i)
	for(j=0;j<=i;++j)
	{
		if(C[i][j]>100)C[i][j]=101;
		C[i+1][j]+=C[i][j];
		C[i+1][j+1]+=C[i][j];
	}
	scanf("%d%d%d",&n,&m,&K);
	n/=2;nm=n;if(m<nm)nm=m;
	for(i=1;i<=n;++i)f[i][i][1][1]=1;
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	for(k=1;k<=nm;++k)
	for(l=1;l<=K;++l)
	if(f[i][j][k][l])
	{
		f[i][j][k][l]%=p;
		ans=(ans+(m-k)*f[i][j][k][l])%p;
		for(r=n-i;r>=1;--r)
		if(l*C[j+r-1][j-1]<=K)
		f[i+r][r][k+1][l*C[j+r-1][j-1]]+=f[i][j][k][l];
	}
	printf("%I64d\n",ans);
}