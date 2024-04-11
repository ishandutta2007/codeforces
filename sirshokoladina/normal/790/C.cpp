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

const int N = 75;

struct Input {
	int n;
	string s;
	
	bool read () {
		return !!(cin >> n >> s);
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
};


namespace Main {
	
	struct Solution: Data {
		int d[N + 1][N + 1][N + 1][2];
		int cnt0[N + 1], cnt1[N + 1], cnt2[N + 1];
		
		void solve () {
			deepen(0);
			vi vv, vk, vo;
			cnt0[0] = cnt1[0] = cnt2[0] = 0;
			forn (i, n) {
				cnt0[i + 1] = cnt0[i];
				cnt1[i + 1] = cnt1[i];
				cnt2[i + 1] = cnt2[i];
				if (s[i] == 'V') {
					vv.pb(i);
					++cnt0[i + 1];
				} else if (s[i] == 'K') {
					vk.pb(i);
					++cnt1[i + 1];
				} else {
					vo.pb(i);
					++cnt2[i + 1];
				}
			}
			debug(mt(vv, vk, vo));
			
			memset(d, 1, sizeof d);
			d[0][0][0][0] = 0;
			forn (i, sz(vv) + 1) {
				forn (j, sz(vk) + 1) {
					forn (k, sz(vo) + 1) {
						forn (t, 2) {
							deepen(d[i][j][k][t] <= 4);
							debug(mt(i, j, k, t, d[i][j][k][t]));
							if (i < sz(vv)) {
								umn(d[i + 1][j][k][1], d[i][j][k][t] + max(0, cnt1[vv[i]] - j) + max(0, cnt2[vv[i]] - k));
							}
							if (j < sz(vk) && !t) {
								umn(d[i][j + 1][k][0], d[i][j][k][t] + max(0, cnt0[vk[j]] - i) + max(0, cnt2[vk[j]] - k));
							}
							if (k < sz(vo)) {
								umn(d[i][j][k + 1][0], d[i][j][k][t] + max(0, cnt0[vo[k]] - i) + max(0, cnt1[vo[k]] - j));
							}
						}
					}
				}
			}
			ans = 1000000000;
			forn (t, 2) {
				umn(ans, d[sz(vv)][sz(vk)][sz(vo)][t]);
			}
		}
		
		void clear () {
			*this = Solution();
		}
	};
}


Main::Solution sol;

int main () {
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