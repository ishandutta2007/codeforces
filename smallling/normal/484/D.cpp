#include<cstdio>
#include<algorithm>

using namespace std;

int n,a[1000010];
long long Max,Min,f[1000010];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	Max=a[1];Min=-a[1];
	for(int i=1;i<=n;i++)
	{
		f[i]=max(Max-a[i],Min+a[i]);
		Max=max(Max,f[i]+a[i+1]);
		Min=max(Min,f[i]-a[i+1]);
	}
	printf("%I64d",f[n]);
}