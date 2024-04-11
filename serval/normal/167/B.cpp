#include <cstdio>
using namespace std;
const int N=205;
int n,l,k;
int i,j,x,y;
double p[N],ans;
double f[N][N][N<<1];
int main()
{
	scanf("%d%d%d",&n,&l,&k);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&j);
		p[i]=j/100.0;
	}
	f[0][0][N+k]=1.0;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&j);
		for (x=0;x<=n;x++)
			for (y=0;y<(N<<1);y++)
				if (j==-1)
				{
					f[i][x+1][y-1]+=f[i-1][x][y]*p[i];
					f[i][x][y]+=f[i-1][x][y]*(1-p[i]);
				}
				else
				{
					f[i][x+1][y+j>(N<<1)-1?(N<<1)-1:y+j]+=f[i-1][x][y]*p[i];
					f[i][x][y]+=f[i-1][x][y]*(1-p[i]);
				}
	}
	for (i=l;i<=n;i++)
		for (j=N;j<(N<<1);j++)
			ans+=f[n][i][j];
	printf("%.10lf\n",ans);
	return 0;
}