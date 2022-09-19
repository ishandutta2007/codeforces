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
const int K = 100000;

typedef pa<ll, int> cost;
cost operator + (cost a, cost b) {
	return cost(a.fs + b.fs, a.sc + b.sc);
}

struct Input {
	int n, k;
	ve<pa<int, cost> > e[N];
	pa<int, cost> t[K];
	
	bool read () {
		int m;
		if (!(cin >> n >> m >> k)) {
			return 0;
		}
		forn (i, m) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			--x;
			--y;
			e[x].pb(mp(y, mp(z, -1)));
			e[y].pb(mp(x, mp(z, -1)));
		}
		forn (i, k) {
			int x, z;
			scanf("%d%d", &x, &z);
			--x;
			e[x].pb(mp(0, mp(z, 0)));
			e[0].pb(mp(x, mp(z, 0)));
			t[i] = mp(x, mp(z, 0));
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans;
	
	void write () {
		cout << ans << endl;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	cost d[N];
	set<pa<cost, int> > q;
	
	void solve () {
		sort(t, t + k);
		int k1 = unique(t, t + k) - t;
		ans = k - k1;
		k = k1;
		forn (i, n) {
			d[i] = mp(1e18, 0);
		}
		d[0] = mp(0, 0);
		forn (i, n) {
			q.insert(mp(d[i], i));
		}
		forn (i, n) {
			int v = q.begin()->sc;
			q.erase(q.begin());
			forn (i, sz(e[v])) {
				cost cur = d[e[v][i].fs];
				if (umn(d[e[v][i].fs], d[v] + e[v][i].sc)) {
					q.erase(mp(cur, e[v][i].fs));
					q.insert(mp(d[e[v][i].fs], e[v][i].fs));
				}
			}
		}
		debug(d, d + n);
		forn (i, k) {
			if (t[i].sc > d[t[i].fs]) {
				++ans;
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