#include <bits/stdc++.h>

using namespace std;

pair<int, int> p[3];

void solve() {
	for (auto &i: p) {
		cin >> i.first >> i.second;
	}
	sort(p, p + 3, [&](pair<int, int> x, pair<int, int> y) { return x.second < y.second; });
	if (p[1].second == p[2].second) cout << abs(p[1].first - p[2].first) << '\n';
	else cout << "0\n";
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