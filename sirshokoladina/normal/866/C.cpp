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

const int N = 50;
const int X = 100;

struct Input {
	int n, s;
	int a[N], b[N];
	double p[N];
	
	bool read () {
		if (!(cin >> n >> s)) {
			return 0;
		}
		forn (i, n) {
			int x;
			scanf("%d%d%d", &a[i], &b[i], &x);
			p[i] = double(x) / 100;
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	double ans;
	
	void write () {
		cout << ans << endl;
	}
};


namespace Main {
	
	struct Solution: Data {
		double c[N * X + 1], d[N * X + 1];
		
		double calc (double x) {
			forn (j, n * X + 1) {
				if (j <= s) {
					c[j] = 1;
					d[j] = 0;
				} else {
					c[j] = 0;
					d[j] = 0;
				}
			}
			ford (i, n) {
				forn (j, i * X + 1) {
					double c1 = c[j + a[i]];
					double d1 = d[j + a[i]];
					if (d1 > c1 * x) {
						c1 = 0;
						d1 = 0;
					}
					d1 += a[i];
					
					double c2 = c[j + b[i]];
					double d2 = d[j + b[i]];
					if (d2 > c2 * x) {
						c2 = 0;
						d2 = 0;
					}
					d2 += b[i];
					
					c[j] = p[i] * c1 + (1 - p[i]) * c2;
					d[j] = p[i] * d1 + (1 - p[i]) * d2;
				}
			}
			return d[0] / c[0];
		}
		
		void solve () {
			ans = 1e10;
			forn (i, 4) {
				ans = calc(ans);
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