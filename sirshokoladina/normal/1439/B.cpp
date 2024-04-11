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

struct Input {
	int n, m, k;
	vi e[N];
	
	bool read() {
		if (scanf("%d%d%d", &n, &m, &k) != 3) {
			return 0;
		}
		forn (i, m) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			e[x].pb(y);
			e[y].pb(x);
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int res;
	vi ans;

	void write() {
		if (res == -1) {
			puts("-1");
			return;
		}
		if (res == 1) {
			printf("1 %d\n", sz(ans));
		} else {
			puts("2");
		}
		forn (i, sz(ans)) {
			if (i) {
				printf(" ");
			}
			printf("%d", ans[i] + 1);
		}
		puts("");
	}
};


namespace Main {
	const int X = 500;
	const int Y = 500;
	
	struct Solution: Data {
		int a[N];
		int big_num[N];
		int big_cnt;
		bool b[Y][Y];
		bool del[N];
		bool tmp[N];

		bool check(int v) {
			vi q;
			for (int to : e[v]) {
				if (!del[to]) {
					q.pb(to);
				}
			}
			assert(sz(q) == k - 1);
			for (int x : q) {
				if (big_num[x] == -1) {
					bool ok = 1;
					for (int to : e[x]) {
						tmp[to] = 1;
					}
					for (int y : q) {
						if (y != x && !tmp[y]) {
							ok = 0;
							break;
						}
					}
					for (int to : e[x]) {
						tmp[to] = 0;
					}
					if (!ok) {
						return 0;
					}
				} else {
					for (int y : q) {
						if (y != x && big_num[y] != -1 && !b[big_num[x]][big_num[y]]) {
							return 0;
						}
					}
				}
			}
			return 1;
		}
		
		void solve() {
			if (ll(k) * ll(k - 1) / 2 > m) {
				res = -1;
				return;
			}
			big_cnt = 0;
			forn (i, n) {
				del[i] = 0;
				tmp[i] = 0;
				a[i] = sz(e[i]);
				if (a[i] > X) {
					big_num[i] = big_cnt++;
				} else {
					big_num[i] = -1;
				}
			}
			forn (i, big_cnt) {
				forn (j, big_cnt) {
					b[i][j] = 0;
				}
			}
			forn (i, n) {
				if (big_num[i] != -1) {
					for (int j : e[i]) {
						if (big_num[j] != -1) {
							b[big_num[i]][big_num[j]] = 1;
						}
					}
				}
			}
			debug(big_num, big_num + n);
			forn (i, big_cnt) {
				debug(b[i], b[i] + big_cnt);
			}

			set<pii> st;
			forn (i, n) {
				st.insert(mp(a[i], i));
			}

			while (sz(st)) {
				int v = st.begin()->sc;
				debug(mt(v, a[v]));
				if (a[v] >= k) {
					res = 1;
					for (const auto p : st) {
						ans.pb(p.sc);
					}
					return;
				}
				if (a[v] == k - 1) {
					if (check(v)) {
						res = 2;
						ans.pb(v);
						for (int to : e[v]) {
							if (!del[to]) {
								ans.pb(to);
							}
						}
						assert(sz(ans) == k);
						return;
					}
				}
				st.erase(mp(a[v], v));
				del[v] = 1;
				for (int to : e[v]) {
					if (!del[to]) {
						st.erase(mp(a[to], to));
						a[to]--;
						st.insert(mp(a[to], to));
					}
				}
			}

			res = -1;
			return;
		}
		
		void clear() {
			forn (i, n) {
				e[i] = vi();
			}
			ans = vi();
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