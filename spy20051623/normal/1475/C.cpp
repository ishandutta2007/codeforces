#include <bits/stdc++.h>
using namespace std;
int sa[200005], sb[200005];

long long c(long long n) {
	return n * (n - 1) / 2;
}

main() {
	long long t, p, i, cnt, a, b, k;
	cin >> t;
	while (t--) {
		memset(sa, 0, sizeof(sa));
		memset(sb, 0, sizeof(sb));
		cin >> a >> b >> k;
		for (i = 0; i < k; ++i) {
			cin >> p;
			++sa[p];
		}
		for (i = 0; i < k; ++i) {
			cin >> p;
			++sb[p];
		}
		cnt = c(k);
		for (i = 0; i <= a; ++i) {
			if (sa[i])
				cnt -= c(sa[i]);
		}
		for (i = 0; i <= b; ++i) {
			if (sb[i])
				cnt -= c(sb[i]);
		}
		cout << cnt << endl;
	}
}