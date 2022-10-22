#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), b(n), x(n), y(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> b[i];
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> y[i];
	map<pair<int, int>, int> cnt;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			++cnt[make_pair(a[i] + x[j], b[i] + y[j])];
		}
	for (auto& x : cnt)
		if (x.second == n)
		{
			cout << x.first.first << ' ' << x.first.second << '\n';
			return 0;
		}
	return 0;
}