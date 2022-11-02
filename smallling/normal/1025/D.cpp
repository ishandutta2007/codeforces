#include <bits/stdc++.h>

using namespace std;

int n, flag[710][710], f[710][710][2], a[710];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		f[i][i][0] = f[i][i][1] = 1;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(__gcd(a[i], a[j]) > 1)flag[i][j] = 1;
	for(int i = 2; i <= n; i++)
		for(int l = 1; l + i - 1 <= n; l++)
		{
			int r = l + i - 1;
			for(int k = l; k < r; k++)
				if(flag[r][k] && f[l][k][0] &&f[k][r - 1][1])
				{
					f[l][r][0] = 1;
					break;
				}
			for(int k = l + 1; k <= r; k++)
				if(flag[l][k] && f[k][r][1] && f[l + 1][k][0])
				{
					f[l][r][1] = 1;
					break;
				}
		}
	for(int i = 1; i <= n; i++)
		if(f[1][i][0] && f[i][n][1])
		{
			puts("Yes");
			return 0;
		}
	puts("No");
}