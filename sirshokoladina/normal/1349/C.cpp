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
const int K = 100000;

struct Input {
	int n, m, k;
	string s[N];
	int x[K], y[K];
	ll t[K];

	bool read() {
		if (!(cin >> n >> m >> k)) {
			return 0;
		}
		getline(cin, s[0]);
		forn (i, n) {
			getline(cin, s[i]);
		}
		forn (i, k) {
			scanf("%d %d %" SCNd64, &x[i], &y[i], &t[i]);
			--x[i];
			--y[i];
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	char ans[K];

	void write() {
		forn (i, k) {
			printf("%c\n", ans[i]);
		}
	}
};


namespace Main {
	const int dx[4] = {-1, 0, 1, 0};
	const int dy[4] = {0, -1, 0, 1};
	
	struct Solution: Data {
		int l[N][N];
		
		void solve() {
			memset(l, -1, sizeof l);
			ve<pii> q;
			forn (i, n) {
				forn (j, m) {
					forn (d, 4) {
						int i1 = i + dx[d];
						int j1 = j + dy[d];
						if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m) {
							if (s[i][j] == s[i1][j1]) {
								l[i][j] = 0;
								q.pb(mp(i, j));
							}
						}
					}
				}
			}
			forn (i, sz(q)) {
				forn (d, 4) {
					int i1 = q[i].fs + dx[d];
					int j1 = q[i].sc + dy[d];
					if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m) {
						if (l[i1][j1] == -1) {
							l[i1][j1] = l[q[i].fs][q[i].sc] + 1;
							q.pb(mp(i1, j1));
						}
					}
				}
			}
			forn (i, n) {
				debug(l[i], l[i] + m);
			}
			forn (i, k) {
				ll r = l[x[i]][y[i]];
				if (r == -1) {
					r = t[i];
				}
				ans[i] = s[x[i]][y[i]];
				if (t[i] >= r) {
					ans[i] ^= (t[i] - r) & 1;
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