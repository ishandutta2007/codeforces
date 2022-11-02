#include <cstdio>
#include <algorithm>

int const N = 1234567;

int b[N], p[N], id1[N], id2[N], m1[N], m2[N];

int main() {
	int n, c, d;
	scanf("%d%d%d", &n, &c, &d);
	int c1 = 0;
	int c2 = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", b + i, p + i);
		int e = getchar();
		while (e <= 32) e = getchar();
		if (e == 'C') {
			if (p[i] <= c) {
  			id1[c1++] = i;
  		}
		} else {
			if (p[i] <= d) {
				id2[c2++] = i;
			}
		}
	}
	std::sort(id1, id1 + c1, [](int i, int j) {
		return p[i] < p[j];
	});
	std::sort(id2, id2 + c2, [](int i, int j) {
		return p[i] < p[j];
	});
	for (int i = 0; i < c1; i++) {
		m1[i] = b[id1[i]];
		if (i > 0) m1[i] = std::max(m1[i], m1[i - 1]);
	}
	for (int i = 0; i < c2; i++) {
		m2[i] = b[id2[i]];
		if (i > 0) m2[i] = std::max(m2[i], m2[i - 1]);
	}
	int ans = 0;
	if (c1 > 0 && c2 > 0) {
		ans = m1[c1 - 1] + m2[c2 - 1];
	}
	for (int i = 0; i < c1; i++) {
		int l = -1;
		int r = c1;
		while (l < r - 1) {
			int mid = (l + r) >> 1;
			if (p[id1[mid]] > c - p[id1[i]]) {
				r = mid;
			} else {
				l = mid;
			}
		}
		l = std::min(l, i - 1);
		if (l >= 0) {
			ans = std::max(ans, b[id1[i]] + m1[l]);
		}
	}
	for (int i = 0; i < c2; i++) {
		int l = -1;
		int r = c2;
		while (l < r - 1) {
			int mid = (l + r) >> 1;
			if (p[id2[mid]] > d - p[id2[i]]) {
				r = mid;
			} else {
				l = mid;
			}
		}
		l = std::min(l, i - 1);
		if (l >= 0) {
			ans = std::max(ans, b[id2[i]] + m2[l]);
		}
	}
	printf("%d\n", ans);
}