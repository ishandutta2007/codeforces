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

const ll mod = 998244353;
const int N = 200000;

struct Input {
	int n, m;
	int x[N], y[N];
	
	bool read() {
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, m) {
			scanf("%d%d", &x[i], &y[i]);
			--x[i];
			--y[i];
		}
		return 1;
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
	const int D = 64;

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
		ll f[2 * N + 10];
		ll rf[2 * N + 10];

		Solution() {
			f[0] = rf[0] = 1;
			forn (i, 1, 2 * N + 10) {
				f[i] = f[i - 1] * i % mod;
				rf[i] = inv(f[i]);
			}
		}

		ll calc_c(int n, int m) {
			if (n < 0 || m < 0) {
				return 0;
			}
			return f[n + m] * rf[n] % mod * rf[m] % mod;
		}

		ull a[N / D + 5];
		
		void solve() {
			memset(a, 0, sizeof a);
			forn (t, m) {
				debug(mt(x[t], y[t]));
				{
					int k = (x[t] + D) / D;
					int l = y[t] / D;
					int p = y[t] % D;
					ford (i, l + 1, k) {
						a[i] <<= 1;
						a[i] ^= (a[i - 1] >> (D - 1)) & 1ull;
					}
					ull pref = a[l] & ((1ull << p) - 1ull);
					a[l] = pref + ((a[l] - pref) << 1);
				}
				{
					int p = y[t];
					a[p / D] &= ~(1ull << (p % D));
				}
				{
					int p = y[t] + 1;
					a[p / D] |= 1ull << (p % D);
				}
				debug(a, a + n / D + 1);
			}
			int cnt = 0;
			forn (i, N / D + 5) {
				cnt += __builtin_popcountll(a[i] & (~0ull >> (64 - D)));
			}
			debug(mt(n, cnt));
			ans = calc_c(n - 1 - cnt, n);
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