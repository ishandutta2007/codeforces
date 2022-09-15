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

const int N = 200000;
const int K = 9;

struct Input {
	int n, k;
	ve<pii> e[N], re[N];
	
	bool read() {
		int m;
		if (!(cin >> n >> m >> k)) {
			return 0;
		}
		forn (i, m) {
			int x, y, w;
			scanf("%d%d%d", &x, &y, &w);
			--x;
			--y;
			e[x].pb(mp(y, w));
			re[y].pb(mp(x, w));
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans;

	void write() {
		cout << ans << endl;
	}
};


namespace Main {
	const int M = K * (K + 1) / 2;
	
	struct Solution: Data {
		ull f[M];

		void rec(int s, int t, ull u) {
			if (t == 0) {
				++ans;
				return;
			}
			forn (i, s - t, s) {
				ull v = u | f[i];
				if (v & (1ull << i)) {
					continue;
				}
				rec(s - t, t - 1, v);
			}
		}
		
		void solve() {
			forn (i, n) {
				sort(all(e[i]), [](pii x, pii y) {
					return x.sc < y.sc;
				});
			}
			memset(f, 0, sizeof f);
			forn (i, n) {
				vi w;
				debug(i);
				for (auto p : re[i]) {
					int to = p.fs;
					int pos = 0;
					while (e[to][pos].sc != p.sc) {
						++pos;
					}
					debug(mt(to, pos));
					w.pb(sz(e[to]) * (sz(e[to]) - 1) / 2 + pos);
				}
				forn (t, 2) {
					ull s = 0;
					for (int x : w) {
						f[x] |= s;
						s |= 1ull << x;
					}
					reverse(all(w));
				}
			}
			ans = 0;
			rec(k * (k + 1) / 2, k, 0ull);
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