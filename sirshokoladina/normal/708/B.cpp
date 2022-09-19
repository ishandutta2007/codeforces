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
	int a00, a01, a10, a11;
	
	bool read () {
		return !!(cin >> a00 >> a01 >> a10 >> a11);
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	string ans;
	
	void write () {
		puts(ans.c_str());
	}
};


namespace Main {
	
	struct Solution: Data {
	
		vi calc_v (int n) {
			vi res;
			for (int i = 0; 1; ++i) {
				int cnt = i * (i - 1) / 2;
				if (cnt > n) {
					break;
				}
				if (cnt == n) {
					res.pb(i);
				}
			}
			return res;
		}
		
		void make (int k0, int k1) {
			if (k0 == 0) {
				ans = string(k1, '1');
				return;
			}
			debug();
			if (k1 == 0) {
				ans = string(k0, '0');
				return;
			}
			if (a01 == 0) {
				ans = string(k1, '1') + string(k0, '0');
				return;
			}
			
			debug();
			int q = a10 / k1;
			int r = a10 % k1;
			debug(mt(k0, k1, a01, a10, q, r));
			
			debug();
			ans = string(k0 - q - 1, '0') + string(r, '1') + '0' + string(k1 - r, '1') + string(q, '0');
			debug();
		}
		
		void solve () {
			ans = "Impossible";
			if (a00 == 0 && a01 == 0 && a10 == 0 && a11 == 0) {
				ans = "0";
				return;
			}
			vi v0 = calc_v(a00);
			vi v1 = calc_v(a11);
			for (int k0 : v0) {
				for (int k1 : v1) {
					debug(mt(k0, k1));
					if (k0 * k1 == a01 + a10) {
						deepen(0);
						make(k0, k1);
						return;
					}
				}
			}
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
	}
	*/
	
	return 0;
}