#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else 
#define dump(x) true
#endif

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

const int SZ = 1 << 19;

template<class T>
struct segtree {
	vector<T> dat;

	const T id = 0;

	void init() {
		dat.resize(SZ * 2);
		rep(i, SZ * 2) dat[i] = id;
	}

	void update(int pos, T x) {
		pos += SZ - 1;
		dat[pos] = x;

		while (pos > 0) {
			pos = (pos - 1) / 2;
			dat[pos] = __gcd(dat[pos * 2 + 1], dat[pos * 2 + 2]);
		}
	}

	T get(int a, int b, int k = 0, int l = 0, int r = SZ) {
		if (b <= l || r <= a) return id;
		if (a <= l && r <= b) return dat[k];
		return __gcd(get(a, b, k * 2 + 1, l, (l + r) / 2), get(a, b, k * 2 + 2, (l + r) / 2, r));
	}

	int ask(int a, int b, int x, int k = 0, int l = 0, int r = SZ) {
		if (b <= l || r <= a) return -1;
		if (r - l == 1) {
			if (dat[k] % x == 0) {
				return -1;
			} else {
				return l;
			}
		}

		int lv = get(a, b, k * 2 + 1, l, (l + r) / 2);
		int rv = get(a, b, k * 2 + 2, (l + r) / 2, r);

		if (lv % x == 0 && rv % x == 0) {
			return -1;
		}

		if (lv % x == 0) {
			return ask(a, b, x, k * 2 + 2, (l + r) / 2, r);
		} else if (rv % x == 0) {
			return ask(a, b, x, k * 2 + 1, l, (l + r) / 2);
		} else {
			return -2;
		}
	}
};

int main() {
	int n; scanf("%d", &n);

	segtree<int> seg;
	seg.init();

	V<int> a(n);
	rep(i, n) {
		scanf("%d", &a[i]);
	}

	rep(i, n) {
		seg.dat[i + SZ - 1] = a[i];
	}
	for (int i = SZ - 2; i >= 0; --i) {
		seg.dat[i] = __gcd(seg.dat[i * 2 + 1], seg.dat[i * 2 + 2]);
	}

	int q; scanf("%d", &q);
	while (q--) {
		int tp; scanf("%d", &tp);
		if (tp == 1) {
			int l, r, x;
			scanf("%d %d %d", &l, &r, &x);
			--l;

			auto res = seg.ask(l, r, x);

			if (res != -2) {
				puts("YES");
			} else {
				puts("NO");
			}
		} else {
			int p, y; scanf("%d %d", &p, &y);
			--p;
			a[p] = y;
			seg.update(p, y);
		}
	}


	return 0;
}