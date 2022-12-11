#include <bits/stdc++.h>
using namespace std;

void solve() {
	int x;
	cin >> x;
	int st = 1;
	vector<int> ans;
	while (st <= x) {
		if (x / st % 10) ans.push_back(st * (x / st % 10));
		st *= 10;
	}
	cout << ans.size() << "\n";
	for (int x : ans) cout << x << " ";
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}