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

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 200000;
const int K = 5;

struct Input {
	int n, k, b, c;
	int t[N];
	
	bool read () {
		if (!(cin >> n >> k >> b >> c)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &t[i]);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ll ans;
	
	void write () {
		cout << ans << endl;
	}
};

struct Solution: Data {
	vi v[K];
	int lb[K], rb[K];
	
	ll calc (ll x) {
		return x / 5 * b + x % 5 * c;
	}
	
	void solve () {
		deepen(0);
		umn(b, 5 * c);
		sort(t, t + n, greater<int>());
		forn (i, n) {
			v[(t[i] % K + K) % K].pb(t[i]);
		}
		ans = ll(1e18);
		debug(t, t + n);
		debug(v, v + K);
		forn (r, K) {
			debug(r);
			deepen();
			int cnt = 0;
			ll sum = 0;
			forn (i, K) {
				lb[i] = rb[i] = 0;
			}
			int pr = 0;
			forn (i, n - k + 1) {
				int cur = t[i];
				debug();
				deepen();
				debug(mt(i, cur, cnt, sum));
				debug(lb, lb + K);
				debug(rb, rb + K);
				while ((cur % K + K) % K != r) {
					++cur;
				}
				sum -= (pr - cur) / 5 * 1ll * b * cnt;
				while (cnt < k) {
					int bst = -1;
					ll mn = ll(1e18);
					forn (j, K) {
						if (rb[j] < sz(v[j]) && umn(mn, calc(cur - v[j][rb[j]]))) {
							bst = j;
						}
					}
					sum += mn;
					cnt++;
					rb[bst]++;
				}
				debug(mt(i, cur, cnt, sum));
				debug(lb, lb + K);
				debug(rb, rb + K);
				umn(ans, sum);
				int num = (t[i] % K + K) % K;
				if (lb[num] != rb[num]) {
					sum -= calc(cur - v[num][lb[num]]);
					cnt--;
					lb[num]++;
				} else {
					rb[num]++;
					lb[num]++;
				}
				pr = cur;
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
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);
	sol.read();
	sol.solve();
	sol.write();
#endif
	return 0;
}