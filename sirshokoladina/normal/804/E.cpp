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

const int N = 1000;

struct Input {
	int n;

	bool read () {
		return !!(cin >> n);
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans;
	ve<pii> res;

	void write () {
		puts(ans ? "YES" : "NO");
		if (ans) {
			forn (i, sz(res)) {
				printf("%d %d\n", res[i].fs + 1, res[i].sc + 1);
			}
		}
	}
};


namespace Main {
	
	struct Solution: Data {

		void add0 (int m, int s) {
			forn (i, m) {
				int j = (m + s - i) % m;
				if (i < j) {
					res.pb(mp(i, j));
				}
			}
		}

		void add1 (int m, int s) {
			forn (i, m) {
				int j = (m + s - i) % m;
				if (i < j) {
					res.pb(mp(i, m));
					res.pb(mp(i, j));
					res.pb(mp(j, m));
				}
			}
		}
		
		void solve () {
			if (n % 4 == 2 || n % 4 == 3) {
				ans = 0;
				return;
			}
			ans = 1;
			
			if (n % 4 == 0) {
				forn (t, n / 4) {
					add0(n, t);
					add0(n, n / 2 - 1 - t);
					add0(n, n - 1 - t);
					add0(n, n / 2 + t);
				}
			}
			if (n % 4 == 1) {
				int m = n - 1;
				forn (t, m / 4) {
					add0(m, t);
					add0(m, m / 2 - 1 - t);
					if (t == 0) {
						add1(m, m - 1 - t);
					} else {
						add0(m, m - 1 - t);
					}
					add0(m, m / 2 + t);
				}
			}

			forn (i, sz(res)) {
				if (res[i].fs > res[i].sc) {
					swap(res[i].fs, res[i].sc);
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
		sol.clear();
	}
	*/
	
	return 0;
}