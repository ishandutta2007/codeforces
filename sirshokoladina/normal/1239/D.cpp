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
	int n, m;
	vi e[N], f[N];
	
	bool read () {
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, m) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			e[x].pb(y);
			f[y].pb(x);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	vi ans;

	bool take[N];

	void write () {
		if (sz(ans) == 0 || sz(ans) == n) {
			puts("No");
			return;
		}
		forn (i, n) {
			take[i] = 0;
		}
		for (int v : ans) {
			take[v] = 1;
		}
		puts("Yes");
		cout << sz(ans) << ' ' << n - sz(ans) << endl;
		{
			bool first = 1;
			forn (i, n) {
				if (take[i]) {
					if (!first) {
						printf(" ");
					}
					first = 0;
					printf("%d", i + 1);
				}
			}
		}
		puts("");
		{
			bool first = 1;
			forn (i, n) {
				if (!take[i]) {
					if (!first) {
						printf(" ");
					}
					first = 0;
					printf("%d", i + 1);
				}
			}
		}
		puts("");
	}
};


namespace Main {
	
	struct Solution: Data {
		bool u[N];
		vi q;

		void dfs1(int v) {
			if (u[v]) {
				return;
			}
			u[v] = 1;
			for (int to : e[v]) {
				dfs1(to);
			}
			q.pb(v);
		}

		void dfs2(int v) {
			if (u[v]) {
				return;
			}
			u[v] = 1;
			for (int to : f[v]) {
				dfs2(to);
			}
			q.pb(v);
		}
		
		void solve () {
			forn (i, n) {
				u[i] = 0;
			}
			dfs1(0);
			if (sz(q) < n) {
				ans = q;
				return;
			}
			forn (i, n) {
				u[i] = 0;
			}

			dfs2(0);
			forn (i, n) {
				if (!u[i]) {
					ans.pb(i);
				}
			}
		}
		
		void clear () {
			forn (i, n) {
				e[i].clear();
				f[i].clear();
			}
			q.clear();
			ans.clear();
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