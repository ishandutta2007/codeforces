#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
int a[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)
	{
		if(a[i]<0||((int)sqrt(a[i])*sqrt(a[i])!=a[i]))
		{
			printf("%d\n",a[i]);
			return 0;
		}
	}
	return 0;
}