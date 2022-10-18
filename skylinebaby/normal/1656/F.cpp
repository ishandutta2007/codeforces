#include<bits/stdc++.h>
using namespace std;
int a[212345];
long long s[212345];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		sort(a, a + n);
		s[0] = a[0];
		for(int i = 1; i < n; i++) s[i] = s[i - 1] + a[i];
		long long z = 1ll * a[0] * (n - 1) + (s[n - 1] - a[0]);
		if(z > 0)
		{
			printf("INF\n");
			continue;
		}
		z = 1ll * a[n - 1] * (n - 1) + s[n - 2];
		if(z < 0) 
		{
			printf("INF\n");
			continue;
		}
		long long ans = -1123456789123456789ll;
		for(int i = 0; i < n; i++)
		{
			int t = -a[i];
			z = 1ll * a[0] * a[n - 1] + 1ll * (a[0] + a[n - 1]) * t;
			z += (s[n - 2] - a[0]) * t;
			long long u = s[i] - a[0];
			long long v = s[n - 2] - s[i];
			u = u + 1ll * t * i;
			v = v + 1ll * t * (n - 2 - i);
			z += u * a[n - 1];
			z += v * a[0];
			ans = max(ans, z);
		}
		printf("%lld\n", ans);
	}
	return 0;
}