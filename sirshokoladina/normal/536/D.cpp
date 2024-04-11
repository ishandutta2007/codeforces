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
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 2000;

struct Input {
	int n, s, t;
	ve<pil> e[N];
	ll p[N];
	
	bool read () {
		int m;
		if (!(cin >> n >> m >> s >> t)) {
			return 0;
		}
		--s;
		--t;
		forn (i, n) {
			scanf("%" SCNd64, &p[i]);
		}
		forn (i, m) {
			int x, y;
			ll c;
			scanf("%d%d%" SCNd64, &x, &y, &c);
			--x;
			--y;
			e[x].pb(mp(y, c));
			e[y].pb(mp(x, c));
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ll score;
	
	void write () {
		if (score > 0) {
			puts("Break a heart");
		}
		if (score < 0) {
			puts("Cry");
		}
		if (score == 0) {
			puts("Flowers");
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	bool u[N];
	
	void bfs (int v, ll *d) {
		memset(u, 0, sizeof u);
		forn (i, n) {
			d[i] = 1e18;
		}
		d[v] = 0;
		forn (i, n) {
			int bst = 0;
			ll mn = 1e18;
			forn (j, n) {
				if (!u[j] && umn(mn, d[j])) {
					bst = j;
				}
			}
			u[bst] = 1;
			forn (j, sz(e[bst])) {
				umn(d[e[bst][j].fs], d[bst] + e[bst][j].sc);
			}
		}
		ve<ll> w;
		forn (i, n) {
			w.pb(d[i]);
		}
		sort(all(w));
		w.erase(unique(all(w)), w.end());
		forn (i, n) {
			d[i] = lower_bound(all(w), d[i]) - w.begin();
		}
	}
	
	ll ds[N];
	ll dt[N];
	
	ll a[N][N], s[N + 1][N + 1];
	int q[N][N], t[N + 1][N + 1];
	ll d1[N + 1][N + 1], d2[N + 1][N + 1];
	int bst1[N + 1], bst2[N + 1];
	
	void solve () {
		bfs(Data::s, ds);
		bfs(Data::t, dt);
		memset(a, 0, sizeof a);
		memset(q, 0, sizeof q);
		forn (i, n) {
			a[ds[i]][dt[i]] += p[i];
			q[ds[i]][dt[i]]++;
		}
		memset(s, 0, sizeof s);
		memset(t, 0, sizeof t);
		ford (i, n) {
			ford (j, n) {
				s[i][j] = s[i + 1][j] + s[i][j + 1] - s[i + 1][j + 1] + a[i][j];
				t[i][j] = t[i + 1][j] + t[i][j + 1] - t[i + 1][j + 1] + q[i][j];
			}
		}
		forn (i, n + 1) {
			debug(s[i], s[i] + n + 1);
		}
		forn (i, n + 1) {
			debug(t[i], t[i] + n + 1);
		}
		forn (i, n + 1) {
			bst1[i] = bst2[i] = n;
		}
		ford (i, n) {
			ford (j, n) {
				auto f1 = [&] (int _) -> ll {
					return s[_][j] + d2[_][j];
				};
				auto f2 = [&] (int _) -> ll {
					return s[i][_] + d1[i][_];
				};
				if (t[i][j] != t[i + 1][j] && f1(i + 1) < f1(bst1[j])) {
					bst1[j] = i + 1;
				}
				if (t[i][j] != t[i][j + 1] && f2(j + 1) < f2(bst2[i])) {
					bst2[i] = j + 1;
				}
				deepen(i == 0 && j == 0);
				debug(bst1[j]);
				debug(bst2[i]);
				d1[i][j] = s[i][j] - f1(bst1[j]);
				d2[i][j] = s[i][j] - f2(bst2[i]);
			}
		}
		forn (i, n + 1) {
			debug(d1[i], d1[i] + n + 1);
		}
		forn (i, n + 1) {
			debug(d2[i], d2[i] + n + 1);
		}
		score = d1[0][0];
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