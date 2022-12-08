#include <bits/stdc++.h>
using namespace std;

main() {
	int t, n, a[1000], b[1000], i, j;
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 0; i < n; ++i) {
			cin >> b[i];
		}
		i = 0;
		j = n - 1;
		while (i < j) {
			a[2 * i] = b[i];
			a[2 * i + 1] = b[j];
			++i;
			--j;
		}
		if (i == j) {
			a[2 * i] = b[i];
		}
		for (i = 0; i < n; ++i) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}