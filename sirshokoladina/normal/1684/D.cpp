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

struct Input {
	int n, k;
	vi a;

	bool read() {
		if (!(cin >> n >> k)) {
			return 0;
		}
		a.resize(n);
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
	ll ans;

	void write() {
		cout << ans << endl;
	}
};


namespace Main {

	const ll X = 1e9;
	const ll inf = 1e18;
	
	struct Solution: Data {
		// ve<ll> tmx;
		// ve<ll> tupd;

		// void push(int v, int lb, int rb) {
		// 	if (lb - rb > 1) {
		// 		tupd[2 * v + 1] += tupd[v];
		// 		tupd[2 * v + 2] += tupd[v];
		// 	}
		// 	tmx[v] += tupd[v];
		// 	tupd[v] = 0;
		// }

		// void upd(int v, int lb, int rb, int l, int r, ll val) {
		// 	if (lb >= r || rb <= l) {
		// 		push(v, lb, rb);
		// 		return;
		// 	}
		// 	if (lb >= l && rb <= r) {
		// 		tupd[v] += val;
		// 		push(v, lb, rb);
		// 		return;
		// 	}
		// 	push(v, lb, rb);
		// 	int md = (lb + rb) / 2;
		// 	upd(2 * v + 1, lb, md, l, r, val);
		// 	upd(2 * v + 2, md, rb, l, r, val);
		// 	tmx[v] = max(tmx[2 * v + 1], tmx[2 * v + 2]);
		// }

		// ll get(int v, int lb, int rb, int l, int r) {
		// 	if (lb >= r || rb <= l) {
		// 		return -inf;
		// 	}
		// 	if (lb >= l && rb <= r) {
		// 		return tmx[v];
		// 	}
		// 	push(v, lb, rb);
		// 	int md = (lb + rb) / 2;
		// 	return max(
		// 		get(2 * v + 1, lb, md, l, r),
		// 		get(2 * v + 2, md, rb, l, r)
		// 	);
		// }
		
		void solve() {
			debug(a);
			// tmx.resize(4 * n, 0);
			// tupd.resize(4 * n, 0);
			// ans = 0;
			// forn (i, n) {
			// 	ans += a[i];
			// 	upd(0, 0, n, i, i + 1, ll(a[i] - (n - i - 1)) * X + i);
			// }
			// forn (i, k) {
			// 	ll number = get(0, 0, n, 0, n);
			// 	ll val = number / X;
			// 	int pos = int((number % X + X) % X);
			// 	debug(mt(val, pos));
			// 	if (val <= 0) {
			// 		break;
			// 	}
			// 	ans -= val;
			// 	upd(0, 0, n, 0, pos, X);
			// 	upd(0, 0, n, pos, pos + 1, -inf);
			// 	upd(0, 0, n, pos + 1, n, X);
			// }
			ll cur = 0;
			forn (i, n) {
				cur += a[i];
				a[i] -= (n - 1 - i);
			}
			sort(all(a));
			reverse(all(a));
			ans = cur;
			forn (i, k) {
				cur -= a[i] + i;
				umn(ans, cur);
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