#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; cin >> T;
	while (T--) {
		long long x; cin >> x;
		if (x % 2050 != 0) {
			cout << -1 << endl;
			continue;
		}
		x /= 2050;
		int sum = 0;
		while (x) sum += x % 10, x /= 10;
		cout << sum << endl;
	}
	return 0;
}