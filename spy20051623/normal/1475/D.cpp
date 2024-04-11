#include <bits/stdc++.h>
using namespace std;

struct dt {
	int a, b;
} d[200005];

int cmp(dt x, dt y) {
	if (x.a * 2 / x.b == y.a * 2 / y.b)
		return x.b > y.b;
	else
		return x.a * 2 / x.b > y.a * 2 / y.b;
}

main() {
	int t, n, m, i, j, p, q, sum;
	cin >> t;
	while (t--) {
		memset(d, 0, sizeof(d));
		cin >> n >> m;
		for (i = 0; i < n; ++i) {
			cin >> d[i].a;
		}
		for (i = 0; i < n; ++i) {
			cin >> d[i].b;
		}
		sort(d, d + n, cmp);
		i = 0;
		q = -1;
		while (m > d[i].a) {
			m -= d[i].a;
			if (d[i].b == 1)
				q = i;
			++i;
			if (i == n)
				break;
		}
		if (i == n) {
			cout << "-1" << endl;
			continue;
		} else {
			p = 1;
			if (d[i].b == 2) {
				for (p = i + 1; p < n; ++p) {
					if (d[p].b == 1 && d[p].a >= m)
						break;
				}
				if (p >= n) {
					if (q != -1 && m + d[q].a <= d[i].a)
						p = 1;
					else
						p = 2;
				} else
					p = 1;
			}
			sum = 0;
			for (j = 0; j < i; ++j) {
				sum += d[j].b;
			}
			sum += p;
			cout << sum << endl;
		}
	}
}