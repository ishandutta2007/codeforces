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
const ll X = 1000000;

struct Input {
	int n;
	ll t[N];
	int h[N];
	vi e[N];

	bool read() {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%" SCNd64, &t[i]);
		}
		forn (i, n) {
			scanf("%d", &h[i]);
		}
		forn (i, n - 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			e[x].pb(y);
			e[y].pb(x);
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
	ll inf = 2 * N * X;
	
	struct Solution: Data {

		tu<ll, ll, ll> rec(int v, int pr) {
			debug(mt(v, pr));
			ll res_no = inf, res_l = inf, res_g = inf;
			ll tot = 0;
			ve<ll> diffs;
			for (int to : e[v]) {
				if (to == pr) {
					continue;
				}
				auto cur = rec(to, v);
				tot += get<1>(cur);
				diffs.pb(get<2>(cur) - get<1>(cur));
			}
			sort(all(diffs));
			forn (i, sz(diffs) + 1) {
				umn(res_no, tot + max(i, sz(diffs) - i) * t[v]);
				umn(res_l, tot + max(i + 1, sz(diffs) - i) * t[v]);
				umn(res_g, tot + max(i, sz(diffs) - i + 1) * t[v]);
				if (i < sz(diffs)) {
					tot += diffs[i];
				}
			}
			if (pr != -1 && h[pr] > h[v]) {
				res_g = inf;
			}
			if (pr != -1 && h[pr] < h[v]) {
				res_l = inf;
			}
			return mt(res_no, res_l, res_g);
		}
		
		void solve() {
			ans = get<0>(rec(0, -1));
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