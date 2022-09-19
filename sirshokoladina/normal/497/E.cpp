#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
#else
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
#endif

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define forv(i,v) for (auto i = v.begin(); i != v.end(); ++i)
#define forr(i,v) for (auto i = v.end(); i != v.begin() && (--i, 1); )
#define ve vector
#define pa pair
#define tu tuple
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T> inline T abs (T x) {return x > T() ? x : -x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const ll mod = 1000000007;

struct Input {
	ll n;
	int k;
	
	bool read () {
		return cin >> n >> k;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ll ans;
	
	void write () {
		cout << ans << endl;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	int s;
	
	ve<ve<ll> > mul (const ve<ve<ll> > &a, const ve<ve<ll> > &b) {
		ve<ve<ll> > ans(s, ve<ll>(s, 0));
		forn (i, s) {
			forn (j, s) {
				forn (k, s) {
					(ans[i][j] += a[i][k] * b[k][j]) %= mod;
				}
			}
		}
		return ans;
	}
	
	ve<ve<ll> > shift (const ve<ve<ll> > &a, int t) {
		ve<ve<ll> > ans(s, ve<ll>(s));
		forn (i, k) {
			forn (j, k) {
				ans[(i + t) % k][(j + t) % k] = a[i][j];
			}
		}
		forn (i, k) {
			ans[k][(i + t) % k] = a[k][i];
			ans[(i + t) % k][k] = a[i][k];
		}
		ans[k][k] = a[k][k];
		return ans;
	}
	
	int f (ll n) {
		int res = 0;
		while (n) {
			(res += n % k) %= k;
			n /= k;
		}
		return res;
	}
	
	void solve () {
		s = k + 1;
		ve<ve<ll> > a(s, ve<ll>(s, 0));
		forn (i, s) {
			a[i][i] = 1;
		}
		a[0][k] = 1;
		a[0][0] = 0;
		a[k][0] = mod - 1;
		a[k][k] = 2;
		
		ve<ve<ll> > res(s, ve<ll>(s, 0));
		forn (i, s) {
			res[i][i] = 1;
		}
		while (n) {
			while (n % k) {
				res = mul(shift(a, f(n - 1)), res);
				--n;
			}
			ve<ve<ll> > b = a;
			for (int t = 1; t < k; ++t) {
				a = mul(a, shift(b, t));
			}
			n /= k;
		}
		debug(res[k]);
		ans = res[k][k];
	}
	
	void clear () {
		*this = Solution();
	}
};

Solution sol;

int main () {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);
#ifdef SG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	while (sol.read()) {
		sol.solve();
		sol.write();
		sol.clear();
	}
#else
	sol.read();
	sol.solve();
	sol.write();
#endif
	return 0;
}