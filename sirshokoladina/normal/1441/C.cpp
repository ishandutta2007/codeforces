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

// typedef long double ld;
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

const int N = 3000;
const ll inf = ll(1e18);

struct Input {
	int n, k;
	ve<ll> a[N];
	
	bool read() {
		if (!(cin >> n >> k)) {
			return 0;
		}
		forn (i, n) {
			int l;
			scanf("%d", &l);
			forn (j, l) {
				int x;
				scanf("%d", &x);
				a[i].pb(x);
			}
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
		ve<ll> uni(const ve<ll> &d, const ve<ll> &v) {
			assert(sz(d) == k + 1);
			ve<ll> res = d;
			int s = sz(v);
			ll sum = accumulate(all(v), 0ll);
			forn (i, k + 1 - s) {
				umx(res[i + s], d[i] + sum);
			}
			//debug(mt(d, v, res));
			return res;
		}

		void calc(int lb, int rb, const ve<ll> &val) {
			deepen();
			debug(mt(lb, rb, val));
			if (lb + 1 == rb) {
				debug();
				umx(ans, val[k]);
				debug(mt("!!!", lb, val[k]));
				ll sum = 0;
				forn (i, sz(a[lb])) {
					sum += a[lb][i];
					if (i + 1 > k) {
						break;
					}
					debug(mt("!!!", lb, i, sum + val[k - 1 - i]));
					umx(ans, val[k - 1 - i] + sum);
				}
				return;
			}
			int md = (lb + rb) / 2;
			debug(md);
			{
				ve<ll> nval = val;
				forn (i, md, rb) {
					debug(i);
					nval = uni(nval, a[i]);
					debug(i);
				}
				debug();
				calc(lb, md, nval);
				debug();
			}
			{
				ve<ll> nval = val;
				forn (i, lb, md) {
					debug(i);
					nval = uni(nval, a[i]);
					debug(i);
				}
				calc(md, rb, nval);
			}
		}

		void solve() {
			ans = -inf;
			ve<ll> val(k + 1, -inf);
			val[0] = 0;
			calc(0, n, val);
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