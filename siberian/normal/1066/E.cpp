#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>
using namespace std;
#define INF 998244353
#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)
#define int long long
int pows[200010];
int dp[200010];

signed main()
{
	FAST;
	pows[0] = 1;
	dp[0] = 0;
	for (int i = 1; i < 200010; i++)
	{
		pows[i] = pows[i - 1];
		pows[i] *= 2;
		pows[i] %= INF;
		dp[i] = 0;
	}

	int n, m;
	cin >> n >> m;
	string s1, s2;
	cin >> s1 >> s2;
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	dp[0] = 0;
	if (s1[0] == '1')
		dp[0] = 1;
	for (int i = 1; i < n; i++)
	{
		dp[i] += dp[i - 1];
		if (s1[i] == '1')
		{
			dp[i] += pows[i];
			dp[i] %= INF;
		}
	}
	int ans = 0;
	

	for (int i = 0; i < min(n, m); i++)
	{
		if (s2[i] == '1')
		{
			ans += dp[i];
			ans %= INF;
		}
	}
	if (m > n)
	{
		for (int i = n; i < m; i++)
		{
			if (s2[i] == '1')
			{
				ans += dp[n - 1];
				ans %= INF;
			}
			}
	}
			cout << ans;
	return 0;
}