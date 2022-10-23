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

const ll X = 1000000000;

struct Input {
	int n, m;
	ve<tu<int, int, ll>> e;
	
	bool read() {
		if (!(cin >> n >> m)) {
			return 0;
		}
		e.resize(m);
		forn (i, m) {
			cin >> get<0>(e[i]) >> get<1>(e[i]) >> get<2>(e[i]);
			--get<0>(e[i]);
			--get<1>(e[i]);
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ll ans;

	void write() {
		cout << ans << endl;
	}
};


namespace Main {
	const ll INF = 1000000000;
	
	struct Solution: Data {
		ve<ve<ll>> d;
		
		void solve() {
			debug(e);
			d = ve<ve<ll>>(n, ve<ll>(n, INF));
			forn (i, n) {
				d[i][i] = 0;
			}
			forn (i, m) {
				umn(d[get<0>(e[i])][get<1>(e[i])], 1);
				umn(d[get<1>(e[i])][get<0>(e[i])], 1);
			}
			forn (i, n) {
				forn (j, n) {
					forn (k, n) {
						umn(d[j][k], d[j][i] + d[i][k]);
					}
				}
			}
			forn (i, n) {
				debug(d[i]);
			}
			ans = INF * X;
			forn (i, m) {
				ll l = INF;
				umn(l, d[0][get<0>(e[i])] + d[n - 1][get<1>(e[i])] + 1);
				umn(l, d[0][get<1>(e[i])] + d[n - 1][get<0>(e[i])] + 1);
				forn (j, n) {
					umn(l, d[j][0] + d[j][n - 1] + min(d[j][get<0>(e[i])], d[j][get<1>(e[i])]) + 2);
				}
				if (l < INF) {
					debug(mt(i, e[i], l));
					umn(ans, l * get<2>(e[i]));
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