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

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int C = 6;
const int N = 6;
const int Q = 36;

struct Input {
	int n, q;
	int a[Q], b[Q], c[Q];
	
	bool read () {
		if (!(cin >> n >> q)) {
			return 0;
		}
		forn (i, q) {
			string s, t;
			cin >> s >> t;
			a[i] = s[0] - 'a';
			b[i] = s[1] - 'a';
			c[i] = t[0] - 'a';
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

struct Solution: Data {
	int x[C + 1][C + 1];
	
	void rec (int l, vi v) {
		if (l == n) {
			int cur = v[0];
			forn (i, 1, n) {
				cur = x[cur][v[i]];
			}
			ans += cur == 0;
			if (cur == 0) {
				debug(v);
			}
			return;
		}
		v.pb(-1);
		forn (t, C) {
			v.back() = t;
			rec(l + 1, v);
		}
	}
	
	void solve () {
		forn (i, C + 1) {
			forn (j, C + 1) {
				x[i][j] = C;
			}
		}
		forn (i, q) {
			x[a[i]][b[i]] = c[i];
		}
		ans = 0;
		rec (0, vi());
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
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);
	sol.read();
	sol.solve();
	sol.write();
#endif
	return 0;
}