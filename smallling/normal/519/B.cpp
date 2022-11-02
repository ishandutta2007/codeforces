#include<cstdio>
#include<algorithm>

using namespace std;

int n,a[100010],b[100010],c[100010];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
		scanf("%d",&b[i]);
	sort(b+1,b+n);
	for(int i=1;i<=n;i++)
		if(a[i]!=b[i])
		{
			printf("%d\n",a[i]);
			break;
		}
	for(int i=1;i<n-1;i++)
		scanf("%d",&c[i]);
	sort(c+1,c+n-1);
	for(int i=1;i<n;i++)
	{
		if(c[i]!=b[i])return printf("%d\n",b[i]),0;
	}
}