#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100011;
typedef long long intl;
const intl Inf = 0x3f3f3f3f3f3f3f3fLL;

int v[N], c[N];
intl dp[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i ++)
		cin >> v[i];
	for(int i = 1; i <= n; i ++)
		cin >> c[i];

	while(q --)
	{
		intl a, b;
		cin >> a >> b;
		intl dp0 = 0, c0 = 0;
		intl dp1 = 0, c1 = 0;
		fill(dp + 1, dp + n + 1, -Inf);
		for(int i = 1; i <= n; i ++)
		{
			if(dp[c[i]] != -Inf)
				dp[c[i]] = max(dp[c[i]], dp[c[i]] + v[i] * a);
			if(c0 == c[i])
				dp[c[i]] = max(dp[c[i]], dp1 + v[i] * b);
			else
				dp[c[i]] = max(dp[c[i]], dp0 + v[i] * b);
			if(c[i] == c0)
				dp0 = dp[c[i]];
			else if(c[i] == c1)
			{
				dp1 = dp[c[i]];
				if(dp1 > dp0)
				{
					swap(dp1, dp0);
					swap(c1, c0);
				}
			}
			else if(dp[c[i]] > dp0)
			{
				dp1 = dp0;
				c1 = c0;
				dp0 = dp[c[i]];
				c0 = c[i];
			}
			else if(dp[c[i]] > dp1)
			{
				dp1 = dp[c[i]];
				c1 = c[i];
			}
		}

		cout << dp0 << '\n';
	}
	return 0;
}