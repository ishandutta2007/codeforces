#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n,k,p;
int a[300030];
long long f[5010][5010];

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	memset(f,0x3f,sizeof(f));
	p=n%k;
	f[0][0]=0;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<p;j++)
			f[i+1][j]=min(f[i+1][j],f[i][j]+a[i*(n/k)+j+n/k]-a[i*(n/k)+j+1]),
			f[i+1][j+1]=min(f[i+1][j+1],f[i][j]+a[i*(n/k)+j+n/k+1]-a[i*(n/k)+j+1]);
		f[i+1][p]=min(f[i+1][p],f[i][p]+a[i*(n/k)+p+n/k]-a[i*(n/k)+p+1]);
	}
	printf("%I64d",f[k][p]);
}