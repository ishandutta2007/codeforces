#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; cin >> T;
	while (T--) {
		long long n, x, t; cin >> n >> x >> t;
		long long delta = t / x;
		long long ans = 0;
		if (n - 1 <= delta) ans = n * (n - 1) / 2;
		else ans = delta * (n - delta - 1) + delta * (delta + 1) / 2;
		cout << ans << endl;
	}
	return 0;
}