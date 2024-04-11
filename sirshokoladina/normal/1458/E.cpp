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
	int n, m;
	int x[N], y[N], a[N], b[N];
	
	bool read() {
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d%d", &x[i], &y[i]);
		}
		forn (i, m) {
			scanf("%d%d", &a[i], &b[i]);
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool ans[N];

	void write() {
		forn (i, m) {
			puts(ans[i] ? "WIN" : "LOSE");
		}
	}
};


namespace Main {
	
	struct Solution: Data {
		int ordn[N], ordm[N];
		
		void solve() {
			iota(ordn, ordn + n, 0);
			iota(ordm, ordm + m, 0);
			sort(ordn, ordn + n, [&](int i, int j) {
				return mp(x[i], y[i]) < mp(x[j], y[j]);
			});
			sort(ordm, ordm + m, [&](int i, int j) {
				return mp(a[i], b[i]) < mp(a[j], b[j]);
			});

			int cur_line = -1;
			int last_y = 0;
			int pos = 0;
			set<int> q;

			auto print = [&]() {
				debug(mt(cur_line, last_y, pos, q));
			};

			auto go = [&](int cur_x, int cur_y) {
				if (cur_line != cur_x) {
					int cnt_skip = cur_x - cur_line;
					if (last_y != -1) {
						--cnt_skip;
					}
					while (sz(q) && *q.begin() - pos <= cnt_skip) {
						cnt_skip -= *q.begin() - pos;
						pos = *q.begin() + 1;
						q.erase(q.begin());
					}
					pos += cnt_skip;
					cur_line = cur_x;
					last_y = -1;
				}
				if (last_y == -1) {
					while (sz(q) && *q.begin() == pos && *q.begin() < cur_y) {
						pos++;
						q.erase(q.begin());
					}
					if (pos < cur_y) {
						last_y = pos;
						++pos;
					}
				}
				debug(mt(cur_x, cur_y));
				print();
			};

			{
				deepen();
				print();
			}
			int j = 0;
			forn (i, m) {
				while (j < n && mp(x[ordn[j]], y[ordn[j]]) <= mp(a[ordm[i]], b[ordm[i]])) {
					debug(mt(x[ordn[j]], y[ordn[j]]));
					deepen();
					go(x[ordn[j]], y[ordn[j]]);
					last_y = y[ordn[j]];
					if (last_y >= pos) {
						q.insert(last_y);
					}
					print();
					++j;
				}
				{
					debug(mt(a[ordm[i]], b[ordm[i]]));
					deepen();
					go(a[ordm[i]], b[ordm[i]] + 1);
					ans[ordm[i]] = (last_y != b[ordm[i]]);
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