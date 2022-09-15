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

const int N = 300;

struct Input {
	int n;
	string s[N];
	
	bool read() {
		if (!(cin >> n)) {
			return 0;
		}
		getline(cin, s[0]);
		forn (i, n) {
			getline(cin, s[i]);
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	string ans[N];

	void write() {
		forn (i, n) {
			puts(ans[i].c_str());
		}
	}
};


namespace Main {
	
	struct Solution: Data {
		
		void solve() {
			int o[3] = {0, 0, 0};
			int x[3] = {0, 0, 0};
			debug(s, s + n);
			forn (i, n) {
				forn (j, n) {
					if (s[i][j] == 'O') {
						o[(i + j) % 3]++;
					}
					if (s[i][j] == 'X') {
						x[(i + j) % 3]++;
					}
				}
			}
			debug(o, o + 3);
			debug(x, x + 3);
			int bst_o = -1, bst_x = -1;
			int mn = N * N + 1;
			forn (oi, 3) {
				forn (xi, 3) {
					if (oi != xi && umn(mn, o[xi] + x[oi])) {
						bst_o = oi;
						bst_x = xi;
					}
				}
			}
			debug(mt(bst_o, bst_x, mn));
			forn (i, n) {
				ans[i] = s[i];
				forn (j, n) {
					if ((i + j) % 3 == bst_o && ans[i][j] == 'X') {
						ans[i][j] = 'O';
					}
					if ((i + j) % 3 == bst_x && ans[i][j] == 'O') {
						ans[i][j] = 'X';
					}
				}
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