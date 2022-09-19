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
	#define fbegin(...)
	#define fend
	#define pbegin(...)
	#define pend
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

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 200000;
const ll mod = 1000000007;

struct Input {
	int n;
	ll a[N];
	
	bool read () {
		if (!(cin >> n)) {
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


namespace Main {
	
	struct Solution: Data {
		ll f[N + 1];
		ll rf[N + 1];
		
		ll c (int x, int y) {
			return f[x + y] * rf[x] % mod * rf[y] % mod;
		}
		
		ll pw (ll val, ll k) {
			ll res = 1;
			while (k) {
				if (k & 1) {
					res = res * val % mod;
				}
				val = val * val % mod;
				k >>= 1;
			}
			return res;
		}
		
		int sgn;
		
		void iteration () {
			debug(a, a + n);
			--n;
			forn (i, n) {
				a[i] = (a[i] + sgn * a[i + 1] + mod) % mod;
				sgn *= -1;
			}
		}
		
		ll calc (int t) {
			int m = (n + 1 - t) / 2;
			ll res = 0;
			forn (i, m) {
				debug(mt(a[t + 2 * i], c(i, m - 1 - i)));
				res = (res + a[t + 2 * i] * c(i, m - 1 - i)) % mod;
			}
			debug(res);
			return res;
		}
		
		void solve () {
			f[0] = 1;
			forn (i, n) {
				f[i + 1] = f[i] * (i + 1) % mod;
			}
			forn (i, n + 1) {
				rf[i] = pw(f[i], mod - 2);
			}
			
			if (n == 1) {
				ans = a[0];
				return;
			}
			
			sgn = 1;
			if (n & 1) {
				iteration();
			}
			debug(a, a + n);
			debug(sgn);
			ll val0 = calc(0);
			ll val1 = calc(1);
			if (n / 2 % 2 == 0) {
				sgn *= -1;
			}
			ans = (val0 + sgn * val1 + mod) % mod;
		}
		
		void clear () {
			*this = Solution();
		}
	};
}


Main::Solution sol;

int main () {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);

	#ifdef SG
		freopen((problemname + ".in").c_str(), "r", stdin);
//		freopen((problemname + ".out").c_str(), "w", stdout);
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
	
	/*
	int t;
	cin >> t;
	forn (i, t) {
		sol.read();
		sol.solve();
		sol.write();
		sol.clear();
	}
	*/
	
	return 0;
}