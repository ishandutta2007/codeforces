#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
#else
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
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
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

struct Input {
	ld a, b, c, d;
	
	bool read () {
		return cin >> a >> b >> c >> d;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ld ans;
	
	void write () {
		cout << ans << endl;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	void solve () {
		debug(mt(a, b, c, d));
		ans = 10e9;
		forn (i, 16) {
			ld sa = bool(i & 1) * 2 - 1;
			ld sb = bool(i & 2) * 2 - 1;
			ld sc = bool(i & 4) * 2 - 1;
			ld sd = bool(i & 8) * 2 - 1;
			ld ka = sa * sd - sb * sc;
			ld kb = sa * d + a * sd - sb * c - b * sc;
			ld kc = a * d - b * c;
			debug(mt(ka, kb, kc));
			if (fabsl(ka) < 0.5) {
				if (fabsl(kb) < 0.5) {
					if (fabsl(kc) < 0.5) {
						ans = 0;
					} else {
					}
				} else {
					umn(ans, fabsl(-kc / kb));
				}
			} else {
				ld kd = kb * kb - 4 * ka * kc;
				if (kd < -0.5) {
				} else {
					umx(kd, 0);
					forn (j, 2) {
						ld t = 2 * j - 1;
						ld x = (-kb + t * sqrtl(kd)) / (2 * ka);
						umn(ans, fabsl(x));
					}
				}
			}
		}
	}
	
	void clear () {
		*this = Solution();
	}
};

Solution sol;

int main () {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);
#ifdef SG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
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
	return 0;
}