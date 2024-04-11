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
const int D = 60;

struct Input {
	int n;
	ll a[N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%" SCNd64, &a[i]);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool res;
	ve<ll> ans;

	void write () {
		if (!res) {
			puts("No");
			return;
		}
		puts("Yes");
		forn (i, n) {
			if (i) {
				printf(" ");
			}
			printf("%" PRId64, ans[i]);
		}
		puts("");
	}
};


namespace Main {
	
	struct Solution: Data {
		ve<ll> v[D];
		
		void solve () {
			forn (i, n) {
				int mx = 0;
				forn (j, D) {
					if (a[i] & (1ll << j)) {
						mx = j;
					}
				}
				v[mx].pb(a[i]);
			}
			ford (j, D) {
				debug(j);
				debug(ans);
				vi p;
				p.pb(0);
				forn (i, sz(ans)) {
					if (ans[i] & (1ll << j)) {
						p.pb(i + 1);
					}
				}
				debug(p);
				debug(v[j]);
				if (sz(v[j]) > sz(p)) {
					res = false;
					return;
				}
				ve<ll> w;
				int pos = 0;
				forn (i, sz(v[j])) {
					while (pos < p[i]) {
						w.pb(ans[pos++]);
					}
					w.pb(v[j][i]);
				}
				while (pos < sz(ans)) {
					w.pb(ans[pos++]);
				}
				debug(w);
				ans = w;
			}
			res = true;
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