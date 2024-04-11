#include <bits/stdc++.h>
using namespace std;

const int H = 32, Q = 100010;

struct node{
	node *l, *r; int val;
} root[H*Q], *nodes = root + 1;

int q, h, v, e;
char s[100];

int main() {
	for (scanf("%d %d", &h, &q); q --; ) {
		scanf("%s", s);
		if (s[0] == 'a') {
			scanf("%d %d", &v, &e);
			node *u = root; u->val += e;
			for (int t = 31 - __builtin_clz(v); t --; ) {
				if (v>>t&1) { if (!u->l) u->l = nodes ++; u = u->l; }
				else { if (!u->r) u->r = nodes ++; u = u->r; }
				u->val += e;
			}
		}
		else {
			double ans = 0, tmp = 1;
			int mx = 0;
			for (node *u = root; u; ) {
				int tmpl = (u->l) ? (u->l->val) : 0;
				int tmpr = (u->r) ? (u->r->val) : 0;
				int now = u->val - tmpl - tmpr;
				tmp /= 2;
				if (tmpl > tmpr) {
					u = u->l;
					mx = max(mx, tmpr + now);
					ans += max(mx, tmpl + now) * tmp;
				}
				else {
					u = u->r;
					mx = max(mx, tmpl + now);
					ans += max(mx, tmpr + now) * tmp;
				}
			} ans += tmp * mx;
			printf("%lf\n", ans);
		}
	}
}