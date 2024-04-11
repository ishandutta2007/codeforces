#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k;
int a[105],b[105],f[105][105];

void Min(int &a,int b){if(b<a)a=b;}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);a[0]=a[n];
	for(i=1;i<=n;++i)scanf("%d",&b[i]);b[0]=b[n];
	for(i=0;i<=n*4;++i)
	for(j=0;j<=n*4;++j)
	f[i][j]=100000000;
	f[0][0]=0;
	for(i=0;i<n*4;++i)
	for(j=0;j<=n+n;++j)
	{
		if(j>0)Min(f[i+1][j-1],f[i][j]+b[(i+1)%n]);
		if(j<n)Min(f[i+1][j+1],f[i][j]+a[(i+1)%n]);
	}
	if(m<=3)printf("%d\n",f[n*m][0]);
	else printf("%I64d\n",f[n*4][0]+(long long)(m-4)/2*(f[n*4][0]-f[n*2][0]));
}