#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, l;
	cin >> n >> m >> l;
	vector<nagai> a(n);
	for (auto& x : a)
		cin >> x;
	int cnt = 1;
	for (int i = 0; i + 1 < n; ++i)
	{
		if ((a[i] > l) != (a[i + 1] > l))
			++cnt;
	}
	auto proc = [&](int i, int j, int mul)
	{
		if (i < 0 || j >= n)
			return;
		if ((a[i] > l) != (a[j] > l))
			cnt += mul;
	};
	for (int i = 0; i < m; ++i)
	{
		int t;
		cin >> t;
		if (t == 0)
		{
			if (a[0] > l)
				cout << (cnt + 1) / 2 << '\n';
			else
				cout << cnt / 2 << '\n';
		}
		else
		{
			int x, y;
			cin >> x >> y;
			--x;
			proc(x - 1, x, -1);
			proc(x, x + 1, -1);
			a[x] += y;
			proc(x - 1, x, 1);
			proc(x, x + 1, 1);
		}
	}
	return 0;
}