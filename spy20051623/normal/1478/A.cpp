#include <bits/stdc++.h>
using namespace std;

main() {
	int t, a[105], n, i, p, maxm;
	cin >> t;
	while (t--) {
		cin >> n;
		memset(a, 0, sizeof(a));
		for (i = 0; i < n; ++i) {
			cin >> p;
			++a[p];
		}
		maxm = 0;
		for (i = 0; i <= n; ++i) {
			if (a[i] > maxm)
				maxm = a[i];
		}
		cout << maxm << endl;
	}
}