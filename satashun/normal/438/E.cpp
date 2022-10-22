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

using Mint = ModInt<998244353>;

//depend on ModInt
template<class D>
struct NumberTheoreticTransform {
    D mod, root;

    NumberTheoreticTransform(int mod, int root) : mod(mod), root(root) {}

    void ntt(std::vector<D> &a, bool rev = false) {
        int n = a.size();
        int h = 0;
        for (int i = 0; 1 << i < n; i++) h++;
        for (int i = 0; i < n; i++) {
            int j = 0;
            for (int k = 0; k < h; k++) {
            	j |= (i >> k & 1) << (h - 1 - k);
            }
            if (i < j) std::swap(a[i], a[j]);
        }
        for (int i = 1; i < n; i *= 2) {
            D w = root.pow(((mod - 1) * D(i * 2).inv()).v);
            if (rev) w = w.inv();
            for (int j = 0; j < n; j += i * 2) {
                D wn = 1;
                for (int k = 0; k < i; k++) {
                    D s = a[j + k + 0];
                    D t = a[j + k + i] * wn;
                    a[j + k + 0] = s + t;
                    a[j + k + i] = s - t;
                    wn *= w;
                }
            }
        }
        int v = D(n).inv().v;
        if (rev) {
        	for (int i = 0; i < n; i++) {
        		a[i] *= v;
        	}
        }
    }

    std::vector<D> mul(std::vector<D> a, std::vector<D> b) {
        int s = a.size() + b.size() - 1;
        int t = 1;
        while (t < s) t *= 2;
        a.resize(t);
        b.resize(t);
        ntt(a);
        ntt(b);

        for (int i = 0; i < t; i++) {
        	a[i] *= b[i];
        }
        ntt(a, true);

        a.resize(s);
        return a;
    }
};

template<class D>
struct Poly : public V<D> {
	Poly() {}

	template<class...Args>
	Poly(Args...args):V<D>(args...){}
	Poly(initializer_list<D>init):V<D>(init.begin(),init.end()){}

	int size() const { return V<D>::size(); }
	D at(int p) const { return (p < this->size() ? (*this)[p] : D(0)); }

	Poly operator+(const Poly& r) const {
		auto n = max(size(), r.size());
		V<D> tmp(n);
		for (int i = 0; i < n; ++i) {
			tmp[i] = at(i) + r.at(i);
		}
		return tmp;
	}
	Poly operator-(const Poly& r) const {
		auto n = max(size(), r.size());
		V<D> tmp(n);
		for (int i = 0; i < n; ++i) {
			tmp[i] = at(i) - r.at(i);
		}
		return tmp;
	}
	Poly operator*(const D& k) const {
		int n = size();
		V<D> tmp(n);
		for (int i = 0; i < n; ++i) {
			tmp[i] = at(i) * k;
		}
		return tmp;
	}
	Poly operator*(const Poly& r) const {
		NumberTheoreticTransform<D> ntt(998244353, 3);
		Poly a = *this;
		Poly b = r;
		auto v = ntt.mul(a, b);
		return v; 
	}

	Poly pref(int len) const {
		return Poly(this->begin(), this->begin() + min(this->size(), len));
	}

	Poly diff() const {
		V<D> res(max(0, size() - 1));
		for (int i = 1; i < size(); ++i) {
			res[i - 1] = at(i) * i;
		}
		return res;
	}

	Poly inte() const {
		V<D> res(size() + 1);
		for (int i = 0; i < size(); ++i) {
			res[i + 1] = at(i) / (D)(i + 1);
		}
		return res;
	}

	//f * f.inv(m) === 1 mod (x^m)
	//f_0 ^ -1 must exist
	Poly inv(int m) const {
		Poly res = Poly({D(1) / at(0)});
		for (int i = 1; i < m; i *= 2) {
			res = (res * D(2) - res * res * pref(i * 2)).pref(i * 2);
		}
		return res.pref(m);
	}

	//f_0 = 1 must hold
	Poly log(int n) const {
		auto f = pref(n);
		return (f.diff() * f.inv(n - 1)).pref(n - 1).inte();
	}

	//f_0 = 0 must hold
	Poly exp(int n) const {
		auto h = diff();
		Poly f({1}), g({1});

		for (int m = 1; m < n; m *= 2) {		
			g = (g * D(2) - f * g * g).pref(m); 
			auto q = h.pref(m - 1);
			auto w = (q + g * (f.diff() - f * q)).pref(m * 2 - 1);
			f = (f + f * (*this - w.inte()).pref(m * 2)).pref(m * 2);
		}

		return f.pref(n);
	}

	//f_0 = 1 must hold (use it with modular sqrt)
	Poly sqrt(int n) const {
		Poly f = pref(n);
		Poly g({1});
		for (int i = 1; i < n; i *= 2) {
			g = (g + f.pref(i * 2) * g.inv(i * 2)) * D(2).inv();
		}
		return g.pref(n);
	}

	Poly& operator+=(const Poly& r) { return *this = *this + r; }
	Poly& operator-=(const Poly& r) { return *this = *this - r; }
	Poly& operator*=(const D& r) { return *this = *this * r; }
	Poly& operator*=(const Poly& r) { return *this = *this * r; }
	Poly& operator/=(const Poly& r) { return *this = *this / r; }
	Poly& operator/=(const D &r) {return *this = *this / r; }
	Poly& operator%=(const Poly& r) { return *this = *this % r; }

	friend ostream& operator<<(ostream& os, const Poly& pl) {
		if (pl.size() == 0) return os << "0";
		for (int i = 0; i < pl.size(); ++i) {
			if (pl[i]) {
				os << pl[i] << "x^" << i;
				if (i + 1 != pl.size()) os << ",";
			}
		}
		return os;
	}	
};

const int L = 100010;

int main() {
	int n, m; scanf("%d %d", &n, &m);

	Poly<Mint> c(L);

	rep(i, n) {
		int x; cin >> x;
		c[x] = 1;
	}

	Poly<Mint> one({1});

	auto p = (one - c * Mint(4)).sqrt(L);
	auto q = (one + p).inv(L) * Mint(2);

	for (int i = 1; i <= m; ++i) {
		printf("%d\n", q[i].v);
	}

	return 0;
}