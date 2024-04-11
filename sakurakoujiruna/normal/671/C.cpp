#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 11;
using ll = long long;

struct SegTree {
	bool leaf[N * 4];
	ll sum[N * 4];
	int lazy[N * 4];
	int f[N * 4], g[N * 4], f_cnt[N * 4];
	#define m ((l + r) / 2)
	void init(int l, int r, int x = 1) {
		sum[x] = lazy[x] = f[x] = 0;
		g[x] = -1; f_cnt[x] = r - l;
		if(l + 1 != r) {
			init(l, m, 2 * x);
			init(m, r, 2 * x + 1);
		} else
			leaf[x] = true;
	}
	void maintain(int x) {
		if(f[2 * x] == f[2 * x + 1]) {
			f[x] = f[2 * x];
			g[x] = (g[2 * x] != -1 ? g[2 * x + 1] != -1 ?
				min(g[2 * x], g[2 * x + 1]) : g[2 * x] : g[2 * x + 1]);
			f_cnt[x] = f_cnt[2 * x] + f_cnt[2 * x + 1];
		} else {
			f[x] = min(f[2 * x], f[2 * x + 1]);
			f_cnt[x] = (f[x] == f[2 * x] ? f_cnt[2 * x] : f_cnt[2 * x + 1]);
			if(f[x] == f[2 * x]) {
				if(g[2 * x] == -1) g[x] = f[2 * x + 1];
				else g[x] = min(g[2 * x], f[2 * x + 1]);
			} else {
				if(g[2 * x + 1] == -1) g[x] = f[2 * x];
				else g[x] = min(g[2 * x + 1], f[2 * x]);
			}
		}
		sum[x] = sum[2 * x] + sum[2 * x + 1];
	}
	void push(int x) {
		if(!lazy[x]) return;
		if(leaf[x]) {
			f[x] = max(f[x], lazy[x]); f_cnt[x] = 1;
			g[x] = -1; lazy[x] = 0; sum[x] = f[x];
			return;
		}
		if(g[x] == -1 || lazy[x] < g[x]) {
			if(lazy[x] > f[x]) {
				sum[x] += ll(lazy[x] - f[x]) * f_cnt[x];
				f[x] = lazy[x];
			}
			lazy[2 * x] = max(lazy[2 * x], lazy[x]);
			lazy[2 * x + 1] = max(lazy[2 * x + 1], lazy[x]);
			lazy[x] = 0;
		} else {
			lazy[2 * x] = max(lazy[2 * x], lazy[x]);
			lazy[2 * x + 1] = max(lazy[2 * x + 1], lazy[x]);
			lazy[x] = 0;
			push(2 * x); push(2 * x + 1);
			maintain(x);
		}
	}
	void change(int l, int r, int ql, int qr, int c, int x = 1) {
		push(x);
		if(l == ql && r == qr) lazy[x] = c;
		else {
			if(qr <= m) change(l, m, ql, qr, c, 2 * x);
			else if(ql >= m) change(m, r, ql, qr, c, 2 * x + 1);
			else {
				change(l, m, ql, m, c, 2 * x);
				change(m, r, m, qr, c, 2 * x + 1);
			}
			push(2 * x); push(2 * x + 1);
			maintain(x);
		}
	}
	ll query(int l, int r, int ql, int qr, int x = 1) {
		push(x);
		if(l == ql && r == qr) return sum[x];
		if(qr <= m) return query(l, m, ql, qr, 2 * x);
		if(ql >= m) return query(m, r, ql, qr, 2 * x + 1);
		return query(l, m, ql, m, 2 * x) + query(m, r, m, qr, 2 * x + 1);
	}
	#undef m
}st;

int a[N], pos[N];
struct Eve {
	int l, r, v;
	bool operator <(Eve e) const {
		return l < e.l;
	}
};

//int brute[N];

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		pos[a[i]] = i;
	}

	vector <Eve> eves;
	for(int i = 1; i < N; i ++) {
		vector <int> v;
		for(int j = i; j < N; j += i)
			if(pos[j]) v.push_back(pos[j]);
		int m = v.size();
		if(m >= 2) {
			sort(v.begin(), v.end());
			eves.push_back({1, v[m - 2] - 1, i});
			eves.push_back({v[0] + 1, v[m - 1] - 1, i});
			eves.push_back({v[1] + 1, n, i});
		}
	}
	sort(eves.begin(), eves.end());
	reverse(eves.begin(), eves.end());
	ll ans = 0; st.init(1, n + 1); ll ans2 = 0;
	for(int i = 1; i <= n; i ++) {
		while(eves.size() && eves.back().l == i) {
			Eve e = eves.back(); eves.pop_back();
			if(e.l <= e.r) {
				st.change(1, n + 1, e.l, e.r + 1, e.v);
				/*
				for(int j = e.l; j <= e.r; j ++)
					brute[j] = max(brute[j], e.v);
					*/
			}
		}
		ans += st.query(1, n + 1, i, n + 1);
		/*
		for(int j = i; j <= n; j ++)
			ans += st.query(1, n + 1, j, j + 1);
		for(int j = i; j <= n; j ++)
			ans2 += brute[j];
		cout << ans << ' ' << ans2 << '\n';
		*/
	}
	cout << ans << '\n';

	return 0;
}