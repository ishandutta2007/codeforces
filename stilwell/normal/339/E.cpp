#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,i,j,k;
int a[1005],ansl[15],ansr[15];

void work(int x)
{
	int i,j,k;
	for(i=1;i<=n;++i)if(a[i]!=i)break;
	if(i>n)
	{
		printf("%d\n",x-1);
		for(i=x-1;i>=1;--i)printf("%d %d\n",ansl[i],ansr[i]);
		exit(0);
	}
	if(x==4)return;
	for(i=1;i<=n;++i)
	if(a[i]!=i&&(abs(a[i]-a[i-1])!=1||abs(a[i]-a[i+1])!=1))
	for(j=i+1;j<=n;++j)
	if(a[j]!=j&&(abs(a[j]-a[j-1])!=1||abs(a[j]-a[j+1])!=1))
	{
		reverse(a+i,a+j+1);
		ansl[x]=i;ansr[x]=j;
		work(x+1);
		reverse(a+i,a+j+1);
	}
}

int main()
{
	scanf("%d",&n);a[0]=a[n+1]=-1;
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	work(1);
}