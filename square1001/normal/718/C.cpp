#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
const int mod = 1000000007;
const long long modsqr = 1000000014000000049;
using namespace std;
int n, q, tp[100009], l[100009], r[100009], x[100009], a[100009][2], z, v[1009], s[1009][2], mul[1009][2];
int main() {
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &z); z--; a[i][0] = 1;
		int c0 = 1, c1 = 1;
		while (z) {
			if (z & 1) {
				int b0 = (1LL * a[i][0] * c0 + 1LL * a[i][1] * c1) % mod;
				int b1 = (1LL * a[i][0] * c1 + 1LL * a[i][1] * c0 - 1LL * a[i][1] * c1 + modsqr) % mod;
				a[i][0] = b0; a[i][1] = b1;
			}
			int a0 = (1LL * c0 * c0 + 1LL * c1 * c1) % mod;
			int a1 = (2LL * c0 * c1 - 1LL * c1 * c1 + modsqr) % mod;
			c0 = a0; c1 = a1;
			z >>= 1;
		}
	}
	for (int i = 0; i < q; i++) {
		scanf("%d %d %d", &tp[i], &l[i], &r[i]); l[i]--;
		if (tp[i] == 1) scanf("%d", &x[i]);
	}
	int b = sqrt(q);
	for (int i = 0; i < b; i++) {
		int lb = i * q / b, rb = (i + 1) * q / b, cnt = 0;
		for (int j = lb; j < rb; j++) {
			v[cnt++] = l[j];
			v[cnt++] = r[j];
		}
		sort(v, v + cnt);
		cnt = unique(v, v + cnt) - v;
		for (int j = 0; j < cnt - 1; j++) {
			s[j][0] = s[j][1] = 0;
			for (int k = v[j]; k < v[j + 1]; k++) {
				s[j][0] += a[k][0]; if (s[j][0] >= mod) s[j][0] -= mod;
				s[j][1] += a[k][1]; if (s[j][1] >= mod) s[j][1] -= mod;
			}
			mul[j][0] = 1; mul[j][1] = 0;
		}
		for (int j = lb; j < rb; j++) {
			int pl = lower_bound(v, v + cnt, l[j]) - v;
			int pr = lower_bound(v, v + cnt, r[j]) - v;
			if (tp[j] == 1) {
				int d0 = 1, d1 = 0, c0 = 1, c1 = 1;
				while (x[j]) {
					if (x[j] & 1) {
						int b0 = (1LL * d0 * c0 + 1LL * d1 * c1) % mod;
						int b1 = (1LL * d0 * c1 + 1LL * d1 * c0 - 1LL * d1 * c1 + modsqr) % mod;
						d0 = b0; d1 = b1;
					}
					int a0 = (1LL * c0 * c0 + 1LL * c1 * c1) % mod;
					int a1 = (2LL * c0 * c1 - 1LL * c1 * c1 + modsqr) % mod;
					c0 = a0; c1 = a1;
					x[j] >>= 1;
				}
				for (int k = pl; k < pr; k++) {
					int a0 = (1LL * mul[k][0] * d0 + 1LL * mul[k][1] * d1) % mod;
					int a1 = (1LL * mul[k][0] * d1 + 1LL * mul[k][1] * d0 - 1LL * mul[k][1] * d1 + modsqr) % mod;
					mul[k][0] = a0; mul[k][1] = a1;
				}
			}
			else {
				int ret = 0;
				for (int k = pl; k < pr; k++) ret = (ret + 1LL * mul[k][0] * s[k][0] + 1LL * mul[k][1] * s[k][1]) % mod;
				printf("%d\n", ret);
			}
		}
		for (int j = 0; j < cnt - 1; j++) {
			for (int k = v[j]; k < v[j + 1]; k++) {
				int a0 = (1LL * a[k][0] * mul[j][0] + 1LL * a[k][1] * mul[j][1]) % mod;
				int a1 = (1LL * a[k][0] * mul[j][1] + 1LL * a[k][1] * mul[j][0] - 1LL * a[k][1] * mul[j][1] + modsqr) % mod;
				a[k][0] = a0; a[k][1] = a1;
			}
		}
	}
	return 0;
}