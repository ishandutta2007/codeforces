#include <bits/stdc++.h>
using namespace std;
long long a[100005], b[100005], c[100005], ring[100005], de[100005];

main() {
	long long t, n, i, j, dq, maxm;
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 0; i < n; ++i)
			cin >> c[i];
		for (i = 0; i < n; ++i)
			cin >> a[i];
		for (i = 0; i < n; ++i)
			cin >> b[i];
		for (i = 1; i < n; ++i) {
			de[i] = abs(a[i] - b[i]);
			ring[i] = de[i] + c[i] + 1;
		}
		dq = maxm = ring[1];
		for (i = 2; i < n; ++i) {
			if (de[i] == 0 || dq - de[i] < de[i])
				dq = ring[i];
			else
				dq = dq + ring[i] - 2 * de[i];
			if (dq > maxm)
				maxm = dq;
		}
		cout << maxm << endl;
	}
}