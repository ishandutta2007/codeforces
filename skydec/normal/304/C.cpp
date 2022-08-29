#include<stdio.h>
using namespace std;
long n;
long a[100005];long b[100005];long c[100005];
int main()
{
	scanf("%ld",&n);
	if((n%2==0))
	{
		printf("-1\n");
		return 0;
	}
	for(long i=0;i<=n-1;i++)a[i+1]=i;
	b[1]=n-1;for(long i=0;i<=n-2;i++)b[i+2]=i;
	for(long i=1;i<=n;i++)c[i]=(a[i]+b[i])%n;
	for(long i=1;i<=n-1;i++)printf("%ld ",a[i]);printf("%ld\n",a[n]);
	for(long i=1;i<=n-1;i++)printf("%ld ",b[i]);printf("%ld\n",b[n]);
	for(long i=1;i<=n-1;i++)printf("%ld ",c[i]);printf("%ld\n",c[n]);
	return 0;
}