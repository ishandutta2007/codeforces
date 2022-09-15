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

struct Input {
	int n;
	ll a[N];
	
	bool read() {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%" PRId64, &a[i]);
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
	
	struct Solution: Data {

		ll score(const ve<pll> &v) {
			int i = 0;
			int j = sz(v) - 1;
			ll sum_l = v[i].fs;
			ll sum_r = v[j].fs;
			while (i < j) {
				if (sum_l < sum_r) {
					i++;
					sum_l += v[i].fs;
				} else {
					j--;
					sum_r += v[j].fs;
				}
			}
			ll res = 0;
			ll x = v[i].sc;
			debug(x);
			forn (t, sz(v)) {
				res += v[t].fs * abs(v[t].sc - x);
			}
			debug(res);
			return res;
		}

		ll calc(ll d) {
			debug(d);
			ll res = 0;

			ve<pll> v;
			ll r = d;
			forn (i, n) {
				ll cnt = min(r, a[i]);
				if (cnt) {
					v.pb(mp(cnt, i));
				}
				r -= cnt;
				if (r == 0) {
					debug(v);
					res += score(v);
					v.clear();
					ll s = a[i] - cnt;
					s %= d;
					if (s > 0) {
						v.pb(mp(s, i));
					}
					r = d - s;
				}
			}
			debug(r);
			debug(v);
			assert(sz(v) == 0);
			return res;
		}
		
		void solve() {
			deepen(0);
			ll sum = 0;
			forn (i, n) {
				sum += a[i];
			}
			if (sum <= 1) {
				ans = -1;
				return;
			}
			ans = sum * N;
			for (ll i = 2; i * i <= sum; ++i) {
				if (sum % i == 0) {
					umn(ans, calc(i));
					while (sum % i == 0) {
						sum /= i;
					}
				}
			}
			if (sum > 1) {
				umn(ans, calc(sum));
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