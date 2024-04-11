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

const int N = 10000;
const int K = 100;

struct Input {
	int n, k;

	bool read () {
		return cin >> n >> k;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int res;
	int ans[N][4];
	
	void write () {
		cout << res << endl;
		forn (i, n) {
			forn (j, 4) {
				if (j) {
					printf(" ");
				}
				printf("%d", ans[i][j]);
			}
			puts("");
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	bool u[6 * N];

	void solve () {
		res = k * (6 * n - 1);
		memset(u, 0, sizeof u);
		int t = 2;
		forn (i, n) {
			forn (j, 3) {
				ans[i][j] = 6 * i + 1 + 2 * j;
			}
			ans[i][3] = t;
			t += 2;
			while (u[ans[i][3]] || __gcd(ans[i][3], ans[i][0]) != 1 || __gcd(ans[i][3], ans[i][1]) != 1 || __gcd(ans[i][3], ans[i][2]) != 1) {
				ans[i][3] = t;
				t += 2;
				assert(ans[i][3] * k < res);
			}
		}
		forn (i, n) {
			forn (j, 4) {
				ans[i][j] *= k;
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