#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long n;
	cin >> n;
	cout << 2 * (1 << (n / 2)) - 2 << "\n";
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