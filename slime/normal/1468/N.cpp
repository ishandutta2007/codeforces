#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int a[5],c[3];
		for (int i = 0;i < 3;i++)
			scanf("%d",&c[i]);
		for (int i = 0;i < 5;i++)
			scanf("%d",&a[i]);
		c[0] -= a[0];
		c[1] -= a[1];
		c[2] -= a[2];
		if (c[0] < 0 || c[1] < 0 || c[2] < 0)
		{
			puts("NO");
			continue;
		}
		a[3] -= min(c[0],a[3]);
		c[2] -= a[3];
		a[4] -= min(c[1],a[4]);
		c[2] -= a[4];
		puts(c[2] < 0 ? "NO" : "YES");
	}
	return 0;
}