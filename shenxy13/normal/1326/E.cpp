#include <cstdio>
#include <algorithm>
using namespace std;
struct seg {
	int s, e, m, v, lazy;
	seg *l, *r;
	seg(int _s, int _e) {
		s = _s, e = _e, m = (s + e) / 2;
		v = lazy = 0;
		if (s != e) {
			l = new seg(s, m);
			r = new seg(m + 1, e);
		}
	}
	int value() {
		if (lazy != 0) {
			v += lazy;
			if (s != e) {
				l -> lazy += lazy;
				r -> lazy += lazy;
			}
			lazy = 0;
		}
		return v;
	}
	void up(int a, int b, int dv){
		if (s == a && e == b) {
			lazy += dv;
			return;
		} else if (a > m) r -> up(a, b, dv);
		else if (b <= m) l -> up(a, b, dv);
		else l -> up(a, m, dv), r -> up(m + 1, b, dv);
		v = min(l -> value(), r -> value());
	}
	int query(int a, int b) {
		value();
		if (s == a && e == b) return v;
		if (a > m) return r -> query(a, b);
		if (b <= m) return l -> query(a, b);
		return min(l -> query(a, m), r -> query(m + 1, b));
	}
} *root;
int main() {
	int n;
	scanf("%d", &n);
	int pos[n + 1], p, q[n + 1];
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p);
		pos[p] = i;
	}
	for (int i = 1; i <= n; ++i) scanf("%d", &q[i]);
	int ans[n], cur = n;
	ans[0] = n;
	root = new seg(1, n);
	for (int i = 1; i < n; ++i) {
		root -> up(1, q[i], 1);
		while (root -> query(1, pos[cur]) != 0) root -> up(1, pos[cur--], -1);
		ans[i] = cur;
	}
	for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
	return 0;
}