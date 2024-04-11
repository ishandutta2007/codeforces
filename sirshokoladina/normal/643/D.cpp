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
#define pb push_back
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

const int N = 100000;
const int Q = 100000;

struct Input {
	int n, q;
	ll a[N];
	int to[N];
	
	int r_t[Q], r_x[Q], r_y[Q];
	
	bool read () {
		if (!(cin >> n >> q)) {
			return 0;
		}
		forn (i, n) {
			scanf("%" SCNd64, &a[i]);
		}
		forn (i, n) {
			scanf("%d", &to[i]);
			--to[i];
		}
		forn (i, q) {
			scanf("%d", &r_t[i]);
			if (r_t[i] != 3) {
				scanf("%d", &r_x[i]);
				--r_x[i];
				if (r_t[i] != 2) {
					scanf("%d", &r_y[i]);
					--r_y[i];
				}
			}
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ve<ve<ll> > ans;
	
	void write () {
		forn (i, sz(ans)) {
			forn (j, sz(ans[i])) {
				if (j) {
					printf(" ");
				}
				printf("%" PRId64, ans[i][j]);
			}
			puts("");
		}
	}
};

struct Solution: Data {
	int d[N];
	ll x[N], y[N], z[N];
	set<pa<ll, int> > w[N];
	set<pa<ll, int> > smx, smn;
	
	pa<ll, int> calc_mx (int i) {
		if (!sz(w[i])) {
			return mp(-1000000000000000000ll, i);
		}
		return mp((--w[i].end())->fs + y[i], i);
	}
	
	pa<ll, int> calc_mn (int i) {
		if (!sz(w[i])) {
			return mp(1000000000000000000ll, i);
		}
		return mp(w[i].begin()->fs + y[i], i);
	}
	
	pa<ll, int> calc_w (int i) {
		return mp(x[i] + z[i], i);
	}
	
	void solve () {
		memset(d, 0, sizeof d);
		memset(z, 0, sizeof d);
		forn (i, n) {
			d[to[i]]++;
		}
		forn (i, n) {
			y[i] = a[i] / (d[i] + 2);
			x[i] = a[i] - (d[i] + 1) * y[i];
			z[to[i]] += y[i];
		}
		forn (i, n) {
			w[to[i]].insert(calc_w(i));
		}
		forn (i, n) {
			smx.insert(calc_mx(i));
			smn.insert(calc_mn(i));
		}
		
		forn (i, q) {
			if (r_t[i] == 3) {
				ans.pb({smn.begin()->fs, (--smx.end())->fs});
			}
			if (r_t[i] == 2) {
				int v = r_x[i];
				ans.pb({x[v] + z[v] + y[to[v]]});
			}
			if (r_t[i] == 1) {
				int v = r_x[i];
				
				smx.erase(calc_mx(to[v]));
				smn.erase(calc_mn(to[v]));
				smx.erase(calc_mx(to[to[v]]));
				smn.erase(calc_mn(to[to[v]]));
				smx.erase(calc_mx(to[to[to[v]]]));
				smn.erase(calc_mn(to[to[to[v]]]));
					w[to[v]].erase(calc_w(v));
					w[to[to[v]]].erase(calc_w(to[v]));
					w[to[to[to[v]]]].erase(calc_w(to[to[v]]));
						z[to[v]] -= y[v];
						z[to[to[v]]] -= y[to[v]];
							d[to[v]]--;
							y[to[v]] = a[to[v]] / (d[to[v]] + 2);
							x[to[v]] = a[to[v]] - (d[to[v]] + 1) * y[to[v]];
						z[to[to[v]]] += y[to[v]];
					w[to[to[v]]].insert(calc_w(to[v]));
					w[to[to[to[v]]]].insert(calc_w(to[to[v]]));
				smx.insert(calc_mx(to[v]));
				smn.insert(calc_mn(to[v]));
				smx.insert(calc_mx(to[to[v]]));
				smn.insert(calc_mn(to[to[v]]));
				smx.insert(calc_mx(to[to[to[v]]]));
				smn.insert(calc_mn(to[to[to[v]]]));
				
				
				to[v] = r_y[i];
				
				smx.erase(calc_mx(to[v]));
				smn.erase(calc_mn(to[v]));
				smx.erase(calc_mx(to[to[v]]));
				smn.erase(calc_mn(to[to[v]]));
				smx.erase(calc_mx(to[to[to[v]]]));
				smn.erase(calc_mn(to[to[to[v]]]));
					w[to[to[v]]].erase(calc_w(to[v]));
					w[to[to[to[v]]]].erase(calc_w(to[to[v]]));
						z[to[to[v]]] -= y[to[v]];
							d[to[v]]++;
							y[to[v]] = a[to[v]] / (d[to[v]] + 2);
							x[to[v]] = a[to[v]] - (d[to[v]] + 1) * y[to[v]];
						z[to[v]] += y[v];
						z[to[to[v]]] += y[to[v]];
					w[to[v]].insert(calc_w(v));
					w[to[to[v]]].insert(calc_w(to[v]));
					w[to[to[to[v]]]].insert(calc_w(to[to[v]]));
				smx.insert(calc_mx(to[v]));
				smn.insert(calc_mn(to[v]));
				smx.insert(calc_mx(to[to[v]]));
				smn.insert(calc_mn(to[to[v]]));
				smx.insert(calc_mx(to[to[to[v]]]));
				smn.insert(calc_mn(to[to[to[v]]]));
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