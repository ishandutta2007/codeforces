#include <stdio.h>
#include <stdlib.h>
#define p 1000000007
using namespace std;

int n,m,i,j,k,l,lim;
long long f[2005][2005],g[2005][2005];
char s[2005];

int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(i=1;i<=n;++i)s[i]-='a';
	f[n+1][0]=g[n+1][0]=1;
	for(i=n;i>=1;--i)
	for(j=0;j<=m;++j)
	{
		f[i][j]=(s[i]*f[i+1][j]+g[i+1][j])%p;
		g[i][j]=(s[i]*f[i+1][j]+g[i+1][j])%p;
		for(k=i;k<=n;++k)
		{
			l=j-(k-i+1)*(n-k+1);
			if(l<0)break;
			f[i][j]=(f[i][j]+(25-s[k])*f[k+1][l])%p;
		}
		lim=k;
		for(k=n;k>lim;--k)
		{
			l=j-(k-i+1)*(n-k+1);
			if(l<0)break;
			f[i][j]=(f[i][j]+(25-s[k])*f[k+1][l])%p;
		}
	}
	printf("%I64d\n",f[1][m]);
}