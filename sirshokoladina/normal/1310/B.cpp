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

const int K = 17;
const int N = 1 << K;
const int inf = 1000000000;

struct Input {
	int k, n;
	bool our[N];
	
	bool read() {
		int m;
		if (!(cin >> k >> m)) {
			return 0;
		}
		n = 1 << k;
		memset(our, 0, sizeof our);
		forn (i, m) {
			int x;
			scanf("%d", &x);
			--x;
			our[x] = 1;
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

		void calc(int d[2][2], int lb, int rb) {
			forn (i, 2) {
				forn (j, 2) {
					d[i][j] = -inf;
				}
			}
			if (rb - lb == 2) {
				int x = our[lb];
				int y = our[lb + 1];
				d[x][y] = d[y][x] = (x || y);
				return;
			}
			assert(rb - lb > 2);

			int l[2][2], r[2][2];
			int md = (lb + rb) / 2;
			calc(l, lb, md);
			calc(r, md, rb);
			forn (lu, 2) {
				forn (ld, 2) {
					forn (ru, 2) {
						forn (rd, 2) {
							int v0 = l[lu][ld] + r[ru][rd];
							for (int wu : {lu, ru}) {
								int fu = lu + ru - wu;
								int v1 = v0 + (lu || ru);
								for (int wd : {ld, rd}) {
									int v2 = v1 + (ld || rd);
									for (int wwd : {fu, wd}) {
										int v3 = v2 + (fu || wd);
										umx(d[wu][wwd], v3);
									}
								}
							}
						}
					}
				}
			}
		}
		
		void solve() {
			int d[2][2];
			calc(d, 0, n);
			ans = -inf;
			forn (i, 2) {
				forn (j, 2) {
					umx(ans, d[i][j] + (i || j));
				}
			}
			assert(ans >= 0);
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
	
	/*
	int t;
	cin >> t;
	forn (i, t) {
		sol.read();
		sol.solve();
		sol.write();
		sol.clear();
	}
	*/
	
	return 0;
}