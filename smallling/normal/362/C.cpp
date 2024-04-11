#include<cstdio>
#include<algorithm>

using namespace std;

int i,j,n,m;
int a[5001],f[5001][5001],g[5001][5001],d,b[5001*5001/2];

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	if(a[j]<a[i])f[i][j]=f[i][j-1]+1;
	else f[i][j]=f[i][j-1];
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	if(a[j]>a[i])g[i][j]=g[i][j-1]+1;
	else g[i][j]=g[i][j-1];
	for(i=1;i<n;i++)
	for(j=i+1;j<=n;j++)
	if(a[i]>a[j])
	{
		b[++m]=(f[i][j-1]-f[i][i])-(f[j][j-1]-f[j][i])-(g[i][j-1]-g[i][i])+(g[j][j-1]-g[j][i])+1;
	}
	for(i=1;i<n;i++)
	for(j=i+1;j<=n;j++)
	if(a[i]>a[j])d++;
	sort(b+1,b+1+m);
	int o=0;
	for(j=m;j;j--)
	if(b[j]==b[m])o++;
	printf("%d %d",d-b[m],o);
}