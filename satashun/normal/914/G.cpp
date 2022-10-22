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

using Mint = ModInt<1000000007>;

const int MX = 1 << 17;
const Mint i2 = Mint(2).inv();

template<class T>
void and_fwt(vector<T>& f) {
    int n = f.size();
    for (int d = 1; d < n; d <<= 1) {
        for (int i = 0; i < n; i += d * 2) {
            for (int j = 0; j < d; ++j) {
            	Mint x = f[i+j], y = f[i+j+d];
            	f[i+j] = x + y;
            }
        }
    }
}

template<class T>
void and_ifwt(vector<T>& f) {
    int n = f.size();
    for (int d = 1; d < n; d <<= 1) {
        for (int i = 0; i < n; i += d * 2) {
            for (int j = 0; j < d; ++j) {
            	Mint x = f[i+j], y = f[i+j+d];
            	f[i+j] = x - y;
            }
        }
    }
}

template<class T>
void xor_fwt(vector<T>& f) {
    int n = f.size();
    for (int d = 1; d < n; d <<= 1) {
        for (int i = 0; i < n; i += d * 2) {
            for (int j = 0; j < d; ++j) {
                Mint x = f[i+j], y = f[i+j+d];
                f[i+j] = x + y;
                f[i+j+d] = x - y;
            }
        }
    }
}

template<class T>
void xor_ifwt(vector<T>& f) {
    int n = f.size();
    for (int d = 1; d < n; d <<= 1) {
        for (int i = 0; i < n; i += d * 2) {
            for (int j = 0; j < d; ++j) {
                Mint x = f[i+j], y = f[i+j+d];
                f[i+j] = (x + y) * i2;
                f[i+j+d] = (x - y) * i2;
            }
        }
    }
}

//size : power of 2
template<class T>
V<T> subset_convolution(const V<T>& a, const V<T>& b) {
	int sz = a.size();
	int N = __lg(sz);
	VV<Mint> sa(sz, V<Mint>(N + 1)), sb(sz, V<Mint>(N + 1));
	rep(i, sz) {
		sa[i][__builtin_popcount(i)] = a[i];
		sb[i][__builtin_popcount(i)] = b[i];
	}
	rep(k, N) {
		rep(i, sz) {
			if (!((i >> k) & 1)) {
				for (int j = 0; j <= N; ++j) {
					sa[i | (1 << k)][j] += sa[i][j];
					sb[i | (1 << k)][j] += sb[i][j];
				}
			}
		}
	}
	
	//conv
	VV<Mint> res(sz, V<Mint>(N + 1));
	rep(i, sz) {
		for (int j = 0; j <= N; ++j) {
			for (int k = 0; k + j <= N; ++k) {
				res[i][j + k] += sa[i][j] * sb[i][k];
			}
		}
	}
	rep(k, N) {
		rep(i, sz) {
			if (!((i >> k) & 1)) {
				for (int j = 0; j <= N; ++j) {
					res[i | (1 << k)][j] -= res[i][j];
				}
			}
		}
	}
	V<Mint> ans(sz);
	rep(i, sz) ans[i] = res[i][__builtin_popcount(i)];
	return ans;
}

Mint fib[MX];
V<Mint> cnt(MX);
V<Mint> x, c, ab;

//finally ab and c and x1 

int main() {
	fib[1] = 1;
	for (int i = 2; i < MX; ++i) {
		fib[i] = fib[i-1] + fib[i-2];
	}

	int n; scanf("%d", &n);

	rep(i, n) {
		int v; scanf("%d", &v);
		cnt[v]++;
	}

	dump(cnt.size());

	ab = subset_convolution(cnt, cnt);
	x = cnt;
	c = cnt;

	rep(i, MX) {
		x[i] = c[i] = cnt[i]; 
	}

	xor_fwt(x);
	rep(i, MX) x[i] *= x[i];
	xor_ifwt(x);

	rep(i, MX) {
		x[i] *= fib[i];
		c[i] *= fib[i];
		ab[i] *= fib[i];
	}
	
	and_fwt(ab);
	and_fwt(c);
	and_fwt(x);
	rep(i, MX) {
		ab[i] *= x[i] * c[i];
	}
	and_ifwt(ab);

	Mint ans;
	rep(i, 17) {
		ans += ab[1 << i];
	}
	cout << ans << endl;

	return 0;
}