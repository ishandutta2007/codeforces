#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 11;
const int C = 48;
const int Mod = 95542721;
using ll = long long;

struct Val {
	int r;
	int num[C];
	void rot(int t) { r += t; }
	int& operator [](int i) {
		return num[(i + r) % C];
	}
	Val operator +(Val v) {
		Val r; r.r = 0;
		for(int i = 0; i < C; i ++) {
			r[i] = (*this)[i] + v[i];
			if(r[i] >= Mod) r[i] -= Mod;
		}
		return r;
	}
};

ll a[N];
struct SegTree {
	int l[N * 4], r[N * 4];
	int flag[N * 4];
	Val v[N * 4];
	void push(int x) {
		v[x].rot(flag[x]);
		if(l[x] + 1 != r[x]) {
			flag[2 * x] += flag[x];
			flag[2 * x + 1] += flag[x];
		}
		flag[x] = 0;
	}
	void init(int ql, int qr, int x = 1) {
		l[x] = ql; r[x] = qr; flag[x] = 0;
		if(l[x] + 1 == r[x]) {
			v[x].r = 0;
			v[x][0] = a[ql] % Mod;
			for(int i = 1; i < C; i ++) {
				ll t = v[x][i - 1];
				v[x][i] = t * t % Mod * t % Mod;
			}
		} else {
			int m = (l[x] + r[x]) / 2;
			init(ql, m, 2 * x);
			init(m, qr, 2 * x + 1);
			v[x] = v[2 * x] + v[2 * x + 1];
		}
	}
	void change(int ql, int qr, int x = 1) {
		push(x);
		if(ql == l[x] && qr == r[x]) {
			flag[x] ++; push(x); return;
		}
		int m = (l[x] + r[x]) / 2;
		if(qr <= m) {
			change(ql, qr, 2 * x);
			push(2 * x + 1);
		} else if(ql >= m) {
			push(2 * x);
			change(ql, qr, 2 * x + 1);
		} else {
			change(ql, m, 2 * x);
			change(m, qr, 2 * x + 1);
		}
		v[x] = v[2 * x] + v[2 * x + 1];
	}
	int query(int ql, int qr, int x = 1) {
		push(x);
		if(ql == l[x] && qr == r[x])
			return v[x][0];
		int m = (l[x] + r[x]) / 2;
		if(qr <= m) return query(ql, qr, 2 * x);
		else if(ql >= m) return query(ql, qr, 2 * x + 1);
		int ret = query(ql, m, 2 * x) + query(m, qr, 2 * x + 1);
		return ret - (ret >= Mod ? Mod : 0);
	}
}st;

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	st.init(1, n + 1);

	int m; cin >> m;
	while(m --) {
		int t, l, r;
		cin >> t >> l >> r;
		if(t == 1)
			cout << st.query(l, r + 1) << '\n';
		else
			st.change(l, r + 1);
	}
	return 0;
}