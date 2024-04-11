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

const int N = 400;

struct Input {
	int n, m;
	string s[N];
	
	bool read() {
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, n) {
			cin >> s[i];
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans;

	void write() {
		cout << ans << endl;
	}
};


namespace Main {
	
	struct Solution: Data {
		int a[N][N];
		int si[N + 1][N];
		int sj[N][N + 1];
		int sij[N + 1][N + 1];
		
		void solve() {
			ans = 16;
			forn (j, m) {
				si[0][j] = 0;
			}
			forn (i, n) {
				sj[i][0] = 0;
			}
			forn (j, m + 1) {
				sij[0][j] = 0;
			}
			forn (i, n + 1) {
				sij[i][0] = 0;
			}
			forn (i, n) {
				forn (j, m) {
					a[i][j] = (s[i][j] == '1');
					si[i + 1][j] = si[i][j] + a[i][j];
					sj[i][j + 1] = sj[i][j] + a[i][j];
					sij[i + 1][j + 1] = sij[i + 1][j] + si[i + 1][j];
				}
			}
			forn (il, n + 1) {
				forn (jl, m + 1) {
					forn (ir, il + 5, n + 1) {
						forn (jr, jl + 4, m + 1) {
							int su = (jr - jl - 2) - (sj[il][jr - 1] - sj[il][jl + 1]);
							int sd = (jr - jl - 2) - (sj[ir - 1][jr - 1] - sj[ir - 1][jl + 1]);
							int sl = (ir - il - 2) - (si[ir - 1][jl] - si[il + 1][jl]);
							int sr = (ir - il - 2) - (si[ir - 1][jr - 1] - si[il + 1][jr - 1]);
							int sc = sij[ir - 1][jr - 1] - sij[il + 1][jr - 1] - sij[ir - 1][jl + 1] + sij[il + 1][jl + 1];
							debug(mt(il, jl, ir, jr, su, sl, sr, sd, sc));
							if (su + sl + sc >= ans) {
								break;
							}
							umn(ans, su + sl + sr + sd + sc);
						}
					} 
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