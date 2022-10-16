#include <cstdio>
using namespace std;
const int B=805;
int n,k,t;
int i,j;
double f[2][B];
int main()
{
	scanf("%d%d",&n,&k);
	t=n;
	if (t>=800)
		t=800;
	for (i=1;i<=n;i++)
		for (j=1;j<=t;j++)
			f[i&1][j]=((f[i&1^1][j+1]+j)+j*(f[i&1^1][j]+(j+1)/2.0))/(j+1.0)/(k*1.0)+(k-1)*f[i&1^1][j]/(k*1.0);
	printf("%.10lf\n",f[n&1][1]*k);
	return 0;
}