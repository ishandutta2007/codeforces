#include<bits/stdc++.h>
using namespace std;
int a[123456];

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		long long ans = 0;
		int w = 0;
		int x = 0;
		int y = 0;
		int z = 0;
		for(int i = 1; i < n - 1; i++)
		{
			ans += (a[i] + 1) / 2;
			if(a[i] >= 4) w++;
			if(a[i] >= 2) x++;
			if(a[i] > 0) y++;
			if(a[i] & 1) z++;
		}
		if(ans == 0) printf("0\n");
		else if(!x) printf("-1\n");
		else if(z && n == 3) printf("-1\n");
		else if(!w && z && (y == 1)) printf("-1\n");
		else if(z && (y == 1)) printf("%lld\n", ans + 1);
		else printf("%lld\n", ans);
	}
	return 0;
 }