#include <bits/stdc++.h>

#define int long long
using namespace std;

pair<int, int> inter(pair<int, int> a, pair<int, int> b)
{
	if (a.first > b.first) swap(a, b);
	return { max(a.first, b.first) , min(a.second, b.second) };
}

signed main()
{
	int n, q;
	cin >> n >> q;
	vector<pair<int, int>> a(q);
	for (int i = 0; i < q; ++i) cin >> a[i].first >> a[i].second;
	int ans = 0;
	vector<int> cnt(n + 1);
	for (auto i : a)
	{
		for (int j = i.first; j <= i.second; ++j) cnt[j] ++;
	}
	vector<pair<int, int>> b;
	vector<int> pref(n + 1);
	vector<int> pref2(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		pref[i] = pref[i - 1] + (cnt[i] == 1);
		pref2[i] = pref2[i - 1] + (cnt[i] == 2);
	}
	int am = 0;
	for (int i = 1; i <= n; ++i) if (cnt[i] == 0) am++;
	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = 0; j < a.size(); ++j)
		{
			if (a[i].first > a[j].first) continue;
			if (i == j) continue;
			pair<int, int> x = inter(a[i], a[j]);
			int ta = 0;
			if (x.second >= x.first)
			{
				ta = pref2[x.second] - pref2[x.first - 1];
			}
			ta += pref[a[i].second] - pref[a[i].first - 1];
			ta += pref[a[j].second] - pref[a[j].first - 1];
			ans = max(ans, n - ta);
		}
	}
	cout << ans - am;
	return 0;
}