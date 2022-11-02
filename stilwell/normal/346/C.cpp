#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,l,r,ans;
int x[100005],f[1000005];

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&x[i]);
	scanf("%d%d",&r,&l);m=r-l;
	sort(x+1,x+n+1);
	for(i=1;i<=m;++i)f[i]=i-1;
	for(i=1;i<=n;++i)
	if(x[i]!=x[i-1])
	{
		k=x[i]-l%x[i];
		for(;k<=m;k+=x[i])if(k>=x[i]&&k-x[i]<f[k-1])f[k-1]=k-x[i];
		if(k>=x[i]&&k-x[i]<f[m])f[m]=k-x[i];
	}
	for(i=m-1;i>=1;--i)if(f[i+1]<f[i])f[i]=f[i+1];
	for(k=m;k;k=f[k])++ans;
	printf("%d\n",ans);
}