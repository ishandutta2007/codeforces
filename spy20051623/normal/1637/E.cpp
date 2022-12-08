#include <bits/stdc++.h>

using namespace std;

int a[300005], nxt[300005];
vector<int> v[300005];
map<int, int> mp;

void solve() {
	int n, m;
	cin >> n >> m;
	mp.clear();
	for (int i = 1; i <= n; ++i) {
		v[i].clear();
		nxt[i] = -1;
	}
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		++mp[a[i]];
	}
	for (auto i: mp) {
		v[i.second].push_back(i.first);
	}
	int lst = 0;
	for (int i = 1; i <= n; ++i) {
		if (!v[i].empty()) {
			reverse(v[i].begin(), v[i].end());
			nxt[lst] = i;
			lst = i;
		}
	}
	set<long long> s;
	const long long e = 1e9 + 7;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		s.insert(x * e + y);
		s.insert(y * e + x);
	}
	long long ans = 0;
	for (auto i: mp) {
		int num = i.first, cnt = i.second;
		for (int j = nxt[0]; j != -1; j = nxt[j]) {
			for (int k: v[j]) {
				if (k == num || s.find(k * e + num) != s.end()) continue;
				ans = max(ans, 1ll * (num + k) * (cnt + mp[k]));
				break;
			}
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
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}