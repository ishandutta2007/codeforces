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

struct Input {
	int n;
	vi e[N];
	
	bool read() {
		int m;
		if (scanf("%d%d", &n, &m) != 2) {
			return 0;
		}
		forn (i, m) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			e[x].pb(y);
		} 
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	vi ans;

	void write() {
		printf("%d\n", sz(ans));
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
	
	struct Solution: Data {
		int f[N];
		int can[N];
		
		void solve() {
			forn (i, n) {
				f[i] = 0;
				can[i] = 1;
			}
			forn (i, n) {
				forn (j, sz(e[i])) {
					f[e[i][j]]++;
				}
			}
			vi q;
			forn (i, n) {
				if (!f[i]) {
					q.pb(i);
				}
			}
			forn (i, sz(q)) {
				int v = q[i];
				debug(mt(v, can[v]));
				if (can[v] & 4) {
					can[v] = 0;
					ans.pb(v);
				}
				for (int to : e[v]) {
					--f[to];
					can[to] |= can[v] << 1;
					if (!f[to]) {
						q.pb(to);
					}
				}
			}
		}
		
		void clear() {
			forn (i, n) {
				e[i].clear();
			}
			ans.clear();
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