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
		for(int i = 0; i <= 100; i++) a[i] = 0;
		for(int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			if (x < 0) x = -x;
			a[x]++;
		}
		int ans = 0;
		if(a[0]) ans++;
		for(int i = 1; i <= 100; i++)
		{
			if(a[i] == 1) ans ++;
			else if(a[i] > 1) ans += 2;
		}
		printf("%d\n", ans);
	}

	return 0;
 }