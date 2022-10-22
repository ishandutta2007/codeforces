#include <bits/stdc++.h>

using namespace std;
typedef int nagai;

int main()
{
	ios::sync_with_stdio(false);
	int k, n;
	cin >> k >> n;
	vector<int> t(n);
	for (auto& x : t)
		cin >> x;
	sort(t.begin(), t.end());
	vector<int> t1(n - 1);
	for (int i = 0; i + 1 < n; ++i)
		t1[i] = t[i + 1] - t[i];
	--n;
	t = t1;
	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int a, int b)
			{
				return t[a] < t[b];
			});
	int sz = min(2 * k + 5, n);
	vector<int> ord1(ord.begin(), ord.begin() + sz);
	sort(ord1.begin(), ord1.end());
	n = sz;
	ord = ord1;
	nagai oo = 1e9;
	vector<vector<nagai>> dp(n + 1, vector<nagai>(k + 1, oo));
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= k; ++j)
		{
			dp[i][j] = dp[i - 1][j];
			if (j > 0)
			{
				if (i == 1 || ord[i - 1] > ord[i - 2] + 1)
					dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + t[ord[i - 1]]);
				else
					dp[i][j] = min(dp[i][j], dp[i - 2][j - 1] + t[ord[i - 1]]);
			}
		}
	cout << dp[n][k] << '\n';
}