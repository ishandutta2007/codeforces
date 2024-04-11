#include <cstdio>
using namespace std;
const int N=1005;
const int B=40;
int n,m,i,j,k,x,y;
double f[N][N];
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d%d",&x,&y);
	for (i=n-1;i>=x;i--)
		for (k=1;k<=B;k++)
			for (j=1;j<=m;j++)
				f[i][j]=(f[i][j+1]+f[i][j-1]+f[i][j]+f[i+1][j])/(2+(j>1)+(j<m))+1;
	printf("%.10lf\n",f[x][y]);
	return 0;
}