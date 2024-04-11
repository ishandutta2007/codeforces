#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

nagai oo = 1e18;

nagai solve3(vector<pair<nagai, nagai>> v)
{
	int n = v.size();
	nagai ans = 0;
	nagai mxx = -oo, mxy = -oo;
	for (auto& [x, y] : v)
		mxx = max(mxx, x), mxy = max(mxy, y);
	for (auto& [x, y] : v)
		ans = max(ans, mxx - x + mxy - y);
	return 2 * ans;
}

void rot(vector<pair<nagai, nagai>>& v)
{
	for (auto& p : v)
		p = {-p.second, p.first};
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<nagai, nagai>> v(n);
	for (auto& [x, y] : v)
		cin >> x >> y;
	nagai ans4 = 0;
	for (int i = 0; i < n; ++i)
	{
		 int j = i + 1 == n ? 0 : i + 1;
		 ans4 += abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
	}
	nagai ans3 = 0;
	for (int i = 0; i < 4; ++i)
	{
		ans3 = max(ans3, solve3(v));
		rot(v);
	}
	cout << ans3 << ' ';
	for (int i = 4; i <= n; ++i)
		cout << ans4 << ' ';
	cout << '\n';
	return 0;
}