#include <bits/stdc++.h>
using namespace std;
int a[100005];

struct dt {
	int r;
	double p;
} d[100005];

int cmp(dt x, dt y) {
	return x.r > y.r;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, m, i, j, k;
	double p;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		for (i = 0; i < m; ++i) {
			cin >> d[i].r >> d[i].p;
		}
		sort(d, d + m, cmp);
		for (k = n; k; --k) {
			if (a[k] != k)
				break;
		}
		if (!k)
			cout << fixed << setprecision(9) << 1.0 << endl;
		else {
			p = 1;
			for (i = 0; i < m; ++i) {
				if (d[i].r >= k)
					p *= 1 - d[i].p;
				else
					break;
			}
			cout << fixed << setprecision(9) << 1 - p << endl;
		}
	}
	return 0;
}