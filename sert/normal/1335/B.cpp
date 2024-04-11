#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		if (i % a < b) cout << char('a' + i % a);
		else cout << 'a';
	}
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