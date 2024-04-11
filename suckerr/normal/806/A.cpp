#include <bits/stdc++.h>

using namespace std;

int t;
int x, y, p, q;

bool solve(long long k) {
	long long kp = k * p;
	long long kq = k * q;
	if (kq < y) return false;
	long long lower = x, upper = x + kq - y;
	// cout << (long long)lower << " " << (long long)upper << " " << (long long)kq << " " << (long long)kp << endl;
	if (kp < lower) return false;
	if (kp > upper) return false;
	return true;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d %d", &x, &y, &p, &q);
		long long l = 1, r = 1e9;
		while (l < r) {
			long long k = (l + r) / 2;
			if (!solve(k)) {
				l = k + 1;
			} else {
				r = k;
			}
		}
		if (!solve(l)) {
			cout << -1 << endl;
		} else {
			cout << (1LL * l * q - y) << endl;
		}
	}
	return 0;
}