#include <bits/stdc++.h>
using namespace std;

void solve() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << (n - 1) / 2 << "\n";
	}
}

int main() {
	solve();
#ifdef SERT
	int t = 1;
	for (int i = 1; i < t; i++) {
		solve();
	}
#endif
}