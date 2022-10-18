#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		long long ans = 0;
		int d = 0;
		int mx = 0;
		for(int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			while(x % 2 == 0) 
			{
				d ++;
				x /= 2;
			
			}
			mx = max(mx, x);
			ans += x;
		}
		ans -= mx;
		ans += (mx) * (1ll << d);
		printf("%lld\n", ans);
	}
	return 0;
}