#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k,ll,rr,val;
int a[200005],l[200005],r[200005],Max[200005];

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	l[1]=1;
	for(i=2;i<=n;++i)
	{
		for(j=i;j>1&&a[j-1]>=a[i];j=l[j-1]);
		l[i]=j;
	}
	r[n]=n;
	for(i=n-1;i>=1;--i)
	{
		for(j=i;j<n&&a[j+1]>=a[i];j=r[j+1]);
		r[i]=j;
	}
	for(i=1;i<=n;++i)
	{
		k=r[i]-l[i]+1;
		if(a[i]>Max[k])Max[k]=a[i];
	}
	for(i=n;i>=1;--i)if(Max[i]>=Max[i-1])Max[i-1]=Max[i];
	for(i=1;i<=n;++i)printf("%d ",Max[i]);
	printf("\n");
}