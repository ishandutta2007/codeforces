#include<bits/stdc++.h>
using namespace std;
long long a[123456];
long long b[123456];
long long aa[123456];
long long bb[123456];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i = 0;i<n;i++)
	{
		scanf("%lld",&b[i]);
	}
	for(int i = 0;i<n-1;i++)
	{
		aa[i] = a[i+1] - a[i];
		bb[i] = b[i+1] - b[i];
	}
	sort(aa,aa+n-1);
	sort(bb,bb+n-1);
	int g = 0;
	for(int i = 0;i<n-1;i++) if(aa[i]!=bb[i]) g = 1;
	if(!g)
	{
		if(a[0]==b[0]) if(a[n-1]==b[n-1])
		{
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}