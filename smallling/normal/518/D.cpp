#include<cstdio>

using namespace std;

int n,t;
double p,ans,f[2010][2010];

int main()
{
	scanf("%d%lf%d",&n,&p,&t);
	f[1][0]=1-p;
	f[1][1]=p;
	for(int i=1;i<t;i++)
	{
		for(int j=0;j<n;j++)
		{
			f[i+1][j]+=f[i][j]*(1-p);
			f[i+1][j+1]+=f[i][j]*p;
		}
		f[i+1][n]+=f[i][n];
	}
	for(int j=1;j<=t;j++)ans+=f[t][j]*j;
	printf("%.6lf\n",ans);
}