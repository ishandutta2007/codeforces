#include <bits/stdc++.h>
using namespace std;

#define N 4010
const int inf = 1e9 + 10;

int n, k, p, a[N], b[N], st, en;

int dist(int x, int y) {
	return abs(x - y);
}

bool test(int x) {
	int po = 0;
	for (int i = 1; i <= n; i ++) {
		po ++;
		if (po > k) return false;
		for (po; po <= k; po ++) {
			if (dist(b[po], a[i]) + dist(b[po], p) <= x) break;
		}
		if (po > k) return false;
	}
	return true;
}

int main() {
	scanf("%d%d%d", &n, &k, &p);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= k; i ++) scanf("%d", &b[i]);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + k + 1);
	en = 2 * inf;
	st = -1;
	while (en - st > 1) {
		int mid = st + (en - st >> 1);
		if (test(mid)) en = mid;
		else st = mid;
	}
	printf("%d\n", en);
}