#include<cstdio>
#include<algorithm>

using namespace std;

int a[101],n,i,j,b[101];

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	b[1]=a[n];
	b[n]=a[1];
	for(i=2;i<n;i++)
	b[i]=a[i];
	for(i=1;i<=n;i++)
	printf("%d ",b[i]);
}