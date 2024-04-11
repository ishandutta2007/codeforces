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

using Mint = ModInt<1000000007>;

//from Gifted Infants

const Mint zero(0);
const Mint one(1);

bool iszero(Mint x) {
	return x.v == 0;
}

bool isone(Mint x) {
	return x.v == 1;
}

template<class T>
struct Matrix {
	int H, W;
	VV<T> a;
	Matrix() : H(0), W(0) {}
	Matrix(int H, int W) : H(H), W(W), a(VV<T>(H, V<T>(W))) {}
	Matrix(const VV<T>& v) : H(v.size()), W(v[0].size()), a(v) {}
	static Matrix E(int n) {
		Matrix a(n, n);
		rep(i, n) a.set(i, i, 1);
		return a;
	}
	T at(int i, int j) const {
		return a[i][j];
	}
	void set(int i, int j, T v) {
		a[i][j] = v;
	}
	Matrix operator+(const Matrix& r) const {
		assert(H == r.H && W == r.W);
		VV<T> v(H, V<T>(W));
		rep(i, H) rep(j, W) v[i][j] = a[i][j] + r.a[i][j];
		return Matrix(v);
	}
	Matrix operator-(const Matrix& r) const {
		assert(H == r.H && W == r.W);
		VV<T> v(H, V<T>(W));
		rep(i, H) rep(j, W) v[i][j] = a[i][j] - r.a[i][j];
		return Matrix(v);
	}
	Matrix operator*(const Matrix& r) const {
		assert(W == r.H);
		VV<T> v(H, V<T>(r.W));
		rep(i, H) rep(k, W) rep(j, r.W) v[i][j] += a[i][k] * r.a[k][j];
		return Matrix(v);
	}
	Matrix& operator+=(const Matrix& r) { return (*this) = (*this) + r; }
	Matrix& operator-=(const Matrix& r) { return (*this) = (*this) - r; }
	Matrix& operator*=(const Matrix& r) { return (*this) = (*this) * r; }

	Matrix pow(ll n) const {
		assert(H == W);
		int h = H;
		Matrix x = *this, res(h, h);
		res = E(h);
		while (n > 0) {
			if (n & 1) res *= x;
			x *= x;
			n >>= 1;
		}
		return res;
	}

	friend ostream& operator<<(ostream &o,const Matrix& A) {
		rep(i, A.H) {
			rep(j, A.W) o<<A.a[i][j]<<" ";
			o<<endl;
		}
		return o;
	}
};

vector<int> pre_kmp(string pat) {
	int k;
	vector<int> table((int)pat.size() + 1);
	table[0] = -1;

	for (int i = 1; i <= pat.size(); ++i) {
		k = table[i-1];

		while (k >= 0) {
			if (pat[k] == pat[i-1]) break;
			else k = table[k];
		}

		table[i] = k + 1;
	}

	return table;
}

using Mat = Matrix<Mint>;

int nxt[110][2];
V<int> pf;
string s;
int n;

Mat proc(int c) { //c = 0 or 1
	Mat A(n + 2, n + 2);
	int ap = n + 1;
	A.set(ap, ap, 2);

	for (int i = 0; i <= n; ++i) {
		A.a[i][i]++;

		int nx = i;
		if (i == n) {
			nx = pf[nx];
		}
		while (nx >= 0 && s[nx] != '0' + c) {
			nx = pf[nx];
		}

		nx++;
		if (nx == n) {
			A.a[i][ap]++;
			nx = pf[nx];
		}		
		A.a[i][nx]++;
	}

	return A;
}

int main() {
	int x; cin >> n >> x;
	cin >> s;
	pf = pre_kmp(s);
	dump(pf);

	Mat a = proc(0), b = proc(1);
	for (int i = 2; i <= x; ++i) {
		auto c = b * a;
		a = b; b = c;
	}

	if (x == 0) {
		b = a;
	}

	Mat res(1, n + 2);
	res.set(0, 0, 1);

	res = res * b;
	cout << res.at(0, n + 1) << endl;

	return 0;
}