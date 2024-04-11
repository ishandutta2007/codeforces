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
typedef unsigned int ui;
typedef unsigned char uc;
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
	bool res;
	int ans[N];
	
	void write () {
		if (!res) {
			puts("NO");
			return;
		}
		puts("YES");
		forn (i, n) {
			printf("%d\n", ans[i]);
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	ll d[N];
	
	void solve () {
		if (n == 1) {
			res = 1;
			ans[0] = 1;
			return;
		}
		if (n == 2) {
			res = 1;
			ans[0] = 1;
			ans[1] = 2;
			return;
		}
		if (n == 4) {
			res = 1;
			ans[0] = 1;
			ans[1] = 3;
			ans[2] = 2;
			ans[3] = 4;
			return;
		}
		{
			for (int i = 2; i * i <= n; ++i) {
				if (n % i == 0) {
					res = 0;
					return;
				}
			}
		}
		res = 1;
		int root = 2;
		while (1) {
			bool ok = 1;
			ll pw = 1;
			forn (i, n - 2) {
				(pw *= root) %= n;
				if (pw == 1) {
					ok = 0;
					break;
				}
			}
			if (ok) {
				break;
			}
			++root;
		}
		d[0] = 1;
		forn (i, n - 1) {
			d[i + 1] = d[i] * root % n;
		}
		forn (i, n - 1) {
			if (i & 1) {
				ans[i] = d[i];
			} else {
				ans[i] = d[n - 1 - i];
			}
		}
		ans[n - 1] = n;
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