#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
#define gc (c = getchar())
char readc() {
	char c;
	while (isspace(gc))
		;
	return c;
}
int read() {
	char c;
	while (gc < '-')
		;
	if (c == '-') {
		int x = gc - '0';
		while (gc >= '0') x = x * 10 + c - '0';
		return -x;
	}
	int x = c - '0';
	while (gc >= '0') x = x * 10 + c - '0';
	return x;
}
namespace fenwick_helper {

	template<class T>
	T plus(const T& x, const T& y) {
		return x + y;
	}
	template<class T>
	T multiplies(const T& x, const T& y) {
		return x * y;
	}
	template<class T>
	T bit_xor(const T& x, const T& y) {
		return x ^ y;
	}
	template<class T>
	T min(const T& x, const T& y) {
		return x < y ? x : y;
	}
	template<class T>
	T max(const T& x, const T& y) {
		return x < y ? y : x;
	}
	template<class T>
	T e() {
		return T();
	}

}
template<class T, T (*op)(const T&, const T&) = fenwick_helper::plus<T>, T (*e)() = fenwick_helper::e<T> >
struct fenwick {
	int n;
	vector<T> t;
	fenwick(): n(0), t(0) {}
	fenwick(int n): n(n), t(n, e()) {}
	void assign(int n_) { n = n_, t.assign(n_, e()); }
	void add(int x, const T& y) { // 0<=x
		++x;
		for (int i = x; i <= n; i += i & -i) t[i - 1] = op(t[i - 1], y);
	}
	void add(int l, int r, const T& x) { // [l,r]
		add(l, x);
		add(r + 1, -x);
	}
	T query(int x) { // x<n
		++x;
		T y = e();
		for (int i = x; i > 0; i &= i - 1) y = op(y, t[i - 1]);
		return y;
	}
	T query(int l, int r) {					// [l,r]
		return op(query(r), -query(l - 1)); // operator-()
	}
	void add2(int x, const T& y) { // x<n
		++x;
		for (int i = x; i > 0; i &= i - 1) t[i - 1] = op(t[i - 1], y);
	}
	T query2(int x) { // 0<=x
		++x;
		T y = e();
		for (int i = x; i <= n; i += i & -i) y = op(y, t[i - 1]);
		return y;
	}
};
using LL = long long;
const int N = 1000005;
int n, Q;
LL tag[N];
struct node {
	int l, r, c;
	node(int l, int r, int c): l(l), r(r), c(c) {}
	bool operator<(const node& rhs) const {
		return r < rhs.r;
	}
};
set<node> S;
int ask_col(int i) {
	return S.lower_bound(node(0, i, 0))->c;
}
set<node>::iterator split(int r) { // <r >=r
	if (r == n + 1) return S.end();
	auto it = S.lower_bound(node(0, r, 0));
	if (it->l == r) return it;
	auto cur = *it;
	S.erase(it);
	S.insert(node(cur.l, r - 1, cur.c));
	return S.insert(node(r, cur.r, cur.c)).first;
}
int main() {
#ifdef local
	freopen("a.in", "r", stdin);
#endif
	n = read(), Q = read();
	fenwick<LL> tr(n + 1);
	S.insert(node(1, n, 1));
	rep(_, 1, Q) {
		static char opt[10];
		scanf("%s", opt);
		if (opt[0] == 'C') {
			int l = read(), r = read(), c = read();
			auto en = split(r + 1);
			auto be = split(l);
			for (auto it = be; it != en; ++it) {
				tr.add(it->l, it->r, +tag[it->c] - tag[c]);
			}
			S.erase(be, en);
			S.insert(node(l, r, c));
		} else if (opt[0] == 'A') {
			int c = read(), x = read();
			tag[c] += x;
		} else {
			int i = read();
			printf("%lld\n", tr.query(i) + tag[ask_col(i)]);
		}
	}
	return 0;
}