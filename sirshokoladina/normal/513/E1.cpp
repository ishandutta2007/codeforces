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

const int N = 30000;
const int K = 200;
const int X = 10000;

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
	int ans;
	
	void write () {
		cout << ans << endl;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	static const int inf = 1000000000;
	
	int s[N + 1];
	int d[2][2 * K + 1][3][3];
	
	void solve () {
		s[0] = 0;
		forn (i, n) {
			s[i + 1] = s[i] + a[i];
		}
		forn (i, 2 * k + 1) {
			forn (l1, 3) {
				forn (l2, 3) {
					d[0][i][l1][l2] = -inf;
				}
			}
		}
		d[0][0][1][1] = 0;
		forn (i, n + 1) {
			int i0 = i & 1;
			int i1 = i0 ^ 1;
			memcpy(d[i1], d[i0], sizeof d[i1]);
			//debug(i + 1);
			forn (j, 2 * k) {
				if (j & 1) {
					forn (l1, 3) {
						forn (l2, 3) {
							umx(d[i1][j + 1][l1][l2], d[i0][j][l1][l2] + (l2 - l1) * s[i]);
						}
					}
				} else {
					forn (l0, 3) {
						forn (l1, 3) {
							forn (l2, 3) {
								umx(d[i1][j + 1][l1][l2], d[i1][j][l0][l1] - (l2 - l1) * s[i]);
							}
						}
					}
				}
				//forn (l1, 3) {
				//	debug(d[i1][j + 1][l1], d[i1][j + 1][l1] + 3);
				//}
				//debug();
			}
		}
		ans = -inf;
		forn (l, 3) {
			umx(ans, d[(n + 1) & 1][2 * k][l][1]);
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