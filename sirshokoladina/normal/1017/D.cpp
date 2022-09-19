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

const int N = 12;
const int M = 500000;
const int Q = 500000;
const int K = 100;

struct Input {
	int n, m, q;
	int a[N];
	int s[M];
	int t[Q];
	int k[Q];

	int to_bin (ll x) {
		if (!x) {
			return 0;
		}
		return to_bin(x / 10) * 2 + x % 10;
	}

	int read_bin () {
		ll x;
		scanf("%" SCNd64, &x);
		return to_bin(x);
	}
	
	bool read () {
		if (!(cin >> n >> m >> q)) {
			return 0;
		}
		ford (i, n) {
			scanf("%d", &a[i]);
		}
		forn (i, m) {
			s[i] = read_bin();
		}
		forn (i, q) {
			t[i] = read_bin();
			scanf("%d", &k[i]);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans[Q];

	void write () {
		forn (i, q) {
			cout << ans[i] << endl;
		}
	}
};


namespace Main {
	
	struct Solution: Data {
		int d[1 << N][K + 1];
		int lb[K + 1], rb[K + 1];
		
		void solve () {
			memset(d, 0, sizeof d);
			forn (i, m) {
				d[s[i]][0]++;
			}
			forn (i, n) {
				forn (msk, 1 << n) {
					if (msk & (1 << i)) {
						int *la = d[msk - (1 << i)];
						int *ra = d[msk];
						memcpy(lb, la, sizeof lb);
						memcpy(rb, ra, sizeof rb);
						forn (j, K - a[i] + 1) {
							la[j + a[i]] += rb[j];
							ra[j + a[i]] += lb[j];
						}
					}
				}
			}
			forn (msk, 1 << n) {
				forn (j, K) {
					d[msk][j + 1] += d[msk][j];
				}
			}
			forn (i, q) {
				ans[i] = d[(1 << n) - 1 - t[i]][k[i]];
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