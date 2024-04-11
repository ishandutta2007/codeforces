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

const int N = 25;
const int X = 50000;

struct Input {
	int n;
	int a[2 * N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, 2 * n) {
			cin >> a[i];
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans[2][N];

	void write () {
		forn (i, 2) {
			forn (j, n) {
				if (j) {
					printf(" ");
				}
				printf("%d", ans[i][j]);
			}
			puts("");
		}
	}
};


namespace Main {
	
	struct Solution: Data {
		ui pr[N][(N - 1) * X + 1];
		
		void solve () {
			sort(a, a + 2 * n);
			reverse(a, a + 2 * n);
			memset(pr, -1, sizeof pr);
			pr[0][0] = 0;
			forn (i, 2 * n - 2) {
				ford (j, min(i + 1, n - 1)) {
					forn (s, j * X + 1) {
						if (pr[j][s] != -1u && pr[j + 1][s + a[i]] == -1u) {
							pr[j + 1][s + a[i]] = i;
						}
					}
				}
			}
			int s = accumulate(a, a + 2 * n - 2, 0) / 2;
			while (pr[n - 1][s] == -1u) {
				--s;
			}
			vi v;
			ford (i, n - 1) {
				int j = pr[i + 1][s];
				v.pb(j);
				s -= a[j];
			}
			vi w;
			forn (i, 2 * n - 2) {
				if (!count(all(v), i)) {
					w.pb(i);
				}
			}
			sort(all(v));
			sort(all(w));
			ans[0][0] = a[2 * n - 2];
			ans[1][n - 1] = a[2 * n - 1];
			forn (i, n - 1) {
				ans[0][i + 1] = a[v[n - 2 - i]];
				ans[1][n - 2 - i] = a[w[n - 2 - i]];
			}
		}
		
		void clear () {
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