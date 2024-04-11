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

const int N = 100000;
const int C = 26;

struct Input {
	string s;
	
	bool read() {
		return !!getline(cin, s) && sz(s);
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ll ans;

	void write() {
		cout << ans << endl;
	}
};


namespace Main {

	const int L = 17;
	
	struct Solution: Data {
		vi pos[C];
		int l[N], r[N];
		int cl[N], cr[N];
		int bl[N + 1], br[N + 1];
		int lm[N], rm[N];
		int mxr[N];
		int lk[L][N], rk[L][N];
		ll sl[L][N], sr[L][N];
		int cnt[C];
		
		void solve() {
			forn (i, sz(s)) {
				pos[s[i] - 'a'].pb(i);
			}
			forn (c, C) {
				forn (i, sz(pos[c])) {
					l[pos[c][i]] = (i == 0) ? 0 : pos[c][i - 1];
					r[pos[c][i]] = (i == sz(pos[c]) - 1) ? sz(s) - 1 : pos[c][i + 1];
				}
			}
			forn (i, sz(s)) {
				cl[i] = i;
				cr[i] = i;
			}
			forn (m, 1, C + 1) {
				{
					memset(cnt, 0, sizeof cnt);
					int k = 0;
					int rb = 0;
					int b = -1;
					int dl = 0, dr = 0;
					forn (lb, sz(s)) {
						if (lb > b) {
							b = rb;
							dl = bl[b] = sz(s);
							dr = br[b] = -1;
							ford (i, lb, b) {
								bl[i] = min(bl[i + 1], l[i]);
								br[i] = max(br[i + 1], r[i]);
							}
						}
						while (rb < sz(s)) {
							int &x = cnt[s[rb] - 'a'];
							if (k + !x > m) {
								break;
							}
							umn(dl, l[rb]);
							umx(dr, r[rb]);
							rm[rb] = max(br[lb], dr);
							k += !x;
							++x;
							++rb;
						}
						mxr[lb] = rb;
						lm[lb] = min(bl[lb], dl);
						int &x = cnt[s[lb] - 'a'];
						--x;
						k -= !x;
					}
				}
				forn (i, sz(s)) {
					lk[0][i] = lm[i];
					rk[0][i] = rm[i];
					sl[0][i] = i;
					sr[0][i] = sz(s) - i - 1;
				}
				forn (t, L - 1) {
					forn (i, sz(s)) {
						lk[t + 1][i] = lk[t][lk[t][i]];
						rk[t + 1][i] = rk[t][rk[t][i]];
						sl[t + 1][i] = sl[t][i] + sl[t][lk[t][i]];
						sr[t + 1][i] = sr[t][i] + sr[t][rk[t][i]];
					}
				}
				forn (i, sz(s)) {
					auto up = [&] (int t) {
						ans += sl[t][cl[i]];
						ans += sr[t][cr[i]];
						cl[i] = lk[t][cl[i]];
						cr[i] = rk[t][cr[i]];
					};
					ford (t, L) {
						if (rk[t][cr[i]] < mxr[lk[t][cl[i]]]) {
							up(t);
						}
					}
					if (cr[i] < mxr[cl[i]]) {
						up(0);
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