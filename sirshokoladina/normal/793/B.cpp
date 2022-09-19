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
	int n, m;
	string s[N];
	
	bool read () {
		if (!(cin >> n >> m)) {
			return 0;
		}
		getline(cin, s[0]);
		forn (i, n) {
			getline(cin, s[i]);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool ans;
	
	void write () {
		puts(ans ? "YES" : "NO");
	}
};


namespace Main {

	struct Solution: Data {
		bool d[N][N][4];
		
		void spread () {
			forn (i, n) {
				forn (j, m - 1) {
					if (s[i][j + 1] != '*') {
						d[i][j + 1][0] |= d[i][j][0];
					}
				}
			}
			forn (i, n) {
				ford (j, m - 1) {
					if (s[i][j] != '*') {
						d[i][j][1] |= d[i][j + 1][1];
					}
				}
			}
			forn (j, m) {
				forn (i, n - 1) {
					if (s[i + 1][j] != '*') {
						d[i + 1][j][2] |= d[i][j][2];
					}
				}
			}
			forn (j, m) {
				ford (i, n - 1) {
					if (s[i][j] != '*') {
						d[i][j][3] |= d[i + 1][j][3];
					}
				}
			}
		}
		
		void rot () {
			forn (i, n) {
				forn (j, m) {
					forn (t1, 4) {
						forn (t2, 4) {
							d[i][j][t1] |= d[i][j][t2];
						}
					}
				}
			}
		}
		
		void solve () {
			forn (i, n) {
				forn (j, m) {
					forn (t, 4) {
						d[i][j][t] = (s[i][j] == 'S');
					}
				}
			}
			spread();
			rot();
			spread();
			rot();
			spread();
			ans = 0;
			forn (i, n) {
				forn (j, m) {
					forn (t, 4) {
						if (d[i][j][t] && s[i][j] == 'T') {
							ans = 1;
						}
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
		sol.clear();
	}
	*/
	
	return 0;
}