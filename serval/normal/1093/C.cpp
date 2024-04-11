#include <cstdio>
using namespace std;
const int N=200005;
int n;
long long b[N];
long long a[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n/2;i++)
	{
		scanf("%lld",&b[i]);
		a[n-i+1]=b[i];
	}
	for (int i=n-1;i>n/2;i--)
	{
		if (a[i+1]<a[i])
			a[i]=a[i+1];
		if (a[n-i]>b[n-i+1]-a[i])
			a[i]=b[n-i+1]-a[n-i];
		a[n-i+1]=b[n-i+1]-a[i];
	}
	for (int i=1;i<=n;i++)
		printf("%lld ",a[i]);
	printf("\n");
	return 0;
}