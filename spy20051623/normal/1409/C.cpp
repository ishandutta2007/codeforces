#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, x, y, i, j, k;
	cin >> t;
	while (t--) {
		cin >> n >> x >> y;
		k = abs(x - y);
		for (i = 1; i <= k; ++i) {
			if (k % i == 0 && k / i + 1 <= n)
				break;
		}
		for (j = min(x, y); j <= max(x, y); j += i, --n) {
			cout << j << ' ';
		}
		for (j = min(x, y) - i; j > 0 && n > 0; j -= i, --n) {
			cout << j << ' ';
		}
		for (j = max(x, y) + i; n > 0; j += i, --n) {
			cout << j << ' ';
		}
		cout << endl;
	}
	return 0;
}