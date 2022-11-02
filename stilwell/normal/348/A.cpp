#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,i,j,k;
long long l,r,mid,ans,sum;
int a[100005];

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	l=a[n];r=a[n]*2;
	while(l<=r)
	{
		mid=l+r>>1;sum=0;
		for(i=1;i<=n;++i)sum+=mid-a[i];
		if(sum>=mid)ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%I64d\n",ans);
}