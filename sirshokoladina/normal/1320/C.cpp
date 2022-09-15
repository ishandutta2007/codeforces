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
const int M = 200000;

struct Input {
	int na, nb;
	int a[N], ca[N], b[N], cb[N];
	int m;
	int x[M], y[M], z[M];
	
	bool read() {
		if (!(cin >> na >> nb >> m)) {
			return 0;
		}
		forn (i, na) {
			scanf("%d%d", &a[i], &ca[i]);
		}
		forn (i, nb) {
			scanf("%d%d", &b[i], &cb[i]);
		}
		forn (i, m) {
			scanf("%d%d%d", &x[i], &y[i], &z[i]);
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

	const int S = 4 * N;
	
	struct Solution: Data {
		ll t_mx[S], t_upd[S];

		ll add(int v, int l, int r, int lb, int rb, ll val) {
			if (r <= lb || l >= rb) {
				return t_mx[v];
			}
			if (l >= lb && r <= rb) {
				t_mx[v] += val;
				t_upd[v] += val;
				return t_mx[v];
			}
			t_upd[2 * v + 1] += t_upd[v];
			t_mx[2 * v + 1] += t_upd[v];
			t_upd[2 * v + 2] += t_upd[v];
			t_mx[2 * v + 2] += t_upd[v];
			t_upd[v] = 0;
			int md = (l + r) / 2;
			return t_mx[v] = max(
				add(2 * v + 1, l, md, lb, rb, val),
				add(2 * v + 2, md, r, lb, rb, val)
			);
		}

		void srt(int nx, int x[N], int cx[N]) {
			ve<pii> v;
			forn (i, nx) {
				v.pb(mp(x[i], cx[i]));
			}
			sort(all(v));
			forn (i, nx) {
				x[i] = v[i].fs;
				cx[i] = v[i].sc;
			}
		}

		int ord[M];
		
		void solve() {
			ans = 0 - ca[0] - cb[0];
			memset(t_mx, 0, sizeof t_mx);
			memset(t_upd, 0, sizeof t_upd);
			srt(na, a, ca);
			srt(nb, b, cb);
			debug(a, a + na);
			debug(ca, ca + na);
			debug(b, b + nb);
			debug(cb, cb + nb);
			forn (i, na) {
				add(0, 0, na, i, i + 1, -ca[i]);
			}
			debug(t_mx[0]);
			iota(ord, ord + m, 0);
			sort(ord, ord + m, [&](int i, int j) {
				return y[i] < y[j];
			});
			int j = 0;
			forn (i, nb) {
				while (j < m && y[ord[j]] < b[i]) {
					int from = upper_bound(a, a + na, x[ord[j]]) - a;
					debug(mt(x[ord[j]], y[ord[j]], z[ord[j]]));
					add(0, 0, na, from, na, z[ord[j]]);
					debug(t_mx[0]);
					++j;
				}
				debug(mt(b[i], cb[i], t_mx[0] - cb[i]));
				umx(ans, t_mx[0] - cb[i]);
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