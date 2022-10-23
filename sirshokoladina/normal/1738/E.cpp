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

struct Input {
	int n;
	vi a;
	
	bool read() {
		if (!(cin >> n)) {
			return 0;
		}
		a.resize(n);
		forn (i, n) {
			cin >> a[i];
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
		ve<ll> f, rf, p2;

		void precalc() {
			f.pb(1);
			forn (i, n) {
				f.pb(f.back() * (i + 1) % mod);
			}
			for (ll x : f) {
				rf.pb(inv(x));
			}
			p2.pb(1);
			forn (i, n) {
				p2.pb(p2.back() * 2 % mod);
			}
		}

		ll C(int x, int y) {
			return f[x + y] * rf[x] % mod * rf[y] % mod;
		}

		ve<ll> s;
		map<ll, int> cnt;
		
		void solve() {
			precalc();

			s.resize(n + 1);
			s[0] = 0;
			forn (i, n) {
				s[i + 1] = s[i] + a[i];
			}
			forn (i, 1, n) {
				cnt[s[i]]++;
			}

			ll tot = s[n];

			debug(tot);
			debug(cnt);

			ans = 1;
			for (const auto &p : cnt) {
				ll s1 = p.fs;
				ll s2 = tot - s1;
				if (s1 < s2) {
					continue;
				}
				int x = p.sc;
				if (s1 == s2) {
					(ans *= p2[x]) %= mod;
					continue;
				}
				if (!cnt.count(s2)) {
					continue;
				}
				int y = cnt.at(s2);
				(ans *= C(x, y)) %= mod;
			}
		}
		
		void clear() {
			*this = Solution();
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