#include <iostream>
#include <algorithm>
#include <string>
#define m (s + e) / 2
using namespace std;
struct segnode {
	int s, e, minv, maxv, lazy;
	segnode *l, *r;
	segnode(int _s, int _e) {
		s = _s;
		e = _e;
		minv = maxv = lazy = 0;
		if (s != e) {
			l = new segnode(s, m);
			r = new segnode(m + 1, e);
		}
	}
	void propagate() {
		minv += lazy;
		maxv += lazy;
		if (s != e) {
			l -> lazy += lazy;
			r -> lazy += lazy;
		}
		lazy = 0;
	}
	void update(int a, int b, int d) {
		if (s == a && e == b) {
			lazy += d;
			return;
		} else if (a > m) r -> update(a, b, d);
		else if (b <= m) l -> update(a, b, d);
		else {
			l -> update(a, m, d);
			r -> update(m + 1, b, d);
		}
		l -> propagate();
		r -> propagate();
		minv = min(l -> minv, r -> minv);
		maxv = max(l -> maxv, r -> maxv);
	}
	int minq(int a, int b) {
		propagate();
		if (s == a && e == b) return minv;
		if (a > m) return r -> minq(a, b);
		if (b <= m) return l -> minq(a, b);
		return min(l -> minq(a, m), r -> minq(m + 1, b));
	}
	int maxq(int a, int b) {
		propagate();
		if (s == a && e == b) return maxv;
		if (a > m) return r -> maxq(a, b);
		if (b <= m) return l -> maxq(a, b);
		return max(l -> maxq(a, m), r -> maxq(m + 1, b));
	}
} *root;
int main() {
	int n, ptr = 0;
	cin >> n;
	string s;
	cin >> s;
	char reals[n];
	root = new segnode(0, n - 1);
	for (int i = 0; i < n; ++i) reals[i] = ' ';
	for (char c: s) {
		if (c == 'L') ptr = max(0, ptr - 1);
		else if (c == 'R') ++ptr;
		else {
			if (reals[ptr] == '(') root -> update(ptr, n - 1, -1);
			else if (reals[ptr] == ')') root -> update(ptr, n - 1, 1);
			if (c == '(') root -> update(ptr, n - 1, 1);
			else if (c == ')') root -> update(ptr, n - 1, -1);
			reals[ptr] = c;
		}
		if (root -> minq(0, n - 1) < 0 || root -> minq(n - 1, n - 1) != 0) printf("-1 ");
		else printf("%d ", root -> maxq(0, n - 1));
	}
	return 0;
}