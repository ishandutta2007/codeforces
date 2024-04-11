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

const int N = 100000;

struct Input {
	int n;
	int x[2 * N], y[2 * N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d%d", &x[i], &y[i]);
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
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	static const int K = 200;
	
	ll s (int i, int j) {
		return x[i] * 1ll * y[j] - y[i] * 1ll * x[j] - abs(__gcd(x[j] - x[i], y[j] - y[i]));
	}
	
	ld pw[N + 1];
	
	void solve () {
		pw[0] = 1;
		forn (i, N) {
			pw[i + 1] = pw[i] * 2;
		}
		forn (i, n) {
			x[i + n] = x[i];
			y[i + n] = y[i];
		}
		ans = 0;
		if (n - 1 < K) {
			forn (i, n) {
				forn (j, i + 1, i + n - 1) {
					ans += s(i, j) * (pw[n - (j - i + 1)] - 1);
				}
			}
			ans /= pw[n] - 1 - n - n * (n - 1) / 2;
		} else {
			forn (i, n) {
				forn (j, i + 1, i + K) {
					ans += s(i, j) / pw[j - i + 1];
				}
			}
		}
		ans /= 2;
		ans += 1;
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