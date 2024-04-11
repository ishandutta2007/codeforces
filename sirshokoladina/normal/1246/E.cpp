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
 
const int N = 16;
const int X = 2000;
 
struct Input {
	int n, k;
	int a[N];
	
	bool read() {
		if (!(cin >> n >> k)) {
			return 0;
		}
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
	ve<pii> ans;
	
	void write() {
		if (!sz(ans)) {
			cout << "NO" << endl;
			return;
		}
		cout << "YES" << endl;
		forn (i, sz(ans)) {
			cout << ans[i].fs << ' ' << ans[i].sc << endl;
		}
	}
};
 
 
namespace Main {
	
	struct Solution: Data {
		uc pr[1 << N][X + 1];
		int p[N];
 
		
		void solve() {
			debug();
			memset(pr, -1, sizeof pr);
			pr[0][0] = 0;
			forn (msk, 1 << n) {
				ford (x, X + 1) {
					if (x % k || int(pr[msk][x]) == uc(-1)) {
						continue;
					}
					pr[msk][x / k] = uc(pr[msk][x] + N);
				}
				forn (x, X + 1) {
					if (int(pr[msk][x]) == uc(-1)) {
						continue;
					}
					forn (i, n) {
						if (msk & (1 << i)) {
							continue;
						}
						pr[msk + (1 << i)][x + a[i]] = uc(i);
					}
				}
			}
			if (int(pr[(1 << n) - 1][1]) == uc(-1)) {
				return;
			}
			int cnt = 0;
			int msk = (1 << n) - 1;
			int x = 1;
			while (msk) {
				debug(mt(msk, x));
				int i = pr[msk][x] % N;
				int d = pr[msk][x] / N;
				debug(mt(i, d));
				int y = x;
				forn (j, d) {
					y *= k;
				}
				y -= a[i];
				cnt += d;
				p[i] = cnt;
				msk -= 1 << i;
				x = y;
			}
			debug(p, p + n);
			ve<pii> v;
			forn (i, n) {
				v.pb(a[i], p[i]);
			}
			while (sz(v) > 1) {
				bool done = 0;
				forn (i, sz(v)) {
					forn (j, i) {
						if (v[i].sc == v[j].sc) {
							ans.pb(v[i].fs, v[j].fs);
							int s = v[i].fs + v[j].fs;
							int d = v[i].sc;
							while (s % k == 0) {
								s /= k;
								d--;
							}
							v.erase(v.begin() + i);
							v.erase(v.begin() + j);
							v.pb(s, d);
							done = 1;
							break;
						}
					}
					if (done) {
						break;
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