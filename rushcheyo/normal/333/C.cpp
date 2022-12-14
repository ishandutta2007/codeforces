#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> a[5];

int main()
{
	int k, m;
	static int pw[9];
	pw[0] = 1;
	for (int i = 1; i <= 8; i++)
		pw[i] = pw[i - 1] * 10;
	cin >> k >> m;
	for (int d = 0; d <= 9; d++)
	{
		a[1].push_back(make_pair(d, d));
		if (d) a[1].push_back(make_pair(d, -d));
	}
	for (int i = 2; i <= 4; i++)
	{
		for (int j = 1; j < i; j++)
			for (auto x : a[j])
				for (auto y : a[i - j])
				{
					int b = x.first * pw[i - j] + y.first;
					a[i].push_back(make_pair(b, x.second + y.second));
					a[i].push_back(make_pair(b, x.second - y.second));
					a[i].push_back(make_pair(b, x.second * y.second));
				}
		sort(a[i].begin(), a[i].end());
		a[i].erase(unique(a[i].begin(), a[i].end()), a[i].end());
	}
	for (auto x : a[4])
	{
		if (m == 0) break;
		int ans = k + x.second;
		if (0 <= ans && ans <= 9999)
			printf("%04d%04d\n", x.first, ans), m--;
	}
	return 0;
}