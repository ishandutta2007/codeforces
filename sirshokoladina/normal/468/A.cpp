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

const int N = 100000;

struct Input {
	int n;

	bool read () {
		return cin >> n;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool ans;
	int a[N - 1], b[N - 1], c[N - 1];
	char op[N - 1];
	
	void write () {
		if (!ans) {
			puts("NO");
			return;
		}
		puts("YES");
		forn (i, n - 1) {
			printf("%d %c %d = %d\n", a[i], op[i], b[i], c[i]);
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	void solve () {
		if (n < 4) {
			ans = 0;
			return;
		}
		ans = 1;
		int k = 0;
		if (n & 1) {
			a[k] = 5, op[k] = '-', b[k] = 3, c[k] = 2, ++k;
			a[k] = 1, op[k] = '+', b[k] = 2, c[k] = 3, ++k;
			a[k] = 2, op[k] = '*', b[k] = 3, c[k] = 6, ++k;
			a[k] = 6, op[k] = '*', b[k] = 4, c[k] = 24, ++k;
		} else {
			a[k] = 1, op[k] = '*', b[k] = 2, c[k] = 2, ++k;
			a[k] = 2, op[k] = '*', b[k] = 3, c[k] = 6, ++k;
			a[k] = 6, op[k] = '*', b[k] = 4, c[k] = 24, ++k;
		}
		for (int i = 5 + (n & 1); i <= n; i += 2) {
			a[k] = i + 1, op[k] = '-', b[k] = i, c[k] = 1, ++k;
			a[k] = 24, op[k] = '*', b[k] = 1, c[k] = 24, ++k;
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