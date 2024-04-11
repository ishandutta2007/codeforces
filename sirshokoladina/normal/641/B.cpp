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

const int N = 110;
const int M = 10010;

struct Input {
	int q;
	int n, m;
	int tp[M];
	int r[M], c[M], x[M];
	
	bool read () {
		if (scanf("%d%d%d", &n, &m, &q) != 3) {
			return 0;
		}
		forn(i, q) {
			scanf("%d", &tp[i]);
			if (tp[i] < 3) {
				scanf("%d", &r[i]);
				r[i]--;
			} else {
				scanf("%d%d%d", &r[i], &c[i], &x[i]);
				r[i]--, c[i]--;
			}
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans[N][N];
	
	void write () {
		forn(i, n) {
			forn(j, m) {
				printf("%d ", ans[i][j]);
			}
			puts("");
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

const int inf = 1e9;

struct Solution: Data {
	pii a[N][N];
	
	void solve () {
		forn(i, n)
			forn(j, m)
				ans[i][j] = inf;
		forn(i, n) {
			forn(j, m) {
				a[i][j] = mp(i, j);
			}
		}
		forn(idx, q) {
			if (tp[idx] == 1) {
				pii res = a[r[idx]][0];
				forn(j, m) {
					if (j + 1 < m) {
						a[r[idx]][j] = a[r[idx]][j + 1];
					} else {
						a[r[idx]][j] = res;
					}
				}
			} else if (tp[idx] == 2) {
				pii res = a[0][r[idx]];
				forn(j, n) {
					if (j + 1 < n) {
						a[j][r[idx]] = a[j + 1][r[idx]];
					} else {
						a[j][r[idx]] = res;
					}
				}
			} else {
				ans[a[r[idx]][c[idx]].fs][a[r[idx]][c[idx]].sc] = x[idx];
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