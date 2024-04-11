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
	int a, b, c, d;
	int k[N];
	
	bool read () {
		if (!(cin >> a >> b >> c >> d >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &k[i]);
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
		int num[X + 1];
	
		int calc (int x, int y) {
			vi v;
			forn (i, 1, x + 1) {
				v.pb((x + i - 1) / i);
			}
			sort(all(v));
			v.erase(unique(all(v)), v.end());
			forn (i, sz(v)) {
				num[v[i]] = i;
			}
			
			vi d(sz(v), inf);
			d.back() = y;
			
			debug(mt(x, y, v, d));
			
			forn (i, n + 1) {
				if (d[0] == 1) {
					return i;
				}
				
				if (i == n) {
					return inf;
				}
				
				forn (j, sz(d)) {
					if (d[j] == inf) {
						continue;
					}
					umn(d[num[(v[j] + k[i] - 1) / k[i]]], d[j]);
					umn(d[j], (d[j] + k[i] - 1) / k[i]);
				}
			}
		}
		
		void solve () {
			deepen(0);
			sort(k, k + n, greater<int>());
			ans = min(calc((a + c - 1) / c, (b + d - 1) / d), calc((b + c - 1) / c, (a + d - 1) / d));
			if (ans == inf) {
				ans = -1;
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