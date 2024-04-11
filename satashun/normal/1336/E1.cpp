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

#ifdef LOCAL
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << H;
	debug_out(T...);
}
#define debug(...) cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

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
	static int get_mod() { return MOD; }	
};

using Mint = ModInt<998244353>;

struct Matrix {
	V<bitset<35>> a;
	int H, W;
	Matrix() : H(0), W(0) {}
	Matrix(int H, int W) : H(H), W(W), a(V<bitset<35>>(H)){}

	void set(int i, int j, bool v) {
		a[i][j] = v;
	}

	int sweep(int var) {
		int rank = 0;
		vector<bool> used(H);
		rep(j, var) {
			int i = 0;
			while (i < H && (used[i] || a[i][j] == 0)) i++;
			if (i == H) continue;
			used[i] = true;
			rank++;
			bool t = a[i][j];
			rep(k, H) if (k != i) {
				if (a[k][j]) {
					a[k] ^= a[i];
				}
			}
/*
			debug("wo");
			rep(i, H) {
				debug(a[i]);
			}*/
		}
		return rank;
	}
};

const int maxv = 200010;

V<Mint> fact(maxv), ifact(maxv), inv(maxv), p2(maxv);

void init() {
	fact[0] = 1;
	p2[0] = 1;
	for (int i = 1; i < maxv; ++i) {
		fact[i] = fact[i-1] * i;
		p2[i] = p2[i-1] * 2;
	}

	ifact[maxv-1] = fact[maxv-1].inv();

	for (int i = maxv - 2; i >= 0; --i) {
		ifact[i] = ifact[i+1] * (i+1);
	}

	for (int i = 1; i < maxv; ++i) {
		inv[i] = ifact[i] * fact[i-1];
	}
}

Mint comb(int n, int r) {
	if (n < 0 || r < 0 || r > n) return Mint(0);
	return fact[n] * ifact[r] * ifact[n-r];
}

Mint dp[36][1 << 15];

int main() {
	init();

	int n, m; cin >> n >> m;
	Matrix A(n, m);

	rep(i, n) {
		ll x; cin >> x;
		A.a[i] = x;
	}

	rep(i, n) {
		debug(A.a[i]);
	}

	int r = A.sweep(m);
	debug(r);

	int free = n - r;

	V<ll> base;

	rep(i, n) {
		debug(A.a[i]);
		if (A.a[i].any()) {
			ll x = 0;
			rep(j, m) {
				if (A.a[i][j]) {
					x |= (1ll << j);
				}
			}
			base.pb(x);
			dump(x);
		}
	}

	V<Mint> ans(m + 1);
	if (r <= 20) {
		assert(base.size() == r);
		rep(i, 1 << r) {
			ll u = 0;
			rep(j, r) {
				if (i >> j & 1) {
					u ^= base[j];
				}
			}
			int t = __builtin_popcountll(u);
			ans[t] += p2[free];
		}
	} else { //relevant : small
		V<int> id(m, 0);
		rep(i, r) {
			rep(j, m) {
				if (base[i] >> j & 1) {
					id[j] = -1;
					break;
				}
			}
		}

		int now = 0;
		rep(i, m) {
			if (id[i] == 0) {
				id[i] = now++;
			}
		}

		dp[0][0] = 1;
		dump(id);

		rep(i, r) {
			int mask = 0;
			rep(j, m) {
				if (id[j] != -1 && (base[i] >> j & 1)) {
					mask |= (1 << id[j]); 
				}
			}
			debug(i, mask);
			for (int num = r; num >= 0; --num) {
				for (int j = 0; j < (1 << now); ++j) {
					if (dp[num][j]) {
						dp[num + 1][j ^ mask] += dp[num][j];
					}
				}
			}
		}

		for (int i = 0; i <= r; ++i) {
			for (int j = 0; j < (1 << now); ++j) {
				int b = __builtin_popcount(j);
				ans[b + i] += p2[free] * dp[i][j];
			}
		}
	}

	for (int i = 0; i <= m; ++i) {
		cout << ans[i] << (i == m ? '\n' : ' ');
	}

	return 0;
}