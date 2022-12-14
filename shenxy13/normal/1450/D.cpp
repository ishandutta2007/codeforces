#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, a[300000], ans[300000];
struct seg {
	int s, e, m, v;
	seg *l, *r;
	seg(int _s, int _e) {
		s = _s, e = _e, m = (s + e) / 2;
		if (s != e) {
			l = new seg(s, m);
			r = new seg(m + 1, e);
			v = min(l -> v, r -> v);
		} else v = a[s];
	}
	int query(int a, int b) {
		if (s == a && e == b) return v;
		if (a > m) return r -> query(a, b);
		if (b <= m) return l -> query(a, b);
		return min(l -> query(a, m), r -> query(m + 1, b));
	}
} *root;
void solve(int l, int r) {
	if (l > r) return;
	if (root -> query(l, r) != n - (r - l)) return;
	ans[r - l] = 1;
	if (a[l] == n - (r - l)) solve(l + 1, r);
	else if (a[r] == n - (r - l)) solve(l, r - 1);
}
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		fill_n(ans, n, 0);
		root = new seg(0, n - 1);
		solve(0, n - 1);
		sort(a, a + n);
		ans[0] = true;
		for (int i = 0; i < n; ++i) {
			if (a[i] != i + 1) ans[0] = false;
		}
		for (int i = 0; i < n; ++i) printf("%d", ans[i]);
		printf("\n");
	}
	return 0;
}