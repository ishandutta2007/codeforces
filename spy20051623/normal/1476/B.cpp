#include <bits/stdc++.h>
using namespace std;

main() {
	long long t, i, j, n, k, p[105], sum[105], inc[105], x, s;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		memset(sum, 0, sizeof(sum));
		memset(inc, 0, sizeof(inc));
		for (i = 0; i < n; ++i) {
			cin >> p[i];
		}
		sum[0] = p[0];
		for (i = 1; i < n; ++i) {
			sum[i] = sum[i - 1] + p[i];
		}
		for (i = n - 1; i > 0; --i) {
			if (100 * p[i] % k)
				x = 100 * p[i] / k + 1;
			else
				x = 100 * p[i] / k;
			if (x <= sum[i - 1])
				inc[i] = 0;
			else {
				inc[i] = x - sum[i - 1];
				for (j = 0; j <= i; ++j)
					sum[j] += inc[i];
			}
		}
		s = 0;
		for (i = 1; i < n; ++i)
			s += inc[i];
		cout << s << endl;
	}
}