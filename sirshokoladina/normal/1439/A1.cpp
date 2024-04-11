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
	int n, m;
	string s[N];
	
	bool read() {
		if (!(cin >> n >> m)) {
			return 0;
		}
		getline(cin, s[0]);
		forn (i, n) {
			getline(cin, s[i]);
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	vector<vector<pii>> ans;

	void write() {
		cout << sz(ans) << endl;
		for (const auto &v : ans) {
			forn (i, sz(v)) {
				if (i) {
					printf(" ");
				}
				printf("%d %d", v[i].fs + 1, v[i].sc + 1);
			}
			puts("");
		}
	}
};


namespace Main {
	
	struct Solution: Data {

		void add(const vector<pii> &v) {
			for (const pii &p : v) {
				s[p.fs][p.sc] ^= 1;
			}
			ans.pb(v);
		}
		
		void solve() {
			ford (i, 2, n) {
				ford (j, 1, m) {
					if (s[i][j] == '1') {
						add({{i, j}, {i - 1, j}, {i - 1, j - 1}});
					}
				}
				if (s[i][0] == '1') {
					add({{i, 0}, {i - 1, 0}, {i - 1, 1}});
				}
			}
			ford (j, 2, m) {
				if (s[0][j] == '1') {
					add({{0, j}, {0, j - 1}, {1, j - 1}});
				}
				if (s[1][j] == '1') {
					add({{1, j}, {1, j - 1}, {0, j - 1}});
				}
			}

			char a[2][2];

			int cnt = 0;
			forn (i, 2) {
				forn (j, 2) {
					a[i][j] = s[i][j];
					cnt += (a[i][j] == '1');
				}
			}
			forn (i, 2) {
				forn (j, 2) {
					if (a[i][j] != '0' + (cnt % 2)) {
						ve<pii> v;
						forn (x, 2) {
							forn (y, 2) {
								if (x != i || y != j) {
									v.pb(x, y);
								}
							}
						}
						add(v);
					}
				}
			}
			forn (i, n) {
				debug(s[i]);
				forn (j, m) {
					assert(s[i][j] == '0');
				}
			}
		}
		
		void clear() {
			*this = Solution();
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