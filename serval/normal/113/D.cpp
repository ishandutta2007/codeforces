#include <cstdio>
#include <algorithm>
using namespace std;
const int N=25;
const int M=505;
int n,m,a,b;
int i,j,k,u,v,con;
int deg[N];
bool c[N][N];
double p[N],q[N][N];
double f[M][M];
int g(int i,int j)
{
	return i*n-n+j;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		c[u][v]=c[v][u]=1;
		deg[u]++;
		deg[v]++;
	}
	for (i=1;i<=n;i++)
		scanf("%lf",&p[i]);
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			if (i==j)
				q[i][j]=p[i];
			else
				if (c[i][j])
					q[i][j]=(1-p[i])/deg[i];
	con=n*n;
	f[g(a,b)][con+1]=-1;
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
		{
			f[g(i,j)][g(i,j)]--;
			for (a=1;a<=n;a++)
				for (b=1;b<=n;b++)
					if (a!=b)
						f[g(i,j)][g(a,b)]+=q[a][i]*q[b][j];
		}
	for (i=1;i<=con;i++)
	{
		for (j=i;j<=con;j++)
			if (f[j][i]!=0)
				break;
		if (j>con)
			continue;
		if (j!=i)
			for (k=i;k<=con+1;k++)
				swap(f[i][k],f[j][k]);
		for (j=i+1;j<=con;j++)
			for (k=con+1;k>=i;k--)
				f[j][k]-=f[j][i]/f[i][i]*f[i][k];
	}
	for (i=con;i;i--)
	{
		if (f[i][i]==0)
			continue;
		f[i][con+1]/=f[i][i];
		for (j=i-1;j;j--)
			f[j][con+1]-=f[i][con+1]*f[j][i];
	}
	for (i=1;i<=n;i++)
		printf(i<n?"%.6lf ":"%.6lf\n",f[g(i,i)][con+1]);
	return 0;
}