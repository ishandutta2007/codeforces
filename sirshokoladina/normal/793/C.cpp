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
	int n;
	int xl, xr, yl, yr;
	int ax[N], ay[N], vx[N], vy[N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		scanf("%d%d%d%d", &xl, &yl, &xr, &yr);
		forn (i, n) {
			scanf("%d%d%d%d", &ax[i], &ay[i], &vx[i], &vy[i]);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ld ans;
	
	void write () {
		if (ans < -0.5) {
			puts("-1");
			return;
		}
		cout << ans << endl;
	}
};


namespace Main {
	const ld eps = 1e-10;
	
	struct Solution: Data {
		
		void solve () {
			ans = 0;
			forn (i, n) {
				if (vx[i] > 0) {
					umx(ans, ld(xl - ax[i]) / vx[i]);
				}
				if (vx[i] < 0) {
					umx(ans, ld(xr - ax[i]) / vx[i]);
				}
				if (vy[i] > 0) {
					umx(ans, ld(yl - ay[i]) / vy[i]);
				}
				if (vy[i] < 0) {
					umx(ans, ld(yr - ay[i]) / vy[i]);
				}
			}
			
			debug(ans);
			
			ld t = ans + eps / 2;
			
			forn (i, n) {
				ld x = ax[i] + vx[i] * t;
				ld y = ay[i] + vy[i] * t;
				if (x < xl + eps / 4 || x > xr - eps / 4) {
					ans = -1;
					return;
				}
				if (y < yl + eps / 4 || y > yr - eps / 4) {
					ans = -1;
					return;
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