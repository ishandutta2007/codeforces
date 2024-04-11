#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, i, j, r[105][105];
	cin >> t;
	while (t--) {
		cin >> n;
		memset(r, 0, sizeof(r));
		for (i = 0; i < n; ++i) {
			for (j = i + 1; j < n; ++j) {
				if (n % 2) {
					if ((j + n - i) % n < 1.0 * n / 2)
						cout << 1 << ' ';
					else
						cout << -1 << ' ';
				} else {
					if ((j + n - i) % n < n / 2)
						cout << 1 << ' ';
					else if ((j + n - i) % n > n / 2)
						cout << -1 << ' ';
					else
						cout << 0 << ' ';
				}
			}
		}
		cout << endl;
	}
	return 0;
}