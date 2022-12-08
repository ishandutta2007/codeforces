#include <bits/stdc++.h>

using namespace std;

int ask(int x) {
	cout << "? " << x << endl;
	int y;
	cin >> y;
	return y;
}

int ans[10005];

void solve() {
	int n;
	cin >> n;
	fill(ans, ans + n + 5, 0);
	for (int i = 1; i <= n; ++i) {
		if (ans[i]) continue;
		vector<int> v;
		v.push_back(ask(i));
		do {
			v.push_back(ask(i));
		} while (v.front() != v.back());
		for (int j = 0; j < v.size() - 1; ++j) {
			ans[v[j]] = v[j + 1];
		}
	}
	cout << "! ";
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << endl;
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