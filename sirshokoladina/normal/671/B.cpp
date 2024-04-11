#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
#else
	template<typename T> struct outputer;
	struct outputable {};
	#define PRINT(...)
	#define OUTPUT(...)
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
#endif

#define ARG4(_1,_2,_3,_4,...) _4

#define forn3(i,l,r) for (int i = int(l); i < int(r); ++i)
#define forn2(i,n) forn3 (i, 0, n)
#define forn(...) ARG4(__VA_ARGS__, forn3, forn2) (__VA_ARGS__)

#define ford3(i,l,r) for (int i = int(r) - 1; i >= int(l); --i)
#define ford2(i,n) ford3 (i, 0, n)
#define ford(...) ARG4(__VA_ARGS__, ford3, ford2) (__VA_ARGS__)

#define ve vector
#define pa pair
#define tu tuple
#define mp make_pair
#define mt make_tuple
#define pb emplace_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long double ld;
typedef int64_t ll;
typedef uint64_t ull;
typedef uint32_t ui;
typedef uint16_t us;
typedef uint8_t uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 500000;

struct Input {
	int n;
	ll k;
	ll a[N];
	
	bool read () {
		if (!(cin >> n >> k)) {
			return 0;
		}
		forn (i, n) {
			scanf("%" SCNd64, &a[i]);
		}
		return 1;
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
};

struct Solution: Data {
	
	bool check1 () {
		ll s = 0;
		forn (i, n) {
			s += a[i];
		}
		ll q = s / n;
		ll r = s % n;
		ll need = 0;
		forn (i, n) {
			ll t = q;
			if (n - 1 - i < r) {
				t++;
			}
			need += max<ll>(a[i] - t, 0);
		}
		if (need <= k) {
			ans = r ? 1 : 0;
			return 1;
		}
		return 0;
	}
	
	ll fnd_up () {
		ll lb = 0, rb = 1000000010;
		while (lb != rb) {
			ll md = (lb + rb) / 2;
			ll need = 0;
			forn (i, n) {
				need += max<ll>(a[i] - md, 0);
			}
			if (need <= k) {
				rb = md;
			} else {
				lb = md + 1;
			}
		}
		return lb;
	}
	
	ll fnd_dn () {
		ll lb = 0, rb = 1000000010;
		while (lb != rb) {
			ll md = (lb + rb + 1) / 2;
			ll need = 0;
			forn (i, n) {
				need += max<ll>(md - a[i], 0);
			}
			if (need <= k) {
				lb = md;
			} else {
				rb = md - 1;
			}
		}
		return lb;
	}
	
	void solve () {
		sort(a, a + n);
		if (check1()) {
			return;
		}
		ll up = fnd_up();
		ll dn = fnd_dn();
		ans = up - dn;
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
	freopen((problemname + ".in").c_str(), "r", stdin);
//	freopen((problemname + ".out").c_str(), "w", stdout);
	while (sol.read()) {
		sol.solve();
		sol.write();
		sol.clear();
	}
#else
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);
	sol.read();
	sol.solve();
	sol.write();
#endif
	return 0;
}