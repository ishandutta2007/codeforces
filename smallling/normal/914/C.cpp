#include <bits/stdc++.h>

using namespace std;

const int mo = 1e9 + 7;

char a[1010];
int f[1010][2][1010], dp[1010][1010];

inline void up(int &a, int b)
{
	a += b;
	if(a >= mo)a -= mo;
}

int main()
{
	scanf("%s", a + 1);
	int l = strlen(a + 1), k;
	scanf("%d", &k);
	if(k == 0)
	{
		puts("1");
		return 0;
	}
	f[1][0][0] = 1;
	f[1][1][1] = 1;
	for(int i = 1; i < l; i++)
	{
		for(int j = 0; j <= 1000; j++)
		{
			up(f[i + 1][0][j], f[i][0][j]);
			up(f[i + 1][0][j + 1], f[i][0][j]);
			if(a[i + 1] == '0')
			{
				up(f[i + 1][1][j], f[i][1][j]);
			}
			else
			{
				up(f[i + 1][1][j + 1], f[i][1][j]);
				up(f[i + 1][0][j], f[i][1][j]);
			}
		}
	}
	for(int i = 0; i <= 1000; i++)
	{
		dp[1][i] = f[l][0][i] + f[l][1][i];
		if(dp[1][i] >= mo)dp[1][i] -= mo;
	}
	dp[1][1]--;
	if(dp[1][1] < 0)dp[1][1] += mo; 
	for(int i = 1; i < k; i++)
	{
		for(int j = 2; j <= 1000; j++)
			up(dp[i + 1][__builtin_popcount(j)], dp[i][j]);
	}
	printf("%d\n", dp[k][1]);
}