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

const int N = 100000;
const int K = 5;

struct Input {
	int n, k;
	ll a[N], b[N], c[N];
	
	bool read () {
		if (!(cin >> n >> k)) {
			return 0;
		}
		forn (i, n) {
			int a_, b_, c_;
			scanf("%d%d%d", &a_, &b_, &c_);
			a[i] = a_;
			b[i] = b_;
			c[i] = c_;
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ve<pii> ans;
	
	void write () {
		if (!sz(ans)) {
			puts("NO");
			return;
		}
		puts("YES");
		cout << sz(ans) << endl;
		forn (i, sz(ans)) {
			printf("%d %d\n", ans[i].fs + (ans[i].fs != -1), ans[i].sc + (ans[i].sc != -1));
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	static const int T = 500;
	
	bool rec(int k, const vi &v) {
		debug(mp(k, v));
		deepen();
		if (sz(v) <= k) {
			forn (i, sz(v)) {
				ans.pb(mp(v[i], -1));
			}
			return 1;
		}
		int x = 0, y = 1;
		map<pa<pll, ll>, pa<int, pii> > qqq;
		int t = 0;
		forn (i, T) {
			++t;
			do {
				ll q = a[v[x]] * b[v[y]] - a[v[y]] * b[v[x]];
				if (!q) {
					break;
				}
				ll px = c[v[x]] * b[v[y]] - c[v[y]] * b[v[x]];
				ll py = a[v[x]] * c[v[y]] - a[v[y]] * c[v[x]];
				ll d = __gcd(__gcd(q, px), py);
				q /= d;
				px /= d;
				py /= d;
				if (q < 0) {
					q = -q;
					px = -px;
					py = -py;
				}
				auto &val = qqq[mp(mp(px, py), q)];
				val.fs++;
				val.sc = mp(v[x], v[y]);
			} while (0);
			x = (x + 1) % sz(v);
			y += !x;
			y = (y + 1) % sz(v);
			if (x == y) {
				break;
			}
		}
		debug(qqq);
		for (const auto &p : qqq) {
			if (p.sc.fs * k * k * 2 < t) {
				continue;
			}
			if (k == 1 && p.sc.fs != t) {
				continue;
			}
			int cnt = 0;
			forn (i, sz(v)) {
				if (a[v[i]] * p.fs.fs.fs + b[v[i]] * p.fs.fs.sc == c[v[i]] * p.fs.sc) {
					cnt++;
				}
			}
			debug(cnt);
			if (cnt * k >= sz(v)) {
				ans.pb(p.sc.sc);
				vi w;
				forn (i, sz(v)) {
					if (a[v[i]] * p.fs.fs.fs + b[v[i]] * p.fs.fs.sc != c[v[i]] * p.fs.sc) {
						w.pb(v[i]);
					}
				}
				if (rec(k - 1, w)) {
					return 1;
				}
				ans.pop_back();
			}
		}
		return 0;
	}
	
	void solve () {
		vi v;
		forn (i, n) {
			v.pb(i);
		}
		random_shuffle(all(v));
		rec(k, v);
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
	sol.read();
	sol.solve();
	sol.write();
#endif
	return 0;
}