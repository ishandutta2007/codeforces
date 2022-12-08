#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, a[3], i, j, k, in, c, d;
	cin >> t;
	while (t--) {
		cin >> n;
		a[0] = a[1] = a[2] = 0;
		for (i = 0; i < n; ++i) {
			cin >> in;
			++a[in % 3];
		}
		c = d = 0;
		for (i = 0; i < 3; ++i)
			if (a[i] > n / 3)
				++c;
			else if (a[i] < n / 3)
				++d;
		if (!c && !d)
			cout << 0 << endl;
		else if (c > d) {
			for (i = 0; i < 3; ++i)
				if (a[i] < n / 3)
					break;
			k = 0;
			for (j = 0; j < 3; ++j) {
				if (i == j)
					continue;
				k += (i + 3 - j) % 3 * abs(a[j] - n / 3);
			}
			cout << k << endl;
		} else if (c < d) {
			for (i = 0; i < 3; ++i)
				if (a[i] > n / 3)
					break;
			k = 0;
			for (j = 0; j < 3; ++j) {
				if (i == j)
					continue;
				k += (j + 3 - i) % 3 * abs(n / 3 - a[j]);
			}
			cout << k << endl;
		} else {
			for (i = 0; i < 3; ++i)
				if (a[i] < n / 3)
					break;
			for (j = 0; j < 3; ++j)
				if (a[j] > n / 3)
					break;
			k = (i + 3 - j) % 3 * abs(n / 3 - a[i]);
			cout << k << endl;
		}
	}
	return 0;
}