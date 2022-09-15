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

const int N = 1000;
const ll X = 100000000;

struct Input {
	int n, m;
	ll a[N], b[N];
	vi e[N];
	
	bool read() {
		if (!(cin >> n >> m)) {
			return 0;
		}
		a[0] = b[0] = 0;
		forn (i, 1, n) {
			scanf("%" SCNd64, &a[i]);
			a[i] += 1;
		}
		forn (i, 1, n) {
			scanf("%" SCNd64, &b[i]);
		}
		forn (i, m) {
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
	
	struct Solution: Data {
		bool u[N];
		bool can2[N];
		ll c_sum;
		ll mn;

		bool dfs(int v, int pr, ll cur) {
			if (a[v] > cur) {
				umn(mn, a[v] - cur);
				return 0;
			}
			if (u[v]) {
				return 1;
			}
			u[v] = 1;
			if (!can2[v]) {
				cur += b[v];
			}
			for (int to : e[v]) {
				if (to == pr) {
					continue;
				}
				if (dfs(to, v, cur) && !can2[v]) {
					can2[v] = 1;
					c_sum += b[v];
				}
			}
			return can2[v];
		}
		
		void solve() {
			debug(n);
			debug(a, a + n);
			debug(b, b + n);
			debug(e, e + n);
			ll tot = accumulate(b, b + n, 0ll);
			ans = 0;
			memset(can2, 0, sizeof can2);
			can2[0] = 1;
			c_sum = 0;
			while (1) {
				debug("before:");
				debug(ans);
				debug(can2, can2 + n);
				debug(c_sum);
				mn = X + 10;
				memset(u, 0, sizeof u);
				ll pr_c_sum = c_sum;
				dfs(0, -1, ans + c_sum);
				debug("after:");
				debug(u, u + n);
				debug(mn);
				debug(can2, can2 + n);
				debug(c_sum);
				if (c_sum == tot) {
					return;
				}
				if (c_sum != pr_c_sum) {
					continue;
				}
				ans += mn;
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