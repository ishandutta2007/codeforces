#include <bits/stdc++.h>

using namespace std;

#define T tr[n]
#define LS tr[n<<1]
#define RS tr[n<<1|1]

const int N = 2e5 + 5;

struct tree {
	int l, r;
	int mn, mx;
	int d;

	tree() {
		l = r = mn = mx = d = 0;
	}
} tr[N << 2];

char s[N];

void build(int n, int l, int r) {
	T.l = l, T.r = r;
	if (l == r) {
		T.d = s[l] == '+' ? 1 : -1;
		T.mn = s[l] == '-' ? -1 : 0;
		T.mx = s[l] == '+' ? 1 : 0;
		return;
	}
	int m = (l + r) >> 1;
	build(n << 1, l, m);
	build(n << 1 | 1, m + 1, r);
	T.mn = min(LS.mn, RS.mn + LS.d);
	T.mx = max(LS.mx, RS.mx + LS.d);
	T.d = LS.d + RS.d;
}

tree query(int n, int l, int r) {
	if (T.l >= l && T.r <= r) return T;
	if (T.l > r || T.r < l) return {};
	tree ans;
	tree ll = query(n << 1, l, r);
	tree rr = query(n << 1 | 1, l, r);
	ans.mn = min(ll.mn, rr.mn + ll.d);
	ans.mx = max(ll.mx, rr.mx + ll.d);
	ans.d = ll.d + rr.d;
	return ans;
}

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	build(1, 1, n);
	while (m--) {
		int l, r;
		scanf("%d%d", &l, &r);
		tree ans;
		tree ll = query(1, 1, l - 1);
		tree rr = query(1, r + 1, n);
		ans.mn = min(ll.mn, rr.mn + ll.d);
		ans.mx = max(ll.mx, rr.mx + ll.d);
		printf("%d\n", ans.mx - ans.mn + 1);
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}