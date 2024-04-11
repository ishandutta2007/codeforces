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

const int N = 300000;

struct Input {
	int n;
	int a[2][N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, 2) {
			forn (j, n) {
				scanf("%d", &a[i][j]);
			}
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
	
	struct Solution: Data {
		
		void calc (ll s[N + 1], int p[N + 1]) {
			map<ll, int> lst;
			forn (i, n + 1) {
				if (i == 0) {
					p[i] = -1;
				} else {
					p[i] = p[i - 1];
				}
				int &val = lst[s[i]];
				if (val) {
					umx(p[i], val - 1);
				}
				val = i + 1;
			}
			
			debug(s, s + n + 1);
			debug(p, p + n + 1);
		}
	
		ll s1[N + 1], s2[N + 1], s3[N + 1];
		int p1[N + 1], p2[N + 1], p3[N + 1];
		
		map<pii, int> d;
		
		int calc (int x, int y) {
			deepen();
			debug(mt(x, y));
			int &val = d[mp(x, y)];
			if (val) {
				return val - 1;
			}
			
			val = 0;
			
			if (x || y) {
				
				if (x != y) {
					umx(val, calc(min(x, y), min(x, y)));
				} else {
					if (p3[x] != -1) {
						umx(val, 1 + calc(p3[x], p3[x]));
					}
				}
				if (x >= y) {
					if (p1[x] != -1) {
						umx(val, 1 + calc(p1[x], y));
					}
				}
				if (y >= x) {
					if (p2[y] != -1) {
						umx(val, 1 + calc(x, p2[y]));
					}
				}
				
			}
			
			debug(mt(x, y, val));
			
			++val;
			
			return val - 1;
		}
		
		void solve () {
			s1[0] = s2[0] = s3[0] = 0;
			forn (i, n) {
				s1[i + 1] = s1[i] + a[0][i];
				s2[i + 1] = s2[i] + a[1][i];
				s3[i + 1] = s3[i] + a[0][i] + a[1][i];
			}
			calc(s1, p1);
			calc(s2, p2);
			calc(s3, p3);
			ans = calc(n, n);
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
	deepen(0);

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