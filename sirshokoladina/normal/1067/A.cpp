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

const int mod = 998244353;
const int N = 100000;
const int K = 200;

struct Input {
	int n;
	int a[N];

	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
			if (a[i] >= 0) {
				--a[i];
			}
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans;

	void write () {
		cout << ans << endl;
	}
};


namespace Main {
	
	struct Solution: Data {
		int d[2][2][K];
		int s[2][K + 1];

		void solve () {
			deepen(0);
			memset(d, 0, sizeof d);
			forn (j, K) {
				if (a[0] == j || a[0] == -1) {
					d[0][0][j] = 1;
				}
			}
			forn (i, 1, n) {
				int i1 = i & 1;
				int i0 = i1 ^ 1;
				forn (t, 2) {
					s[t][0] = 0;
					forn (j, K) {
						s[t][j + 1] = (s[t][j] + d[i0][t][j]) % mod;
						debug(mt(i - 1, t, j + 1, s[t][j + 1]));
					}
				}
				memset(d[i1], 0, sizeof d[i1]);
				forn (j, K) {
					if (a[i] == j || a[i] == -1) {
						d[i1][0][j] = (s[1][j] + s[0][j]) % mod;
						d[i1][1][j] = ((s[1][K] - s[1][j] + mod) % mod + (s[0][j + 1] - s[0][j] + mod) % mod) % mod;
					}
					debug(mt(i, j, d[i1][0][j], d[i1][1][j]));
				}
			}
			ans = 0;
			forn (j, K) {
				ans = (ans + d[(n - 1) & 1][1][j]) % mod;
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