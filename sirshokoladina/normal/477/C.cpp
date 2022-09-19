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

const int N = 2000;
const int M = 500;

struct Input {
	string s, t;
	
	bool read () {
		return getline(cin, s) && getline(cin, t);
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans[N + 1];

	void write () {
		forn (i, sz(s) + 1) {
			if (i) {
				printf(" ");
			}
			printf("%d", ans[i]);
		}
		puts("");
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	int r[N + 1];
	int d[N + 1][N + 1];
	
	void solve () {
		forn (i, N + 1) {
			int j = 0;
			r[i] = i;
			while (r[i] < sz(s) && j < sz(t)) {
				j += (s[r[i]] == t[j]);
				r[i]++;
			}
			if (j != sz(t)) {
				r[i] = -1;
			}
		}
		forn (i, N + 1) {
			forn (j, N + 1) {
				d[i][j] = N + 1;
			}
		}
		d[0][0] = 0;
		forn (i, sz(s)) {
			forn (j, sz(s)) {
				umn(d[i + 1][j], d[i][j]);
				if (r[i] != -1) {
					umn(d[r[i]][j + 1], d[i][j] + r[i] - i - sz(t));
				}
			}
		}
		memset(ans, 0, sizeof ans);
		forn (i, sz(s) + 1) {
			for (int j = d[sz(s)][i]; j <= sz(s) - i * sz(t); ++j) {
				umx(ans[j], i);
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