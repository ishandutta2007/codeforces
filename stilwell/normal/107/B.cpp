#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,h,i,j,k,sum;
int a[1005];
double f[105][105],ans;

int main()
{
	scanf("%d%d%d",&n,&m,&h);
	for(i=1;i<=m;++i)scanf("%d",&a[i]),sum+=a[i];
	--n;--sum;--a[h];m=a[h];
	if(sum<n)
	{
		printf("-1\n");
		return 0;
	}
	f[0][m]=1;
	for(i=0;i<n;++i)
	for(j=0;j<=m;++j)
	{
		f[i+1][j]+=f[i][j]*(sum-i-j)/(sum-i);
		if(j)f[i+1][j-1]+=f[i][j]*j/(sum-i);
	}
	for(i=0;i<m;++i)ans+=f[n][i];
	printf("%.9lf\n",ans);
}