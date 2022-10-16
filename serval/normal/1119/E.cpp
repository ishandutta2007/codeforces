#include <cstdio>
#include <algorithm>
using namespace std;
const int N=300005;
int n;
long long a[N],b[N];
long long ans,rem,d;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++)
	{
		ans=ans+a[i]/3;
		b[i]=a[i]%3;
	}
	rem=0;
	for (int i=1;i<=n;i++)
	{
		d=min(rem,b[i]/2);
		ans+=d;
		rem-=d;
		b[i]-=d*2;
		a[i]-=d*2;
		d=min(rem/2,b[i]);
		d=min(d,(a[i]-b[i])/3);
		ans+=d;
		rem-=d*2;
		b[i]-=d;
		a[i]-=d*2;
		d=min(rem/3,(a[i]-b[i])/6);
		ans+=d;
		rem-=d*3;
		a[i]-=d*6;
		rem+=b[i];
	}
	printf("%lld\n",ans);
	return 0;
}