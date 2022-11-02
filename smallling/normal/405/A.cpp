#include<cstdio>
#include<algorithm>

using namespace std;

int i,j,a[101],n;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	printf("%d ",a[i]);
}