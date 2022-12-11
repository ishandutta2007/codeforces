#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int &x : a) cin >> x;
	for (int &x : b) cin >> x;
	vector<bool> neg(n + 1, false), pos(n + 1, false);
	for (int i = 0; i < n; i++) {
		neg[i + 1] = (neg[i] | (a[i] < 0));
		pos[i + 1] = (pos[i] | (a[i] > 0));
	}

	for (int i = n - 1; i >= 0; i--) {
		if (b[i] > a[i] && !pos[i]) { cout << "NO\n"; return; }
		if (b[i] < a[i] && !neg[i]) { cout << "NO\n"; return; }
	}
	cout << "YES\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}