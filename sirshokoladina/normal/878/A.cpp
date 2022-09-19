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

const int N = 500000;
const int K = 10;

struct Input {
	int n;
	char t[N];
	int a[N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf(" %c%d", &t[i], &a[i]);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ve<pa<char, int>> ans;
	
	void write () {
		cout << sz(ans) << endl;
		forn (i, sz(ans)) {
			printf("%c %d\n", ans[i].fs, ans[i].sc);
		}
	}
};


namespace Main {
	int s[K];
	
	struct Solution: Data {
		
		void solve () {
			forn (i, K) {
				s[i] = 2;
			}
			forn (i, n) {
				forn (j, K) {
					if (a[i] & (1 << j)) {
						if (t[i] == '^') {
							s[j] ^= 1;
						} else if (t[i] == '|') {
							s[j] = 1;
						} else if (t[i] == '&') {
						}
					} else {
						if (t[i] == '^') {
						} else if (t[i] == '|') {
						} else if (t[i] == '&') {
							s[j] = 0;
						}
					}
				}
			}
			int x = 0, y = 0, z = 0;
			forn (j, K) {
				if (s[j] == 0) {
					x |= (1 << j);
				} else if (s[j] == 1) {
					y |= (1 << j);
				} else if (s[j] == 3) {
					z |= (1 << j);
				}
			}
			ans.pb(mp('&', (1 << K) - 1 - x));
			ans.pb(mp('|', y));
			ans.pb(mp('^', z));
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