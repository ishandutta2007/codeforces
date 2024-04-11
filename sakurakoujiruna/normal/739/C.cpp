#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Seg {
	int seg_len;
	ll l, r;
	int l_dec, l_inc;
	int r_dec, r_inc;
	int l_hill, r_hill;
	int max_hill;
	Seg operator +(Seg s) {
		Seg ret; ret.l = l; ret.r = s.r;
		ret.seg_len = seg_len + s.seg_len;

		ret.max_hill = max(max_hill, s.max_hill);
		if(r < s.l)
			ret.max_hill = max(ret.max_hill, r_inc + s.l_hill);
		if(r > s.l)
			ret.max_hill = max(ret.max_hill, r_hill + s.l_dec);

		if(r > s.l && l_hill == seg_len)
			ret.l_hill = l_hill + s.l_dec;
		else
			ret.l_hill = l_hill;
		if(r < s.l && l_inc == seg_len)
			ret.l_hill = max(ret.l_hill, l_inc + s.l_hill);

		if(r < s.l && s.r_hill == s.seg_len)
			ret.r_hill = r_inc + s.r_hill;
		else
			ret.r_hill = s.r_hill;
		if(r > s.l && s.r_dec == s.seg_len)
			ret.r_hill = max(ret.r_hill, r_hill + s.r_dec);

		if(r < s.l && l_inc == seg_len)
			ret.l_inc = l_inc + s.l_inc;
		else
			ret.l_inc = l_inc;

		if(r > s.l && l_dec == seg_len)
			ret.l_dec = l_dec + s.l_dec;
		else
			ret.l_dec = l_dec;

		if(r < s.l && s.r_inc == s.seg_len)
			ret.r_inc = r_inc + s.r_inc;
		else
			ret.r_inc = s.r_inc;

		if(r > s.l && s.r_dec == s.seg_len)
			ret.r_dec = r_dec + s.r_dec;
		else
			ret.r_dec = s.r_dec;

		ret.l_hill = max({ret.l_hill, ret.l_inc, ret.l_dec});
		ret.r_hill = max({ret.r_hill, ret.r_inc, ret.r_dec});

		ret.max_hill = max({ret.max_hill, ret.l_hill, ret.r_hill});
	
		return ret;
	}
};

const int N = 300011;

int a[N];

struct SegTree {
	Seg s[N * 4];
	ll lazy[N * 4];

	#define m (l + r) / 2

	void init(int l, int r, int x = 1) {
		if(l + 1 == r)
			s[x] = {1, a[l], a[l], 1, 1, 1, 1, 1, 1, 1};
		else {
			init(l, m, 2 * x);
			init(m, r, 2 * x + 1);
			s[x] = s[2 * x] + s[2 * x + 1];
		}
	}

	void push(int x) {
		s[x].l += lazy[x];
		s[x].r += lazy[x];
		if(s[x].seg_len != 1) {
			lazy[2 * x] += lazy[x];
			lazy[2 * x + 1] += lazy[x];
		}
		lazy[x] = 0;
	}

	void change(int l, int r, int ql, int qr, int c, int x = 1) {
		push(x);
		if(l == ql && r == qr) lazy[x] += c;
		else {
			if(qr <= m) change(l, m, ql, qr, c, 2 * x);
			else if(ql >= m) change(m, r, ql, qr, c, 2 * x + 1);
			else {
				change(l, m, ql, m, c, 2 * x);
				change(m, r, m, qr, c, 2 * x + 1);
			}
			push(2 * x); push(2 * x + 1);
			s[x] = s[2 * x] + s[2 * x + 1];
		}
	}

	Seg query() {
		push(1);
		return s[1];
	}

	#undef m
}st;

int main() {
	//ios :: sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 1; i <= n; i ++)
		scanf("%d", a + i);
	st.init(1, n + 1);
	//cout << st.query().max_hill << '\n';
	int m; cin >> m;
	while(m --) {
		int l, r, d;
		//cin >> l >> r >> d;
		scanf("%d%d%d", &l, &r, &d);
		st.change(1, n + 1, l, r + 1, d);
		printf("%d\n", st.query().max_hill);
	}
	return 0;
}