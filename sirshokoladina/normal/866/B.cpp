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

struct Input {
	int n;
	ll s;
	ll k[N], a[N], b[N];
	
	bool read () {
		if (!(cin >> n >> s)) {
			return 0;
		}
		forn (i, n) {
			scanf("%" SCNd64 "%" SCNd64 "%" SCNd64, &k[i], &a[i], &b[i]);
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


namespace Main {
	
	struct Solution: Data {
		ll m;
		ve<pli> v;
		
		ll calc (ll x) {
			ll cnt1 = x * s;
			ll cnt2 = (m - x) * s;
			ll res = 0;
			ford (j, sz(v)) {
				int i = v[j].sc;
				ll k1, k2;
				if (a[i] > b[i]) {
					k1 = min(k[i], cnt1);
					k2 = k[i] - k1;
				} else {
					k2 = min(k[i], cnt2);
					k1 = k[i] - k2;
				}
				res += k1 * a[i] + k2 * b[i];
				cnt1 -= k1;
				cnt2 -= k2;
			}
			return res;
		}
		
		void solve () {
			ll tot = 0;
			forn (i, n) {
				tot += k[i];
				v.pb(mp(abs(a[i] - b[i]), i));
			}
			sort(all(v));
			m = (tot + s - 1) / s;
			
			ll lb = 0;
			ll rb = tot;
			while (lb != rb) {
				ll m1 = (lb + rb) / 2;
				ll m2 = m1 + 1;
				if (calc(m1) < calc(m2)) {
					lb = m2;
				} else {
					rb = m1;
				}
			}
			ans = calc(lb);
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