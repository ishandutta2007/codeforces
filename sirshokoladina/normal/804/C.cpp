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

const int N = 300000;
const int M = 300000;

struct Input {
	int n, m;
	vi a[N];
	vi e[N];
	
	bool read () {
		debug();
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, n) {
			int k;
			scanf("%d", &k);
			a[i].resize(k);
			forn (j, k) {
				scanf("%d", &a[i][j]);
				--a[i][j];
			}
		}
		forn (i, n - 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			e[x].pb(y);
			e[y].pb(x);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans;
	int col[M];
	
	void write () {
		cout << ans << endl;
		forn (i, m) {
			if (i) {
				printf(" ");
			}
			printf("%d", col[i] + 1);
		}
		puts("");
	}
};


namespace Main {
	
	struct Solution: Data {
		bool u[M];

		void dfs (int v, int pr) {
			forn (i, sz(a[v])) {
				if (col[a[v][i]] != -1) {
					u[col[a[v][i]]] = 1;
				}
			}

			int num = 0;
			forn (i, sz(a[v])) {
				if (col[a[v][i]] == -1) {
					while (u[num]) {
						++num;
					}
					col[a[v][i]] = num;
					u[col[a[v][i]]] = 1;
				}
			}

			forn (i, sz(a[v])) {
				u[col[a[v][i]]] = 0;
			}

			forn (i, sz(e[v])) {
				if (e[v][i] == pr) {
					continue;
				}
				dfs(e[v][i], v);
			}
		}
		
		void solve () {
			memset(u, 0, sizeof u);
			memset(col, -1, sizeof col);
			dfs(0, -1);

			forn (i, m) {
				if (col[i] == -1) {
					col[i] = 0;
				}
			}

			ans = 0;
			forn (i, m) {
				umx(ans, col[i] + 1);
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
			debug();
			sol.solve();
			debug();
			sol.write();
			debug();
			sol.clear();
			debug();
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