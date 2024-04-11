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

const int N = 1000000;
const int X = 1000000;
const int L = 20;

const ll mod = 1000000007;

struct Input {
	int r, n;
	
	bool read () {
		return scanf("%d%d", &r, &n) == 2;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ll ans;
	
	void write () {
		printf("%d\n", int(ans));
	}
};


namespace Main {
	
	struct Solution: Data {
		ll f[X + L + 1];
		ll rf[X + L + 1];
		int p[X + 1];
		
		ll get_c (int x, int y) {
			return f[x + y] * rf[x] % mod * rf[y] % mod;
		}
		
		ll get_a (int rr, int k) {
			if (k == 0) {
				return 1;
			}
			if (rr == 0) {
				return 2;
			}
			return (2 * get_c(rr, k) + mod - get_c(rr - 1, k)) % mod;
		} 
		
		void solve () {
			vi v;
			while (n != 1) {
				v.pb(p[n]);
				n /= p[n];
			}
			
			ans = 1;
			for (int i = 0; i < sz(v); ) {
				int j = i;
				while (j < sz(v) && v[i] == v[j]) {
					++j;
				}
				
				ans = ans * get_a(r, j - i) % mod;
				
				i = j;
			}
		}
		
		ll pw (ll a, ll nn) {
			ll res = 1;
			while (nn) {
				if (nn & 1) {
					res = res * a % mod;
				}
				a = a * a % mod;
				nn >>= 1;
			}
			return res;
		}
		
		Solution () {
			f[0] = 1;
			forn (i, X + L) {
				f[i + 1] = f[i] * (i + 1) % mod;
			}
			forn (i, X + L + 1) {
				rf[i] = pw(f[i], mod - 2);
			}
			
			memset(p, -1, sizeof p);
			for (int i = 2; i * i <= X; ++i) {
				if (p[i] == -1) {
					p[i] = i;
					for (int j = i * i; j <= X; j += i) {
						if (p[j] == -1) {
							p[j] = i;
						}
					}
				}
			}
			forn (i, 2, X + 1) {
				if (p[i] == -1) {
					p[i] = i;
				}
			}
		}
		
		void clear () {
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
	#endif
	
	int t;
	cin >> t;
	forn (i, t) {
		sol.read();
		sol.solve();
		sol.write();
		sol.clear();
	}
	
	return 0;
}