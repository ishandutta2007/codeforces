#include <bits/stdc++.h>

using namespace std;

void solve() {
	vector<int> l(3);
	for (int i = 0; i < 3; ++i) {
		cin >> l[i];
	}
	sort(l.begin(), l.end());
	do {
		if (l[1] + l[2] == l[0]) {
			cout << "YES\n";
			return;
		}
		if (l[1] == l[2] && l[0] % 2 == 0) {
			cout << "YES\n";
			return;
		}
	} while (next_permutation(l.begin(), l.end()));
	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}