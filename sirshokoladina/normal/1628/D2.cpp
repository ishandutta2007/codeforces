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
const ll mod = 1000000007;

struct Input {
	ll n, m, k;
	
	bool read() {
		return !!(cin >> n >> m >> k);
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ll ans;

	void write() {
		cout << ans << endl;
	}
};


namespace Main {
	ll pow(ll a, ll n) {
		ll ans = 1;
		while (n) {
			if (n & 1) {
				(ans *= a) %= mod;
			}
			(a *= a) %= mod;
			n >>= 1;
		}
		return ans;
	}

	ll inv(ll a) {
		return pow(a, mod - 2);
	}
	
	struct Solution: Data {
		ll rev[N + 1];
		ll f[N + 1];
		ll rf[N + 1];
		ll pow2[N + 1];
		ll rpow2[N + 1];

		Solution() {
			forn (i, N + 1) {
				rev[i] = inv(i);
			}
			f[0] = 1;
			rf[0] = 1;
			pow2[0] = 1;
			rpow2[0] = 1;
			forn (i, N) {
				f[i + 1] = f[i] * (i + 1) % mod;
				rf[i + 1] = rf[i] * rev[i + 1] % mod;
				pow2[i + 1] = pow2[i] * 2 % mod;
				rpow2[i + 1] = rpow2[i] * rev[2] % mod;
			}
		}

		ll c(int a, int b) {
			return f[a + b] * rf[a] % mod * rf[b] % mod;
		}
		
		void solve() {
			n -= m;

			// m - add
			// n - substract

			if (m == 0) {
				ans = 0;
				return;
			}
			if (n == 0) {
				ans = m * k % mod;
				return;
			}
			debug(mt(n, m));
			ans = 0;
			forn (i, m + 1) {
				debug(i);
				debug(c(m - i, n - 1));
				debug(pow2[n + m - i]);
				debug(rpow2[n + m - i]);
				(ans += i * c(m - i, n - 1) % mod * rpow2[n + m - i]) %= mod;
			}
			(ans *= k) %= mod;
		}
		
		void clear() {
		}
	};
}


Main::Solution sol;

int main() {
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