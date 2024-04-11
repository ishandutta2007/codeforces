#include <bits/stdc++.h>
using namespace std;
int a[300005], l[300005], r[300005];

main() {
	int t, n, i, j, c;
	char ch;
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 1; i <= n; ++i) {
			cin >> ch;
			if (ch == 'L')
				a[i] = 0;
			else
				a[i] = 1;
		}
		a[0] = 1;
		a[n + 1] = 0;
		for (i = 0; i <= n; ++i) {
			l[i] = 0;
			if (a[i] == 0) {
				if (i == 1 || a[i] == a[i - 1])
					l[i] = 1;
				else
					l[i] = l[i - 2] + 2;
			}
		}
		for (i = n; i >= 0; --i) {
			r[i] = 0;
			if (a[i + 1] == 1) {
				if (i == n - 1 || a[i + 1] == a[i + 2])
					r[i] = 1;
				else
					r[i] = r[i + 2] + 2;
			}
		}
		for (i = 0; i <= n; ++i) {
			cout << l[i] + r[i] + 1 << ' ';
		}
		cout << endl;
	}
}