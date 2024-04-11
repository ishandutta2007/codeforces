#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

int m = 5;

int get(int x, int y)
{
	if (x > y / 2)
		return 500;
	if (x > y / 4)
		return 1000;
	if (x > y / 8)
		return 1500;
	if (x > y / 16)
		return 2000;
	if (x > y / 32)
		return 2500;
	return 3000;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(m));
	for (auto& x : v)
		for (auto& y : x)
			cin >> y;
	vector<int> cnt(m);
	for (auto x : v)
		for (int i = 0; i < m; ++i)
			if (x[i] >= 0)
				++cnt[i];
	vector<pair<int, int>> ev;
	int mx = 2000000014;
	for (int i = 0; i < m; ++i)
	{
		if (v[0][i] == -1)
			v[0][i] = 250;
		if (v[1][i] == -1)
			v[1][i] = 250;
		if (v[0][i] < v[1][i] || v[0][i] == 250)
		{
			//   ,    
			int cur = get(cnt[i], n);
			nagai curadd = 0;
			while (cur < 3000)
			{
				nagai L = 0, R = 1000000000000000LL;
				while (R - L > 1)
				{
					int M = (L + R) / 2;
					if (get(cnt[i], n + curadd + M) > cur)
						R = M;
					else
						L = M;
				}
				curadd += R;
				cur = get(cnt[i], n + curadd);
				ev.push_back({curadd, 2 * (v[1][i] - v[0][i])});
			}
		}
		else
		{
			//   ,   
			int cur = get(cnt[i], n);
			nagai curadd = 0;
			while (cur > 500)
			{
				nagai L = 0, R = 1000000000000000LL;
				while (R - L > 1)
				{
					int M = (L + R) / 2;
					if (get(cnt[i] + curadd + M, n + curadd + M) < cur)
						R = M;
					else
						L = M;
				}
				curadd += R;
				cur = get(cnt[i] + curadd, n + curadd);
				ev.push_back({curadd, 2 * (v[1][i] - v[0][i])});
			}
		}
	}
	sort(ev.begin(), ev.end());
	int cur = 0;
	for (int i = 0; i < m; ++i)
		cur += get(cnt[i], n) * (v[1][i] - v[0][i]) / 250;
	if (cur > 0)
	{
		cout << 0 << endl;
		return 0;
	}
	for (auto x : ev)
	{
		cur += x.second;
		if (cur > 0)
		{
			cout << x.first << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}