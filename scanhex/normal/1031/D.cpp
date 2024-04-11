#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<string> matr(n);
	for (auto& x : matr)
		cin >> x;
	vector<vector<int>> mx(n, vector<int>(n));
	mx[0][0] = matr[0][0] == 'a';
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			 if (i + 1 < n)
				 mx[i + 1][j] = max(mx[i + 1][j], mx[i][j] + int(matr[i + 1][j] == 'a'));
			 if (j + 1 < n)
				 mx[i][j + 1] = max(mx[i][j + 1], mx[i][j] + int(matr[i][j + 1] == 'a'));
		}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (i + j - mx[i][j] < k)
				matr[i][j] = 'a';
	vector<pair<int, int>> cur = {{0, 0}};
	vector<pair<int, int>> nw;
	vector<vector<bool>> used(n, vector<bool>(n));
	string ans = {matr[0][0]};
	for (int i = 0; i < 2 * n - 2; ++i)
	{
		nw.clear();
		bool ok = false;
		for (int let = 'a'; let <= 'z'; ++let)
		{
			for (auto& [x, y] : cur)
			{
				if (x + 1 < n && matr[x + 1][y] == let && !used[x + 1][y])
					nw.emplace_back(x + 1, y), used[x + 1][y] = true;
				if (y + 1 < n && matr[x][y + 1] == let && !used[x][y + 1])
					nw.emplace_back(x, y + 1), used[x][y + 1] = true;
			}
			if (nw.size())
			{
				ans.push_back(let), cur.swap(nw);
				ok = true;
				break;
			}
		}
		if (!ok)
			return 239;
	}
	cout << ans << '\n';
	return 0;
}