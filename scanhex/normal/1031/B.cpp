#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n - 1), b(n - 1);
	for (auto& x : a)
		cin >> x;
	for (auto& y : b)
		cin >> y;
	vector<vector<bool>> dp(n, vector<bool>(4));
	vector<vector<int>> prev(n, vector<int>(4, -1));
	for (int i = 0; i < 4; ++i)
		dp[0][i] = true;
	for (int i = 0; i + 1 < n; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (!dp[i][j])
				continue;
			for (int k = 0; k < 4; ++k)
			{
				if ((j | k) == a[i] && (j & k) == b[i])
					dp[i + 1][k] = true, prev[i + 1][k] = j;
			}
		}
	}
	int memos = -1;
	for (int i = 0; i < 4; ++i)
		if (dp.back()[i])
			memos = i;
	if (memos == -1)
	{
		 cout << "NO\n";
		 return 0;
	}
	cout << "YES\n";
	vector<int> ans;
	int curi = n - 1;
	while (curi >= 0)
	{
		ans.push_back(memos);
		memos = prev[curi][memos];
		--curi;
	}
	reverse(ans.begin(), ans.end());
	for (int x : ans)
		cout << x << ' ';
	cout << '\n';
	return 0;
}