#include<cstdio>

using namespace std;

int n,m,a,b,A[1010];
double ans,f[1010][1010];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(A[i]>A[j])f[i][j]=1.;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		f[a][b]=f[b][a]=0.5;
		for(int j=1;j<=n;j++)
			if(j!=a&&j!=b)
				f[a][j]=f[b][j]=(f[a][j]+f[b][j])/2.,
				f[j][a]=f[j][b]=(f[j][a]+f[j][b])/2.;
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			ans+=f[i][j];
	printf("%.10lf\n",ans);
}