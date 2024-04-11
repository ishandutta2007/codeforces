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

struct Input {
	int n;
	int a[N];
	
	bool read () {
		if (!(cin >> n)) {
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
	ll ans;
	
	void write () {
		cout << ans << endl;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	int gcd[N];
	
	bool ok[N];
	int b[N + 1];
	int c[N + 1];
	
	void calc (int d) {
		debug(d);
		int k = n / d;
		forn (r, d) {
			int mx = 0;
			forn (i, k) {
				umx(mx, a[i * d + r]);
			}
			debug(mt(r, mx));
			forn (i, k) {
				ok[i * d + r] = (mx == a[i * d + r]);
			}
		}
		debug(ok, ok + n);
		int num0 = -1;
		forn (i, n) {
			if (!ok[i]) {
				num0 = i;
			}
		}
		if (num0 == -1) {
			debug(1);
			forn (i, n) {
				b[i] = n;
			}
		} else {
			rotate(ok, ok + num0, ok + n);
			debug(ok, ok + n);
			memset(c, 0, sizeof c);
			for (int l = 0; l < n; ) {
				if (!ok[l]) {
					l++;
					continue;
				}
				int r = l;
				while (r < n && ok[r]) {
					++r;
				}
				c[r - l]++;
				debug(mt(l, r));
				l = r;
			}
			b[n] = 0;
			int s = 0;
			ford (i, n) {
				s += c[i];
				b[i] = b[i + 1] + s;
			}
		}
		forn (i, 1, n) {
			if (gcd[i] == d) {
				ans += b[i];
			}
		}
	}
	
	void solve () {
		forn (i, 1, n) {
			gcd[i] = __gcd(i, n);
		}
		ans = 0;
		forn (d, 1, n) {
			if (n % d == 0) {
				calc(d);
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
	}
#else
	sol.read();
	sol.solve();
	sol.write();
#endif
	return 0;
}