#include <bits/stdc++.h>
using namespace std;

main() {
	int t, n, i, j, tmp, a[3005], sum;
	cin >> t;
	while (t--) {
		cin >> n;
		sum = 0;
		for (i = 0; i < n; ++i) {
			cin >> a[i];
			sum += a[i];
		}
		for (i = 1; i <= sum; ++i) {
			if (sum % i)
				continue;
			tmp = 0;
			for (j = 0; j <= n - 1; ++j) {
				tmp += a[j];
				if (tmp == i)
					tmp = 0;
				if (tmp > i)
					break;
			}
			if (tmp == 0) {
				cout << n - sum / i << endl;
				break;
			}
		}
	}
}