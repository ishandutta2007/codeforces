#include<bits/stdc++.h>
const int N = 200005;
using std::cin;
using std::cout;
using ll = long long;
int n, t;
int g[N], c[N];
ll d[N];
std::mt19937 gen(124124);
int ls[N], rs[N], p[N], cc;
ll add0[N], w0[N];
ll add1[N], w1[N];
inline void put0(int x, ll v) {
	if(x) w0[x] += v, add0[x] += v;
}
inline void put1(int x, ll v) {
	if(x) w1[x] += v, add1[x] += v;
}
inline void pushdown(int x) {
	put0(ls[x], add0[x]), put0(rs[x], add0[x]), add0[x] = 0;
	put1(ls[x], add1[x]), put1(rs[x], add1[x]), add1[x] = 0;
}
inline int merge(int x, int y) {
	if(!x || !y) return x | y;
	if(p[x] > p[y]) {
		pushdown(x);
		rs[x] = merge(rs[x], y);
		return x;
	} else {
		pushdown(y);
		ls[y] = merge(x, ls[y]);
		return y;
	}
}
inline void split(int root, ll w, int & x, int & y) {
	if(!root) x = y = 0;
	else {
		pushdown(root);
		if(w0[root] <= w) {
			split(rs[root], w, rs[root], y);
			x = root;
		} else {
			split(ls[root], w, x, ls[root]);
			y = root;
		}
	}
}
inline int build(int * l, int * r) {
	if(l + 1 == r) {
		w0[++cc] = *l;
		p[cc] = gen();
		return cc;
	}
	int * mid = l + (r - l) / 2;
	return merge(build(l, mid), build(mid, r));
}
inline ll getmin(int x) {
	ll res = w1[x];
	pushdown(x);
	if(ls[x]) res = std::min(res, getmin(ls[x]));
	if(rs[x]) res = std::min(res, getmin(rs[x]));
	return res;
}
inline ll getres(int x) {
	if(!x) return 1e18;
	pushdown(x);
	ll p = std::min(getres(ls[x]), getres(rs[x]));
	return std::min(p, w1[x] + (t * 2 - w0[x]) % t);
}
inline void debug(int x) {
	if(!x) return;
	pushdown(x);
	debug(ls[x]);
	cout << w0[x] << ' ';
	debug(rs[x]);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> t;
	std::vector<int> o;
	for(int i = 1;i <= n;++i) {
		cin >> g[i] >> c[i];
	}
	for(int i = 2;i <= n;++i) {
		cin >> d[i], d[i] += d[i - 1];
	}
	for(int i = 1;i <= n;++i) {
		ll p = (g[i] - 1 - (c[i] + d[i])) % t;
		p += p >> 63 & t;
		o.push_back(p);
	}
	sort(o.begin(), o.end()), o.erase(unique(o.begin(), o.end()), o.end());
	int root = build(o.data(), o.data() + o.size());
	for(int i = 1;i <= n;++i) {
		put0(root, (d[i] - d[i - 1]) % t);
		put1(root, d[i] - d[i - 1]);

		int A, B; split(root, t - 1, A, B);
		put0(B, -t);
		A = merge(B, A);
		put0(A, c[i]);
//		cout << "Debug 1 : "; debug(A); cout << '\n';
		int a0, a1, a2, a3;
		split(A, t - 1, a0, a2);
		split(a0, g[i] - 1, a0, a1);
		split(a2, g[i] + t - 1, a2, a3);
		A = merge(a0, a2);
//		cout << "Debug 2 : "; debug(A); cout << '\n';
		put0(A, -c[i]);
		if(a1 || a3) {
			ll r = std::min(getres(a1), getres(a3));
			int x = a1 ? a1 : a3;

			ls[x] = rs[x] = add0[x] = w0[x] = add1[x] = w1[x] = 0;
			p[x] = gen();
			w1[x] = r;
			w0[x] = (t - c[i]) % t;
			split(A, w0[x], a0, a1);
			A = merge(merge(a0, x), a1);
		}
		root = A;
	}
	cout << getmin(root) << '\n';
}