#include<cstdio>

using namespace std;

int n,m,o,sigma;
double ans,f[110][100010],sum[110][100010];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&o);
		sigma+=o;
		if(i>1)
		{
			for(int j=i;j<=i*m;j++)
			{
				f[i][j]=sum[i-1][j-1];
				if(j-1-m>=0)f[i][j]-=sum[i-1][j-1-m];
				if(j>=o)f[i][j]-=f[i-1][j-o];
				f[i][j]/=(m-1);
			}
		}
		else
		{
			for(int j=1;j<=m;j++)
				if(j!=o)f[i][j]=1./(m-1);
		}
		for(int j=1;j<=(i+1)*m;j++)
			sum[i][j]=f[i][j]+sum[i][j-1];
	}
	printf("%.10lf\n",sum[n][sigma-1]*(m-1)+1);
}