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

struct Input {
	ll n, k;
	
	bool read () {
		return !!(cin >> n >> k);
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ll ans;
	
	void write () {
		cout << ans + 1 << endl;
	}
};


namespace Main {
	
	struct Solution: Data {
		ll f (ll x) {
			return (x + 1) / 2 - 1;
		}
		
		map<ll, ll> mem;
		
		ll calc (ll len, ll val) {
			if (!len) {
				return 0;
			}
			if (mem.count(len)) {
				return mem[len];
			}
			ll lp = (len - 1) / 2;
			ll rp = len / 2;
			return mem[len] = (f(len) == val) + calc(lp, val) + calc(rp, val);
		}
		
		ll rec (ll pref, ll len, ll num, ll val) {
			
			ll lp = (len - 1) / 2;
			ll rp = len / 2;
			
			debug(mt(pref, len, num, val, lp, rp, f(len), calc(len, val)));
			
			assert(calc(len, val) > num);
			
			if (f(len) == val) {
				if (num == 0) {
					return pref + lp;
				} else {
					num -= 1;
				}
			}
			
			if (calc(lp, val) > num) {
				return rec(pref, lp, num, val);
			}
			num -= calc(lp, val);
			
			return rec(pref + lp + 1, rp, num, val);
		}
		
		void solve () {
			deepen(0);
			--k;
			if (k == 0) {
				ans = 0;
				return;
			}
			--k;
			if (k == 0) {
				ans = n - 1;
				return;
			}
			--k;
			map<ll, map<ll, ll>, greater<ll>> a;
			a[f(n - 2)][n - 2] = 1;
			ll val;
			ll sum;
			while (1) {
				debug(mp(a, k));
				sum = 0;
				val = a.begin()->fs;
				while (a.begin()->fs == val) {
					auto q = a.begin()->sc;
					a.erase(a.begin());
					for (const auto &p : q) {
						sum += p.sc;
						ll lp = (p.fs - 1) / 2;
						ll rp = p.fs / 2;
						a[f(lp)][lp] += p.sc;
						a[f(rp)][rp] += p.sc;
					}
				}
				if (k < sum) {
					break;
				}
				k -= sum;
			}
			
			ans = rec(1, n - 2, k, val);
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