#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,i,j,k;
long long ans,a[300005];

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%I64d",&a[i]);
	if(n==1)
	{
		printf("%I64d\n",a[1]);
		return 0;
	}
	if(n==2)
	{
		printf("%I64d\n",a[1]*2+a[2]*2);
		return 0;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;++i)
	if(i==1)ans+=a[i]*2;
	else if(i==n)ans+=a[i]*n;
	else ans+=a[i]*(1+i);
	printf("%I64d\n",ans);
}