#include <cstdio>
#include <algorithm>
using namespace std;
int a[15],n,i,j;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (i=1;i<=n;i++)
		printf("%d ",a[i]);
	for (i=1;i<=20000;i++)
		for (j=1;j<=20000;j++)
			a[i%n+1]=max(a[i%n+1]-a[j%n+1],0);
	return 0;
}