#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
#else
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

const int N = 200000;
const int Q = 40000;
const int S = 31;

struct Input {
	int n, q;
	int a[N];
	int l[N], r[N], x[N];
	
	bool read () {
		if (!(cin >> n >> q)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
		}
		forn (i, q) {
			int t;
			scanf("%d%d%d", &t, &l[i], &r[i]);
			--l[i];
			if (t == 1) {
				scanf("%d", &x[i]);
			} else {
				x[i] = -1;
			}
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	vi ans;
	
	void write () {
		forn (i, sz(ans)) {
			printf("%d\n", ans[i]);
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	static const int M = 1 << 18;
	
	void gauss (vi &b) {
		vi a = b;
		debug(a);
		int i = 0;
		forn (t, S) {
			{
				int num = -1;
				forn (j, i, sz(a)) {
					if (a[j] & (1 << t)) {
						num = j;
						break;
					}
				}
				if (num == -1) {
					continue;
				}
				swap(a[i], a[num]);
				swap(b[i], b[num]);
			}
			forn (j, i + 1, sz(a)) {
				if (a[j] & (1 << t)) {
					a[j] ^= a[i];
				}
			}
			++i;
		}
		a.resize(i);
		debug(a);
		b.resize(i);
	}
	
	vi uni (const vi &a, const vi &b) {
		if (!sz(a)) {
			return b;
		}
		if (!sz(b)) {
			return a;
		}
		vi res = a;
		res.insert(res.end(), all(b));
		gauss(res);
		return res;
	}
	
	int m;
	
	vi t[2 * M];
	int u[2 * M];
	
	void push (int v) {
		if (!u[v]) {
			return;
		}
		forn (i, sz(t[v])) {
			t[v][i] ^= u[v];
		}
		if (v < m) {
			u[2 * v] ^= u[v];
			u[2 * v + 1] ^= u[v];
		}
		u[v] = 0;
	}
	
	vi fnd (int l, int r, int lb, int rb, int v) {
		deepen();
		debug(mt(l, r, lb, rb, v));
		push(v);
		if (r <= lb || l >= rb) {
			return vi();
		}
		if (l <= lb && r >= rb) {
			return t[v];
		}
		return uni(
			fnd(l, r, lb, (lb + rb) >> 1, 2 * v),
			fnd(l, r, (lb + rb) >> 1, rb, 2 * v + 1)
		);
	}
	
	void upd (int x, int l, int r, int lb, int rb, int v) {
		deepen();
		debug(mt(x, l, r, lb, rb, v));
		push(v);
		if (r <= lb || l >= rb) {
			return;
		}
		if (l <= lb && r >= rb) {
			u[v] ^= x;
			push(v);
			return;
		}
		upd(x, l, r, lb, (lb + rb) >> 1, 2 * v);
		upd(x, l, r, (lb + rb) >> 1, rb, 2 * v + 1);
		t[v] = uni(t[2 * v], t[2 * v + 1]);
	}
	
	void solve () {
		m = 1;
		while (m < n) {
			m <<= 1;
		}
		debug(m);
		memset(u, 0, sizeof u);
		forn (i, n) {
			t[m + i].pb(2 * a[i] + 1);
		}
		ford (i, 1, m) {
			t[i] = uni(t[2 * i], t[2 * i + 1]);
		}
		debug(t + 1, t + 2 * m);
		forn (i, q) {
			debug(i);
			if (x[i] < 0) {
				vi v = fnd(l[i], r[i], 0, m, 1);
				debug(v);
				forn (i, sz(v)) {
					v[i] /= 2;
				}
				debug(v);
				gauss(v);
				ans.pb(1 << sz(v));
			} else {
				upd(2 * x[i], l[i], r[i], 0, m, 1);
			}
			debug(u + 1, u + 2 * m);
			debug(t + 1, t + 2 * m);
		}
	}
	
	void clear () {
		*this = Solution();
	}
};

Solution sol;

int main () {
	deepen(0);
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);
#ifdef SG
	freopen((problemname + ".in").c_str(), "r", stdin);
//	freopen((problemname + ".out").c_str(), "w", stdout);
	while (sol.read()) {
		sol.solve();
		debug();
		sol.write();
		debug();
		sol.clear();
	}
#else
	sol.read();
	sol.solve();
	sol.write();
#endif
	return 0;
}