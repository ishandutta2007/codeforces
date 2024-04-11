#include<bits/stdc++.h>
using namespace std;
long long a[5123];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
	long long ans = 12345678912345678ll;
	for(int i = 0; i < n; i++)
	{
		long long z = 0;
		long long pans = 0;
		for(int j = i - 1; j >= 0; j--)
		{
			long long k = (a[j] + z) / a[j];
			pans += k;
			z = k * a[j];
		}
		z = 0;
		for(int j = i + 1; j < n; j++)
		{
			long long k = (a[j] + z) / a[j];
			pans += k;
			z = k * a[j];			
		}
		ans = min(ans, pans);
	}
	printf("%lld\n", ans);
	return 0;
 }