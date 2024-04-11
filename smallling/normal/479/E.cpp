#include<cstdio>

#define mo 1000000007

using namespace std;

int n,a,b,k,f[5010][5010],sum[5010][5010];

inline void Sum(int x)
{
	for(int i=1;i<=n;i++)
		sum[x][i]=(sum[x][i-1]+f[x][i])%mo;
}

int main()
{
	scanf("%d%d%d%d",&n,&a,&b,&k);
	f[0][a]=1;
	Sum(0);
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<b;j++)
			f[i][j]=(sum[i-1][(b+j-1)/2]-f[i-1][j]+mo)%mo;
		for(int j=b+1;j<=n;j++)
			f[i][j]=((sum[i-1][n]-sum[i-1][(j+b+2)/2-1]+mo)%mo-f[i-1][j]+mo)%mo;
		Sum(i);
	}
	printf("%d",sum[k][n]);
}