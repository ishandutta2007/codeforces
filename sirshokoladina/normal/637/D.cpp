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

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 200000;
const ll X = 1000000000;

struct Input {
	int n;
	ll m, s, q;
	ll a[N];
	
	bool read () {
		if (!(cin >> n >> m >> s >> q)) {
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
	ve<pil> ans;
	
	void write () {
		if (!sz(ans)) {
			puts("IMPOSSIBLE");
			return;
		}
		forn (i, sz(ans)) {
			printf("%s %" PRId64 "\n", ans[i].fs ? "JUMP" : "RUN", ans[i].sc);
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	
	void solve () {
		sort(a, a + n);
		if (a[0] < s + 1) {
			ans.clear();
			return;
		}
		if (a[0] > 1) {
			ans.pb(mp(0, a[0] - 1));
		}
		int lst = 0;
		forn (i, n) {
			if (i == n - 1 || a[i + 1] - a[i] >= s + 2) {
				ll jump = a[i] - a[lst] + 2;
				if (jump > q) {
					ans.clear();
					return;
				}
				ans.pb(mp(1, jump));
				ll run = (i == n - 1 ? m : a[i + 1] - 1) - (a[i] + 1);
				if (run > 0) {
					ans.pb(mp(0, run));
				}
				lst = i + 1;
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
	freopen((problemname + ".in").c_str(), "r", stdin);
//	freopen((problemname + ".out").c_str(), "w", stdout);
	while (sol.read()) {
		sol.solve();
		sol.write();
		sol.clear();
		debug();
	}
#else
	sol.read();
	sol.solve();
	sol.write();
#endif
	return 0;
}