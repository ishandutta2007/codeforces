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

const int N = 50;

struct Input {
	int n;
	string s[N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		getline(cin, s[0]);
		forn (i, n) {
			getline(cin, s[i]);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool res;
	string ans[2 * N];
	
	void write () {
		if (!res) {
			puts("NO");
			return;
		}
		puts("YES");
		forn (i, 2 * n - 1) {
			puts(ans[i].c_str());
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	bool bad[N][N];
	
	void solve () {
		forn (i, 2 * n - 1) {
			ans[i] = string(2 * n - 1, '.');
		}
		ans[n - 1][n - 1] = 'o';
		forn (i, n) {
			forn (j, n) {
				bad[i][j] = s[i][j] == 'x';
			}
		}
		forn (di, -n + 1, n) {
			forn (dj, -n + 1, n) {
				if (di == 0 && dj == 0) {
					continue;
				}
				bool ok = 1;
				forn (i, n) {
					forn (j, n) {
						int i_ = i + di;
						int j_ = j + dj;
						if (s[i][j] == 'o' && i_ >= 0 && i_ < n && j_ >= 0 && j_ < n) {
							ok &= s[i_][j_] != '.';
						}
					}
				}
				if (!ok) {
					continue;
				}
				ans[di + n - 1][dj + n - 1] = 'x';
				forn (i, n) {
					forn (j, n) {
						int i_ = i + di;
						int j_ = j + dj;
						if (s[i][j] == 'o' && i_ >= 0 && i_ < n && j_ >= 0 && j_ < n) {
							bad[i_][j_] = 0;
						}
					}
				}
			}
		}
		res = 1;
		forn (i, n) {
			forn (j, n) {
				res &= !bad[i][j];
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