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
const int X = 100000;

struct Input {
	int n;
	int a[2];
	int v[N], p[N], t[N];
	
	bool read () {
		if (!(cin >> n >> a[0] >> a[1])) {
			return 0;
		}
		forn (i, n) {
			char c;
			scanf("%d%d %c", &v[i], &p[i], &c);
			t[i] = (c == 'D');
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans;
	
	void write () {
		cout << ans << endl;
	}
};


namespace Main {
	const int inf = 1000000000;
	
	struct Solution: Data {
		int mx[2][X + 1];
		int mx2[2][X + 1];
		
		void solve () {
			ans = 0;
			forn (i, X + 1) {
				mx[0][i] = mx[1][i] = -inf;
				mx2[0][i] = mx2[1][i] = -inf;
			}
			forn (i, n) {
				if (mx[t[i]][p[i]] <= v[i]) {
					mx2[t[i]][p[i]] = mx[t[i]][p[i]];
					mx[t[i]][p[i]] = v[i];
				}
			}
			forn (i, X) {
				umx(mx[0][i + 1], mx[0][i]);
				umx(mx[1][i + 1], mx[1][i]);
				umx(mx2[0][i + 1], mx[0][i]);
				umx(mx2[1][i + 1], mx[1][i]);
			}
			debug(mx[0], mx[0] + 15);
			debug(mx[1], mx[1] + 15);
			debug(mx2[0], mx2[0] + 15);
			debug(mx2[1], mx2[1] + 15);
			umx(ans, mx[0][a[0]] + mx[1][a[1]]);
			forn (i, n) {
				if (p[i] <= a[t[i]]) {
					umx(ans, v[i] + min(mx[t[i]][a[t[i]] - p[i]], mx2[t[i]][p[i]]));
					debug(mt(i, p[i], v[i], t[i], a[t[i]], v[i] + min(mx[t[i]][a[t[i]] - p[i]], mx2[t[i]][p[i]])));
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