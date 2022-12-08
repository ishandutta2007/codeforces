#include <bits/stdc++.h>

using namespace std;

int a[200005], b[200005], c[200005];

void solve() {
	int n;
	cin >> n;
	fill(b, b + n + 5, 0);
	fill(c, c + n + 5, 0);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		++c[a[i]];
	}
	vector<int> v;
	int cnt = 0;
	int pos = 0;
	while (c[0]) {
		int p;
		for (int i = 0; i <= n; ++i) {
			if (!c[i]) {
				p = i;
				break;
			}
		}
		v.push_back(p);
		if (p) {
			cnt = p;
			fill(b, b + p + 5, 0);
			for (int i = pos; i < n; ++i) {
				++pos;
				--c[a[i]];
				if (a[i] < p && !b[a[i]]) b[a[i]] = 1, --cnt;
				if (cnt == 0) break;
			}
		}
	}
	for (int i = 0; i <= n; ++i) cnt += c[i];
	while (cnt--) v.push_back(0);
	cout << v.size() << '\n';
	if (!v.empty()) {
		for (int i: v) cout << i << ' ';
		cout << '\n';
	}
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