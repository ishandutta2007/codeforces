#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
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

template <unsigned int MOD>
struct ModInt {
	using uint = unsigned int;
	using ull = unsigned long long;
	using M = ModInt;

	uint v;

	ModInt(ll _v = 0) { set_norm(_v % MOD + MOD); }
	M& set_norm(uint _v) { //[0, MOD * 2)->[0, MOD)
		v = (_v < MOD) ? _v : _v - MOD;
		return *this;
	}

	explicit operator bool() const { return v != 0; }
	M operator+(const M& a) const { return M().set_norm(v + a.v); }
	M operator-(const M& a) const { return M().set_norm(v + MOD - a.v); }
	M operator*(const M& a) const { return M().set_norm(ull(v) * a.v % MOD); }
	M operator/(const M& a) const { return *this * a.inv(); }
	M& operator+=(const M& a) { return *this = *this + a; }
	M& operator-=(const M& a) { return *this = *this - a; }
	M& operator*=(const M& a) { return *this = *this * a; }
	M& operator/=(const M& a) { return *this = *this / a; }
	M operator-() const { return M() - *this; }
	M& operator++(int) { return *this = *this + 1; }
	M& operator--(int) { return *this = *this - 1; }

	M pow(ll n) const {
		if (n < 0) return inv().pow(-n);
		M x = *this, res = 1;
		while (n) {
			if (n & 1) res *= x;
			x *= x;
			n >>= 1;
		}
		return res;
	}

	M inv() const {
		ll a = v, b = MOD, p = 1, q = 0, t;
		while (b != 0) {
			t = a / b;
			swap(a -= t * b, b);
			swap(p -= t * q, q);
		}
		return M(p);
	}

	bool operator==(const M& a) const { return v == a.v; }
	bool operator!=(const M& a) const { return v != a.v; }
	friend ostream& operator<<(ostream& os, const M& a) { return os << a.v; }
};

using Mint = ModInt<1000000007>;

struct segtree {
	vector<Mint> dat;
	int sz = 1;

	void init(int n) {
		while (sz < n) sz *= 2;
		dat = V<Mint>(sz * 2, Mint(1));
	}

	void update(int pos, Mint x) {
		pos += sz - 1;
		dat[pos] *= x;

		while (pos > 0) {
			pos = (pos - 1) / 2;
			dat[pos] = dat[pos * 2 + 1] * dat[pos * 2 + 2];
		}
	}

	Mint get(int a, int b, int k, int l, int r) {
		if (b <= l || r <= a) return 1;
		if (a <= l && r <= b) return dat[k];
		return get(a, b, k * 2 + 1, l, (l + r) / 2) * get(a, b, k * 2 + 2, (l + r) / 2, r);
	}
};

template<class T>
struct BIT {
	int n;
	vector<T> bit;

	BIT(int _n = 0) : n(_n), bit(n + 1) {}

	//sum of [0, i), 0 <= i <= n
	T sum(int i) {
		T s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}

	//0 <= i < n
	void add(int i, T x) {
		++i;
		while (i <= n) {
			bit[i] += x;
			i += i & -i;
		}
	}

	//[l, r) 0 <= l < r < n
	T sum(int l, int r) {
		return sum(r) - sum(l);
	}
};

const int maxn = 100010;
const int INF = 1e9;

struct Edge {
	int to, col;
	Mint w;
	Edge(){}
	Edge(int to, int x, int col) : to(to), w(x), col(col) {}
};

vector<Edge> g[maxn];
bool centroid[maxn];
int subtree_size[maxn];

int compute_subtree_size(int v, int p) {
	int c = 1;
	for (auto e : g[v]) {
		int w = e.to;
		if (w == p || centroid[w]) continue;
		c += compute_subtree_size(w, v);
	}
	return subtree_size[v] = c;
}

pair<int, int> search_centroid(int v, int p, int t) {
	auto res = make_pair(INF, -1);
	int s = 1, m = 0;

	for (auto e : g[v]) {
		int w = e.to;
		if (w == p || centroid[w]) continue;

		res = min(res, search_centroid(w, v, t));
		m = max(m, subtree_size[w]);
		s += subtree_size[w];
	}

	m = max(m, t - s);
	res = min(res, mp(m, v));
	return res;
}

void gen(int v, int p, int x, Mint val, V<pair<int, Mint>>& vec, int tg) {
	vec.eb(x, val);

	for (auto e : g[v]) {
		int w = e.to;
		if (centroid[w] || e.to == p) continue;
		int nx = x;
		if (e.col == tg) {
			++nx;
		} else {
			nx -= 2;
		}
		gen(w, v, nx, val * e.w, vec, tg);
	}
}

Mint ng(1);
Mint all(1);

void solve_sub(int v) {
	compute_subtree_size(v, -1);
	auto info = search_centroid(v, -1, subtree_size[v]);
	int s = info.se;
	int sz = info.fi;
	centroid[s] = 1;
	dump(s);

    //centroid = s !!!!!

	rep(tg, 2) {
		segtree seg;
		BIT<int> bit(sz * 4 + 10);
		seg.init(sz * 4 + 10);
		int B = sz * 2 + 5;
		bit.add(B, 1);

		for (auto e : g[s]) {
			if (centroid[e.to]) continue;
			V<pair<int, Mint>> vc;
			gen(e.to, s, (e.col == tg ? 1 : -2), e.w, vc, tg);
			dump(vc);

			for (auto &data : vc) {
				int p = data.fi;
				Mint w = data.se;
				int l = -p + B + 1;
				int num = bit.sum(l, bit.n);
				//dump(num);
				Mint sw = seg.get(l, seg.sz, 0, 0, seg.sz);
				//dump(sw);
				ng *= sw;
				ng *= w.pow(num);
			}

			if (tg == 0) { //update all path
				for (auto &data : vc) { 
					Mint w = data.se;
					int num = bit.sum(bit.n);
					Mint sw = seg.get(0, seg.sz, 0, 0, seg.sz);
					all *= sw;
					all *= w.pow(num);
				}				
			}

			for (auto &data : vc) {
				int p = data.fi;
				Mint w = data.se;
				bit.add(p + B, 1);
				seg.update(p + B, w);
			}
		}
	}

	for (auto e : g[s]) {
		int w = e.to;
		if (centroid[w]) continue;
		solve_sub(w);
	}
}

int main() {
	int n; cin >> n;
	rep(i, n-1) {
		int a, b, x, t;
		cin >> a >> b >> x >> t;
		--a; --b;
		g[a].eb(b, x, t);
		g[b].eb(a, x, t);
	}

	solve_sub(0);
	//cout << ng << endl;
	//cout << all << endl;
	cout << all / ng << endl;

	return 0;
}