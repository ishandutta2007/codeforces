#include<bits/stdc++.h>
using namespace std;
int a[123456];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, d;
		scanf("%d %d", &n, &d);
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		int ans = 0;
		int pos = 1;
		for(int i = 1; i < n; i++)
		{
			a[0] += min(a[i], d / i);
			d -= min(a[i] * i, d);
		}
		printf("%d\n", a[0]);
	}
	return 0;
}