#include <bits/stdc++.h>
using namespace std;

const int N = 100011;

struct Seg {
	double l, r;
	Seg operator +(Seg s) {
		Seg ret;
		ret.l = l * s.l / (1 - r * (1 - s.l));
		ret.r = s.r + r * s.l * (1 - s.r) / (1 - r * (1 - s.l));
		return ret;
	}
};

double p[N];
struct SegTree {
	Seg s[N * 4];
	#define m (l + r) / 2
	void init(int l, int r, int x = 1) {
		s[x] = {p[l], p[l]};
		if(l + 1 != r) {
			init(l, m, 2 * x);
			init(m, r, 2 * x + 1);
			s[x] = s[2 * x] + s[2 * x + 1];
		}
	}
	void change(int p, int l, int r, double c, int x = 1) {
		if(l + 1 == r)
			s[x] = {c, c};
		else {
			if(p < m)
				change(p, l, m, c, 2 * x);
			else
				change(p, m, r, c, 2 * x + 1);
			s[x] = s[2 * x] + s[2 * x + 1];
		}
	}
	Seg query(int ql, int qr, int l, int r, int x = 1) {
		if(ql == l && qr == r)
			return s[x];
		if(qr <= m)
			return query(ql, qr, l, m, 2 * x);
		if(ql >= m)
			return query(ql, qr, m, r, 2 * x + 1);
		return query(ql, m, l, m, 2 * x) +
			query(m, qr, m, r, 2 * x + 1);
	}
}st;

int main() {
	cout << fixed << setprecision(9);
	ios :: sync_with_stdio(false);
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; i ++) {
		int a, b; cin >> a >> b;
		p[i] = (double)a / b;
	}
	st.init(1, n + 1);
	while(q --) {
		int t; cin >> t;
		if(t == 1) {
			int i, a, b;
			cin >> i >> a >> b;
			st.change(i, 1, n + 1, (double)a / b);
		} else {
			int l, r;
			cin >> l >> r;
			cout << st.query(l, r + 1, 1, n + 1).l << '\n';
		}
	}
	return 0;
}