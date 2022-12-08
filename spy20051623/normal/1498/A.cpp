#include <bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y) {
	long long t;
	while (t = x % y) {
		x = y;
		y = t;
	}
	return y;
}

void solve() {
	long long n, i, j, k;
	cin >> n;
	for (i = n;; ++i) {
		j = i;
		k = 0;
		while (j) {
			k += j % 10;
			j /= 10;
		}
		if (gcd(i, k) > 1) {
			cout << i << endl;
			return;
		}
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}