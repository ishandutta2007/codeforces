#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxN = 100001;
int a[maxN], b[maxN], n, m, t;
int c[maxN], visited[maxN];

int compress(int b[], int n) {
	for (int i = 0; i < n; ++i) {
		a[i] = b[i];
	}
	sort(a, a + n);
	int m = unique(a, a + n) - a;
	for (int i = 0; i < n; ++i) {
		b[i] = (lower_bound(a, a + m, b[i]) - a) + 1;
	}
	return m;
}

int main() {
	int tests = 0;
	scanf("%d%d%d%d", &tests, &n, &m, &t);
	for (int test = 0; test < tests; ++test) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", &b[i]);
		}
		int s = compress(b, n);
		if (t >= s) {
			printf("%d\n", s);
			continue;
		}
		for (int i = 1; i <= s; ++i) {
			c[i] = visited[i] = 0;
		}

		int res = 0;
		for (int j = 0; j < t && res != s; ++j) {
			for (int i = 0; i < n && res != s; ++i) {
				int d = c[b[i]] + 1;
				if (!visited[b[i]]) {
					for (int k = b[i] + 1; k <= s; ++k) {
						if (c[k] < d) {
							c[k] = d;
							visited[k] = 0;
						} else {
							break;
						}
					}
					visited[b[i]] = 1;
				}
				res = max(res, d);
			}
		}

		printf("%d\n", res);
	}
	return 0;
}