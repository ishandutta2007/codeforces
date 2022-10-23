#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
#else
	template<typename T> struct outputer;
	struct outputable {};
	#define PRINT(...)
	#define OUTPUT(...)
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
	#define fbegin(...)
	#define fend
	#define pbegin(...)
	#define pend
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
#define pb emplace_back
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

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 100;

struct Input {
	int n;
	vi a;
	
	bool read() {
		if (!(cin >> n)) {
			return 0;
		}
		a.resize(n);
		forn (i, n) {
			cin >> a[i];
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool ans;
	
	void write() {
		cout << (ans ? "Alice" : "Bob") << endl;
	}
};


namespace Main {
	
	struct Solution: Data {
		int d[N + 1][N + 1][2];

		Solution() {
			memset(d, 0, sizeof d);
			forn (i, N + 1) {
				forn (j, N + 1) {
					if (!i && !j) {
						d[i][j][0] = 1;
						d[i][j][1] = 0;
						continue;
					}
					if (i) {
						forn (t, 2) {
							d[i][j][t] |= !d[i - 1][j][(j & 1) ^ t ^ 1];
						}
					}
					if (j) {
						forn (t, 2) {
							d[i][j][t] |= !d[i][j - 1][(j & 1) ^ t ^ 1];
						}
					}
				}
			}
			forn (i, 5) {
				forn (j, 5) {
					debug(mt(i, j, vi(d[i][j], d[i][j] + 2)));
				}
			}
		}
		
		void solve() {
			int cnt[2] = {0, 0};
			forn (i, n) {
				cnt[abs(a[i]) & 1]++;
			}
			ans = d[cnt[0]][cnt[1]][0];
		}
		
		void clear() {
			a.clear();
		}
	};
}


Main::Solution sol;

int main() {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);

	#ifdef SG
		freopen((problemname + ".in").c_str(), "r", stdin);
//		freopen((problemname + ".out").c_str(), "w", stdout);
	#endif
	
	int t;
	cin >> t;
	forn (i, t) {
		sol.read();
		sol.solve();
		sol.write();
		sol.clear();
	}
	
	return 0;
}