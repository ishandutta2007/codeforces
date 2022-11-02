#include <iostream>
#include <algorithm>
using namespace std;
int n, m, x[200039], a[200039];
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		cin >> x[i]; a[i] = x[i];
	}
	int l = 1012345678, r = -1;
	for (int i = 0; i < n + 31; i++) {
		a[i + 1] += (a[i] - (a[i] & 1)) / 2; a[i] &= 1;
		if (a[i] == 1) {
			l = min(l, i);
			r = max(r, i + 1);
		}
	}
	if (a[n + 31] < 0) {
		fill(a, a + n + 32, 0);
		for (int i = 0; i <= n; i++) x[i] *= -1, a[i] = x[i];
		l = 1012345678, r = -1;
		for (int i = 0; i < n + 31; i++) {
			a[i + 1] += (a[i] - (a[i] & 1)) / 2; a[i] &= 1;
			if (a[i] == 1) {
				l = min(l, i);
				r = max(r, i + 1);
			}
		}
	}
	if (r - l >= 31) cout << 0 << endl;
	else {
		long long b = 0; int ret = 0;
		for (int i = l; i < r; i++) b |= a[i] << (i - l);
		for (int i = l; i >= 0 && b <= 2000000000; i--) {
			if (-m <= x[i] - b && x[i] - b <= m) ret++;
			if (i > n || (i == n && x[i] == b)) ret--;
			b <<= 1;
		}
		cout << ret << endl;
	}
	return 0;
}