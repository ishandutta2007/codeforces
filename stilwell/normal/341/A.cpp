#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,i,j,k;
long long a[100005],ans1,ans2,sum,g;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	ans2=n;
	for(i=1;i<=n;++i)
	{
		ans1+=a[i];
		ans1+=(a[i]*(i-1)-sum)*2;
		sum+=a[i];
	}
	g=__gcd(ans1,ans2);
	ans1/=g;ans2/=g;
	printf("%I64d %I64d\n",ans1,ans2);
}