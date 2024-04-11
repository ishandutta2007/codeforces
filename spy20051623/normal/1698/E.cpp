#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

void solve() {
	int n, s;
	cin >> n >> s;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].first;
	}
	for (int i = 0; i < n; ++i) {
		cin >> v[i].second;
	}
	sort(v.begin(), v.end());
	vector<int> b(n + 1), f(n + 1);
	for (int i = 1; i <= n; ++i) {
		b[i] = v[i - 1].second;
		if (b[i] != -1) f[b[i]] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		if (b[i] != -1 && b[i] < i - s) {
			cout << "0\n";
			return;
		}
	}
	int c = 0;
	for (int i = 1; i <= s; ++i) {
		if (!f[n + 1 - i]) ++c;
	}
	long long ans = 1;
	for (int i = n; i >= 1; --i) {
		if (i - s >= 1 && !f[i - s]) ++c;
		if (b[i] == -1) {
			ans = ans * c % mod;
			--c;
		}
	}
	cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}