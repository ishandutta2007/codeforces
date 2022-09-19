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

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define forv(i,v) for (auto i = v.begin(); i != v.end(); ++i)
#define forr(i,v) for (auto i = v.end(); i != v.begin() && (--i, 1); )
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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T> inline T abs (T x) {return x > T() ? x : -x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 100000;

struct Input {
	int n;
	vi e[N];
	int x[N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		int m;
		cin >> m;
		forn (i, m) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			e[x].pb(y);
			e[y].pb(x);
		}
		forn (i, n) {
			scanf("%d", &x[i]);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool res;
	vi ans;
	
	void write () {
		if (!res) {
			cout << -1 << endl;
			return;
		}
		cout << sz(ans) << endl;
		forn (i, sz(ans)) {
			if (i) {
				printf(" ");
			}
			printf("%d", ans[i] + 1);
		}
		cout << endl;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	int u[N];

	bool fnd (int v) {
		if (u[v]) {
			return 0;
		}
		u[v] = 1;
		if (x[v]) {
			return 1;
		}
		forn (i, sz(e[v])) {
			if (fnd(e[v][i])) {
				return 1;
			}
		}
		return 0;
	}
	
	void make (int v, int pr) {
		if (u[v] == 2) {
			return;
		}
		u[v] = 2;
		forn (i, sz(e[v])) {
			if (u[e[v][i]] == 2) {
				continue;
			}
			ans.pb(v);
			x[v] ^= 1;
			make(e[v][i], v);
		}
		if (pr == -1) {
			if (x[v]) {
				ans.pb(v);
				x[v] ^= 1;
			}
			return;
		}
		ans.pb(v);
		x[v] ^= 1;
		if (x[v]) {
			ans.pb(pr);
			x[pr] ^= 1;
			ans.pb(v);
			x[v] ^= 1;
		}
	}
	
	void solve () {
		bool done = 0;
		memset(u, 0, sizeof u);
		res = 1;
		forn (i, n) {
			if (!u[i]) {
				if (fnd(i)) {
					if (done) {
						res = 0;
						return;
					} else {
						make(i, -1);
						done = 1;
					}
				}
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
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
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