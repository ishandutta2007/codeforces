#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long a, b, c;
	cin >> a >> b >> c;
	cout << a + b + c - 1 << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}