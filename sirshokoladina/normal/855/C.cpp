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

const int N = 100000;
const int D = 10;

const ll mod = 1000000007;

struct Input {
	int n, t;
	ll m, k;
	vi e[N];
	
	bool read () {
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, n - 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			e[x].pb(y);
			e[y].pb(x);
		}
		cin >> k >> t;
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ll ans;
	
	void write () {
		cout << ans << endl;
	}
};


namespace Main {
	
	struct Solution: Data {
		ll d[N][D + 1][3];
		
		void dfs (int v, int pr) {
			deepen();
			debug(mt(v, pr));
			memset(d[v], 0, sizeof d[v]);
			d[v][0][0] = k - 1;
			d[v][1][1] = 1;
			d[v][0][2] = m - k;
			for (int to : e[v]) {
				if (to == pr) {
					continue;
				}
				dfs(to, v);
				ford (i, t + 1) {
					ll q[3];
					forn (x, 3) {
						q[x] = d[v][i][x];
					}
					ford (j, t - i + 1) {
						(d[v][i + j][0] += d[v][i][0] * (d[to][j][0] + d[to][j][1] + d[to][j][2])) %= mod;
						(d[v][i + j][1] += d[v][i][1] * (d[to][j][0])) %= mod;
						(d[v][i + j][2] += d[v][i][2] * (d[to][j][0] + d[to][j][2])) %= mod;
					}
					forn (x, 3) {
						(d[v][i][x] += mod - q[x]) %= mod;
					}
				}
			}
			debug(mt(v, pr));
			forn (i, t + 1) {
				debug(d[v][i], d[v][i] + 3);
			}
		}
		
		void solve () {
			debug(e, e + n);
			dfs(0, -1);
			ans = 0;
			forn (i, t + 1) {
				forn (j, 3) {
					(ans += d[0][i][j]) %= mod;
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