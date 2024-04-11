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

const int N = 200100;

struct Input {
	int n, d, h;
		
	bool read () {
		return scanf("%d%d%d", &n, &d, &h) == 3;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ve<pii> ans;
	bool ok;
	
	void write () {
		if (!ok) {
			puts("-1");
		} else {
			forn(i, sz(ans)) {
				printf("%d %d\n", ans[i].fs + 1, ans[i].sc + 1);
			}
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	
	void solve () {
		if (h == d) {
			if (h == 1) {
				if (n == 2) {
					ok = 1;
					ans.pb(mp(0, 1));
				} else {
					ok = 0;
				}
			} else {
				ok = 1;
				forn(i, h) {
					ans.pb(mp(i, i + 1));
				}
				forn(i, n - h - 1) {
					ans.pb(mp(h - 1, i + h + 1));
				}
			}
			return;	
		}
		if (2 * h < d) {
			ok = 0;
			return;
		}
		ok = 1;
		int kol = d - h;
		forn(i, h) {
			ans.pb(mp(i, i + 1));
		}
		forn(i, kol) {
			ans.pb(mp(((i == 0)?(0):(h + i)), h + 1 + i));
		}
		forn(i, n - kol - h - 1) {
			ans.pb(mp(0, i + kol + h + 1));	
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
	freopen((problemname + ".in").c_str(), "r", stdin);
//	freopen((problemname + ".out").c_str(), "w", stdout);
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