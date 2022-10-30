#include <stdio.h>
#include <stdlib.h>
#define p 1000000007
using namespace std;

int n,m,i,j,k,ans,sum;
int f[2005][2005],f2[2005][2005],g[2005][2005];

int main()
{
	scanf("%d%d",&n,&m);
	for(i=2;i<=m;++i)f[1][i]=1,g[1][i]=i-1;
	for(i=2;i<=n;++i)
	{
		sum=0;
		for(j=2;j<=m;++j)
		{
			sum+=g[i-1][j];
			if(sum>=p)sum-=p;
			if(i==2)f[i][j]=sum-1;
			else f[i][j]=sum;
		}
		for(j=2;j<=m;++j)
		{
			g[i][j]=f[i][j]+g[i][j-1];
			if(g[i][j]>=p)g[i][j]-=p;
		}
	}
	for(i=2;i<=m;++i)f2[1][i]=1,g[1][i]=i-1;
	for(i=2;i<=n;++i)
	{
		sum=0;
		for(j=2;j<=m;++j)
		{
			sum+=g[i-1][j];
			if(sum>=p)sum-=p;
			f2[i][j]=sum;
		}
		for(j=2;j<=m;++j)
		{
			g[i][j]=f2[i][j]+g[i][j-1];
			if(g[i][j]>=p)g[i][j]-=p;
		}
	}
	for(i=2;i<=n;++i)
	for(j=2;j<=m;++j)
	{
		f[i][j]+=f[i-1][j];
		if(f[i][j]>=p)f[i][j]-=p;
	}
	for(i=2;i<=n;++i)
	for(j=2;j<=m;++j)
	{
		f2[i][j]+=f2[i-1][j];
		if(f2[i][j]>=p)f2[i][j]-=p;
	}
	for(i=1;i<=n;++i)
	for(j=2;j<=m;++j)
	{
		ans+=(m-j+1ll)*f[i][j]%p*f2[n-i+1][j]%p;
		if(ans>=p)ans-=p;
	}
	printf("%d\n",ans);
}