#include <stdio.h>
#include <string.h>
typedef long long ll;
const int N=1e5+2;
int a[N];
int n,i;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",a+i);
	if (n==1) return printf("1 1\n1\n1 1\n1\n1 1\n%d",-a[1]-2),0;
	printf("2 %d\n",n);
	for (i=2;i<=n;i++) printf("%lld ",(ll)a[i]*(n-1));
	printf("\n1 %d\n",n);
	for (i=1;i<=n;i++) printf("%lld ",(ll)-a[i]*n);
	printf("\n1 1\n%lld",(ll)a[1]*(n-1));
}