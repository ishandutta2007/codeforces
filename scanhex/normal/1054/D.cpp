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
	vector<int> a(n);
	for (auto& x : a)
		cin >> x;
	vector<int> pref(n + 1);
	for (int i = 0; i < n; ++i)
		pref[i + 1] = pref[i] ^ a[i];
	map<int, int> cnt;
	int mx = (1 << k) - 1;
	for (int x : pref)
		++cnt[min(x, x ^ mx)];
	nagai ans = 0;
	for (auto& x : cnt)
	{
		int mem = x.second / 2;
		int kek = x.second - mem;
		ans += (nagai)mem * (mem - 1) / 2;
		ans += (nagai)kek * (kek - 1) / 2;
	}
	ans = (nagai)n * (n + 1) / 2 - ans;
	cout << ans << '\n';
	return 0;
}