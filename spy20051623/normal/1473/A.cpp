#include <bits/stdc++.h>
using namespace std;

main() {
	int t, n, d, a[200];
	cin >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		sort(a, a + n);
		if (a[0] + a[1] <= d || a[n - 1] <= d)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}