#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int res[200005];

void solve() {
	for (auto k : m) {
		if (k.second == 1) {
			cout << res[k.first] << endl;
			return;
		}
	}
	cout << -1 << endl;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, i, j;
	cin >> t;
	while (t--) {
		m.clear();
		cin >> n;
		for (i = 1; i <= n; ++i) {
			cin >> j;
			res[j] = i;
			++m[j];
		}
		solve();
	}
	return 0;
}