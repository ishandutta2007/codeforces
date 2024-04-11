#include <bits/stdc++.h>

int z[1234567];

int p[42], q[42];
int const INF = 1 << 30;
int ans;

void go(int a, int b, long long h, long long w, int x, int cn, int got) {
//	printf("%d %d %lld %lld %d %d %d\n", a, b, h, w, x, cn, got);
	if (got >= ans) return;
	if (x == cn) {
		if (h >= a && w >= b) {
			ans = got;
		}
		return;
	}
	long long hh = h;
	for (int q1 = 0; q1 <= q[x] && (q1 == 0 || hh < (long long) p[x] * a); q1++) {
		long long ww = w;
		for (int q2 = 0; q2 + q1 <= q[x] && (q2 == 0 || ww < (long long) b * p[x]); q2++) {
			go(a, b, hh, ww, x + 1, cn, got + q1 + q2);
			ww *= p[x];
		}
		hh *= p[x];
	}
}

int solve(int a, int b, int h, int w, int n) {
	int cur = n;
	long long c = 1;
	while (cur > 0 && c < a) {
		c *= z[--cur];
	}
	c = 1;
	while (cur > 0 && c < b) {
		c *= z[--cur];
	}
	int cn = 0;
	int last = z[cur++];
	p[0] = last;
	q[0] = 1;
	++cn;
	while (cur < n) {
		if (z[cur] == last) {
			q[cn - 1]++;
		} else {
			q[cn] = 1;
			p[cn++] = z[cur];
			last = z[cur];
		}
		++cur;
	}
	ans = INF;
	go(a, b, h, w, 0, cn, 0);
	return ans;
}

int main() {
	int a, b, h, w, n;
	scanf("%d%d%d%d%d", &a, &b, &h, &w, &n);
	for (int i = 0; i < n; i++) scanf("%d", z + i);
	std::sort(z, z + n);
	int ans;
	ans = solve(a, b, h, w, n);
	ans = std::min(ans, solve(a, b, w, h, n));
	printf("%d\n", ans == INF ? -1 : ans);
}