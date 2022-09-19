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

const int N = 200000;
const int K = 50;

struct Input {
	int n, k;
	int a[N];
	
	bool read () {
		if (!(cin >> n >> k)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
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
		cout << ans << endl;
	}
};

struct Solution: Data {
	ld s[N + 1];
	ld t[N + 1];
	ld sinv[N + 1];
	
	ld calc (int l, int r) {
		return (t[r] - t[l]) - s[l] * (sinv[r] - sinv[l]);
	}
	
	void make (ld *from, ld *to, int lfrom, int rfrom, int lto, int rto) {
		deepen();
		debug(mp(lto, rto));
		if (lto == rto) {
			return;
		}
		int mto = (lto + rto) / 2;
		debug(mto);
		int mfrom = -1;
		forn (i, lfrom, min(rfrom, mto + 1)) {
			if (umn(to[mto], from[i] + calc(i, mto))) {
				mfrom = i;
			}
		}
		make(from, to, lfrom, mfrom + 1, lto, mto);
		make(from, to, mfrom, rfrom, mto + 1, rto);
	}
	
	ld d[K + 1][N + 1];
	
	void solve () {
		s[0] = 0;
		t[0] = 0;
		sinv[0] = 0;
		forn (i, n) {
			s[i + 1] = s[i] + a[i];
			t[i + 1] = t[i] + s[i + 1] * 1.l / a[i];
			sinv[i + 1] = sinv[i] + 1.l / a[i];
		}
		forn (i, k + 1) {
			forn (j, n + 1) {
				d[i][j] = 1e20l;
			}
		}
		d[0][0] = 0;
		forn (i, k) {
			debug(i);
			make(d[i], d[i + 1], 0, n + 1, 0, n + 1);
		}
		forn (i, k + 1) {
			debug(d[i], d[i] + n + 1);
		}
		ans = d[k][n];
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