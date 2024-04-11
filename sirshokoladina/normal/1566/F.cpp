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

const int N = 200000;
const int X = 1000000000;

struct Input {
	int n, m;
	int a[N];
	int l[N], r[N];
	
	bool read() {
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
		}
		forn (i, m) {
			scanf("%d%d", &l[i], &r[i]);
		}
		return 1;
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
	
	struct Solution: Data {
		int min_r[3 * N + 1];

		int pos_a[N], pos_l[N], pos_r[N];
		ll d[N][2];
		
		void solve() {
			sort(a, a + n);

			debug(a, a + n);
			debug(l, l + m);
			debug(r, r + m);

			// 0 - left bound
			// 1 - right bound
			// 2 - point
			ve<pa<int, pii>> v;
			forn (i, m) {
				v.pb(mp(l[i], mp(0, i)));
				v.pb(mp(r[i], mp(1, i)));
			}
			forn (i, n) {
				v.pb(mp(a[i], mp(2, i)));
			}
			sort(all(v));

			debug(v);

			forn (i, sz(v)) {
				if (v[i].sc.fs == 2) {
					pos_a[v[i].sc.sc] = i;
				}
			}

			debug(pos_a, pos_a + n);

			min_r[sz(v)] = m;
			ford (i, sz(v)) {
				min_r[i] = min_r[i + 1];
				if (v[i].sc.fs == 0 && (min_r[i] == m || r[min_r[i]] > r[v[i].sc.sc])) {
					min_r[i] = v[i].sc.sc;
				}
			}

			debug(min_r, min_r + sz(v) + 1);

			forn (i, n) {
				d[i][0] = d[i][1] = 10ll * X;
			}

			int max_l_ = l[0];
			int min_r_ = r[0];
			forn (i, m) {
				umx(max_l_, l[i]);
				umn(min_r_, r[i]);
			}

			ll val_l = max(a[0] - min_r_, 0);
			ll val_r = max(max_l_ - a[n - 1], 0);

			debug(mt(val_l, val_r));

			d[0][0] = 2 * val_l;
			d[0][1] = val_l;
			forn (i, 1, n) {
				for (int j = pos_a[i - 1]; j < pos_a[i]; ++j) {
					int k = min_r[j + 1];
					ll val1 = v[j].fs - a[i - 1];
					ll val2 = 0;
					if (k != m) {
						umx(val2, a[i] - r[k]);
					}
					ll t = min(d[i - 1][0] + val1, d[i - 1][1] + 2 * val1);
					umn(d[i][0], t + 2 * val2);
					umn(d[i][1], t + val2);
				}
			}

			forn (i, n) {
				debug(d[i], d[i] + 2);
			}

			ans = min(d[n - 1][0] + val_r, d[n - 1][1] + 2 * val_r);
		}
		
		void clear() {
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