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

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define forv(i,v) for (auto i = v.begin(); i != v.end(); ++i)
#define forr(i,v) for (auto i = v.end(); i != v.begin() && (--i, 1); )
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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T> inline T abs (T x) {return x > T() ? x : -x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 1000;
const int M = 1000;

struct Input {
	int n, m;

	bool read () {
		return cin >> n >> m;
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
	ld f[N + 1];
	ld f_[N + 1];
	ld f__[N + 1];

	ld c (int n, int k) {
		if (n < 0 || k < 0 || k > n) {
			return 0;
		}
		return f[n] / f[k] / f[n - k];
	}

	ld c_ (int k) {
		if (k < 0 || k > n * m) {
			return 0;
		}
		return f_[k];
	}

	ld c__ (int k) {
		if (k < 0 || k > n * m - m) {
			return 0;
		}
		return f__[k];
	}

	void solve () {
		f[0] = 1;
		forn (i, N) {
			f[i + 1] = f[i] * (i + 1);
		}
		f_[0] = 1;
		forn (i, N) {
			f_[i + 1] = f_[i] * (n * m - i) / (i + 1);
		}
//		debug(f_, f_ + N + 1);
		f__[0] = 1;
		forn (i, N) {
			f__[i + 1] = f__[i] * (n * m - m - i) / (i + 1);
		}
		ld s = 0;
		forn (i, m + 1) {
			s += n * i * i * c(m, i) * c__(n - i);
		}
		ans = s / c_(n) / n / n;
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