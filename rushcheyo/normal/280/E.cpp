#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int N = 6005;
pair<double, double> c[N * 2];
double ans, x[N], y[N];
int n, m, q, p, a, b;

int main() {
	scanf("%d%d%d%d", &n, &q, &a, &b);
	for (int i = 1; i <= n; i++) {
		scanf("%lf", x + i);
		if (i == 1)
			c[m++] = mp(1, 2 * (1 - x[i])), c[m++] = mp(q, 2 * (q - x[i]));
		else {
			for (int j = m - 1; j > p; j--)
				c[j + 2] = c[j];
			m += 2;
			c[++p] = mp(y[i - 1], 0), c[p + 1] = mp(y[i - 1], 0);
			for (int j = 0; j <= p; j++) c[j].fi += a;
			for (int j = p + 1; j < m; j++) c[j].fi += b;
			for (int j = 0; j < m; j++) c[j].se += 2 * (c[j].fi - x[i]);
		}
		if (c[0].se >= 0) p = -1, y[i] = c[0].fi;
		else {
			for (p = 0; p < m - 1; p++)
				if (c[p].se <= 0 && c[p + 1].se > 0) break;
			y[i] = c[p].fi - c[p].se *
				(c[p].fi - c[p + 1].fi) / (c[p].se - c[p + 1].se);
		}
	}
	y[n] = min(y[n], (double)q);
	for (int i = n - 1; i >= 1; i--) {
		if (y[i] > y[i + 1] - a) y[i] = y[i + 1] - a;
		if (y[i] < y[i + 1] - b) y[i] = y[i + 1] - b;
	}
	for (int i = 1; i <= n; i++) {
		printf("%.6f%c", y[i], " \n"[i == n]);
		ans += (y[i] - x[i]) * (y[i] - x[i]);
	}
	printf("%.6f\n", ans);
}