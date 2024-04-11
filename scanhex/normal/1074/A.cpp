#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

struct seg
{
	 int x1, x2, y;
	 seg ()
	 {}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> xs(n);
	for (auto& x : xs)
		cin >> x;
	vector<seg> v(m);
	for (auto& x : v)
		cin >> x.x1 >> x.x2 >> x.y;
	sort(xs.begin(), xs.end());
	vector<seg> v1;
	for (auto& x : v)
		if (x.x1 == 1)
			v1.push_back(x);
	v = v1;
	sort(v.begin(), v.end(), [&](seg a, seg b)
			{
				return a.x2 < b.x2;
			});
	int ptr = 0;
	int ans = 1e9;
	xs.push_back(1e9);
	for (int i = 0; i <= n; ++i)
	{
		int x = xs[i]; // all <= x
		while (ptr < v.size() && v[ptr].x2 < x)
			++ptr;
		ans = min(ans, (int)v.size() - ptr + i);
	}
	cout << ans << '\n';
	return 0;
}