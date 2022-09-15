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
const ll mod = 998244353;

struct Input {
	int n;
	vi e[N];
	
	bool read() {
		int m;
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, m) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			e[x].pb(y);
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

	ll pw(ll x, ll n) {
		ll ans = 1;
		while (n) {
			if (n & 1) {
				(ans *= x) %= mod;
			}
			(x *= x) %= mod;
			n >>= 1;
		}
		return ans;
	}

	ll inv(ll x) {
		return pw(x, mod - 2);
	}

	const int M = 512;
	
	struct Solution: Data {
		int val[N];

		int dfs(int v) {
			if (val[v] != -1) {
				return val[v];
			}
			vi q;
			for (int to : e[v]) {
				q.pb(dfs(to));
			}
			sort(all(q));
			q.erase(unique(all(q)), q.end());
			val[v] = 0;
			while (val[v] < sz(q) && q[val[v]] == val[v]) {
				++val[v];
			}
			return val[v];
		}

		ll a[M];

		void fft() {
			for (int k = 1; k < M; k *= 2) {
				forn (i, M) {
					if (i & k) {
						continue;
					}
					ll x = a[i];
					ll y = a[i + k];
					a[i] = (x + y) % mod;
					a[i + k] = (x + mod - y) % mod;
				}
			}
		}
		
		void solve() {
			memset(val, -1, sizeof val);
			forn (i, n) {
				dfs(i);
			}
			memset(a, 0, sizeof a);
			a[0] = n + 1;
			forn (i, n) {
				(a[val[i]] += mod - 1) %= mod;
			}
			fft();
			forn (i, M) {
				a[i] = inv(a[i]);
			}
			fft();
			forn (i, M) {
				(a[i] *= inv(M)) %= mod;
			}
			ans = (mod + 1 - a[0]) % mod;
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