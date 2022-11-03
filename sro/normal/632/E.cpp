/* by Hyperhydrochloric Acid */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

template<int jt> struct ModInt {
	int x;
	ModInt(int v = 0) {x = v; if(x >= jt || x < 0) {x %= jt; if(x < 0) x += jt;}}
	ModInt(ll v) {x = v % jt; if(x < 0) x += jt;}
	operator int() const {return x;}
	friend inline ModInt &operator+=(ModInt &a, const ModInt &b) {a.x += b.x; return a.x >= jt ? (a.x -= jt, a) : a;}
	friend inline ModInt operator+(ModInt a, const ModInt &b) {return a += b;}
	friend inline ModInt operator+(ModInt a, int b) {return a += ModInt(b);}
	friend inline ModInt operator+(int a, ModInt b) {return b += ModInt(a);}
	friend inline ModInt &operator++(ModInt &a) {return a += 1;}
	friend inline ModInt &operator-=(ModInt &a, const ModInt &b) {a.x -= b.x; return a.x < 0 ? (a.x += jt, a) : a;}
	friend inline ModInt operator-(ModInt a, const ModInt &b) {return a -= b;}
	friend inline ModInt operator-(ModInt a, int b) {return a -= ModInt(b);}
	friend inline ModInt operator-(int a, ModInt b) {return ModInt(a) - b;}
	friend inline ModInt &operator--(ModInt &a) {return a -= 1;}
	friend inline ModInt &operator*=(ModInt &a, const ModInt &b) {a.x = (ll)a.x * b.x % jt; return a;}
	friend inline ModInt operator*(ModInt a, const ModInt &b) {return a *= b;}
	friend inline ModInt operator*(ModInt a, int b) {return a *= ModInt(b);}
	friend inline ModInt operator*(int a, ModInt b) {return b *= ModInt(a);}
	static inline void exgcd(ll a, ll b, ll &x, ll &y) {b ? (exgcd(b, a % b, y, x), y -= a / b * x) : (x = 1, y = 0);}
	friend inline ModInt inv(const ModInt &a) {ll x, y; exgcd(a, jt, x, y); return x;}
	friend inline ModInt operator/(const ModInt &a, const ModInt &b) {return a * inv(b);}
	friend inline ModInt operator/(ModInt a, int b) {return a * inv(ModInt(b));}
	friend inline ModInt operator/(int a, ModInt b) {return ModInt(a) * inv(b);}
	friend inline ModInt operator/=(ModInt &a, const ModInt &b) {return a = a / b;}
};

const int jt = 469762049, rg = 3;
typedef ModInt<jt> mint;

mint inline ksmii(mint a, int b) {
	mint ans = 1;
	while(b) {
		if(b & 1) ans *= a;
		a *= a; b >>= 1;
	}
	return ans;
}

void inline fft(vector<mint> &a, int in) {
	int n = SZ(a), lg = 0; vector<int> ho(n, 0);
	while((1 << lg) < n) ++lg;
	loop(i, n) {
		ho[i] = (ho[i >> 1] >> 1) | ((i & 1) << (lg - 1));
		if(i < ho[i]) swap(a[i], a[ho[i]]);
	}
	range(i, 1, n - 1, i) {
		mint omega = ksmii(rg, (jt - 1) / (i << 1));
		range(j, 0, n - 1, i << 1) {
			mint omg = 1;
			loop(k, i) {
				mint y = omg * a[j + k + i];
				a[j + k + i] = a[j + k] - y;
				a[j + k] += y; omg *= omega;
			}
		}
	}
	if(!~in) {
		reverse(a.begin() + 1, a.end());
		mint fn = inv(mint(n));
		loop(i, n) a[i] *= fn;
	}
}

struct Poly: vector<mint> {
	Poly(int n = 0) {
		clear(); resize(n);
	}
	Poly(mint x) {
		resize(1); at(0) = x;
	}
	Poly inline operator*(const Poly &p) const {
		int sz = 1;
		while(sz < (int)(size() + SZ(p)) - 1) sz <<= 1;
		vector<mint> A(sz), B(sz);
		loop(i, (int)size()) A[i] = at(i);
		loop(i, SZ(p)) B[i] = p.at(i);
		fft(A, 1); fft(B, 1);
		loop(i, sz) A[i] *= B[i];
		fft(A, -1);
		Poly ans((int)(size() + SZ(p)) - 1);
		loop(i, SZ(ans)) ans[i] = A[i];
		return ans;
	}
};

Poly inline ksmii(Poly a, int b) {
	Poly ans(mint(1));
	while(b) {
		if(b & 1) ans = ans * a;
		a = a * a; b >>= 1;
	}
	return ans;
}

int n, k;

int main() {
	Poly pol(1005);
	scanf("%d%d", &n, &k);
	cont(i, n) {
		int a; scanf("%d", &a);
		pol[a] = 1;
	}
	pol = ksmii(pol, k);
	int res = 0;
	loop(i, SZ(pol)) if(pol[i]) printf("%d ", i);
	return 0; 
}