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

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 150000;
const int X = 150000;

struct Input {
	int n;
	int a[N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
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

struct Solution: Data {
	vi bad;
	
	bool check_ok (int i) {
		if (i < 0 || i >= n - 1) {
			return 1;
		}
		if (i % 2 == 0) {
			return a[i] < a[i + 1];
		} else {
			return a[i] > a[i + 1];
		}
	}
	
	bool check (int i, int j) {
		for (int x : bad) {
			if (x != i && x + 1 != i && x != j && x + 1 != j) {
				return 0;
			}
		}
		bool res = 1;
		swap(a[i], a[j]);
		res &= check_ok(i - 1);
		res &= check_ok(i);
		res &= check_ok(j - 1);
		res &= check_ok(j);
		swap(a[i], a[j]);
		return res;
	}
	
	ll calc (int i) {
		ll res = 0;
		forn (j, n) {
			if (i != j) {
				res += check(i, j);
			}
		}
		return res;
	}
	
	ll tree[X + 1];
	
	void add (int pos, int val) {
		for (++pos; pos <= X; pos = (pos | (pos - 1)) + 1) {
			tree[pos] += val;
		}
	}
	
	ll sum (int pos) {
		ll res = 0;
		for (; pos; pos &= pos - 1) {
			res += tree[pos];
		}
		return res;
	}
	
	int lb[N], rb[N], md[N];

	void solve () {
		forn (i, n - 1) {
			if (!check_ok(i)) {
				bad.pb(i);
			}
		}
		if (sz(bad)) {
			ans = calc(bad[0]) + calc(bad[0] + 1) - check(bad[0], bad[0] + 1);
			return;
		}
		forn (i, n) {
			md[i] = a[i];
			lb[i] = 0;
			rb[i] = X;
			if (i % 2 == 0) {
				if (i > 0) {
					umn(rb[i], a[i - 1]);
				}
				if (i < n - 1) {
					umn(rb[i], a[i + 1]);
				}
			} else {
				if (i > 0) {
					umx(lb[i], a[i - 1] + 1);
				}
				if (i < n - 1) {
					umx(lb[i], a[i + 1] + 1);
				}
			}
		}
		ve<pii> q;
		forn (i, n) {
			q.pb(mp(rb[i] * 3 + 0, i));
			q.pb(mp(lb[i] * 3 + 1, i));
			q.pb(mp(md[i] * 3 + 2, i));
		}
		memset(tree, 0, sizeof tree);
		forn (i, sz(q)) {
			if (q[i].fs % 3 == 0) {
				add(md[q[i].sc], -1);
			}
			if (q[i].fs % 3 == 1) {
				add(md[q[i].sc], 1);
			}
			if (q[i].fs % 3 == 2) {
				ans += sum(rb[q[i].sc]) - sum(lb[q[i].sc]);
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