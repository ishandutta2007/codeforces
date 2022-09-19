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
	ve<pii> e[N];
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n - 1) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			--x;
			--y;
			e[x].pb(mp(y, z));
			e[y].pb(mp(x, z));
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ll ans;
	int p[N];

	void write () {
		cout << ans << endl;
		forn (i, n) {
			if (i) {
				printf(" ");
			}
			printf("%d", p[i] + 1);
		}
		puts("");
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	int cnt[N];

	void dfs0 (int v, int pr) {
		cnt[v] = 1;
		forn (i, sz(e[v])) {
			if (e[v][i].fs != pr) {
				dfs0(e[v][i].fs, v);
				cnt[v] += cnt[e[v][i].fs];
			}
		}
	}
	
	int root;
	
	static const int D = 300;

	int num[N];

	void dfs1 (int v, int pr, int c, set<int> &s) {
		num[v] = c;
		s.insert(v);
		forn (i, sz(e[v])) {
			if (e[v][i].fs != pr) {
				dfs1(e[v][i].fs, v, c, s);
			}
		}
	}
	
	void solve () {
		dfs0(0, -1);
		forn (i, n) {
			forn (j, sz(e[i])) {
				ll s = min(cnt[i], cnt[e[i][j].fs]);
				ans += min(s, n - s) * e[i][j].sc;
			}
		}
		root = 0;
		while (1) {
			bool done = 0;
			forn (i, sz(e[root])) {
				if (cnt[e[root][i].fs] < cnt[root] && 2 * cnt[e[root][i].fs] > n) {
					root = e[root][i].fs;
					done = 1;
				}
			}
			if (!done) {
				break;
			}
		}
		ve<set<int> > s(sz(e[root]) + 1);
		num[root] = sz(e[root]);
		s.back().insert(root);
		forn (i, sz(e[root])) {
			dfs1(e[root][i].fs, root, i, s[i]);
		}
		ve<set<int> > g((sz(s) + D - 1) / D);
		forn (i, sz(s)) {
			for (auto j: s[i]) {
				g[i / D].insert(j);
			}
		}
		
		set<pii> szs;
		vi ss;
		forn (i, sz(s)) {
			ss.pb((i == sz(s) - 1) ? -2 * N : 2 * sz(s[i]));
			szs.insert(mp(-ss[i], i));
		}

		int n1 = n;
		forn (i, n) {
			if (-szs.begin()->fs == n1 && num[i] != szs.begin()->sc) {
				p[i] = *s[szs.begin()->sc].begin();
			} else {
				p[i] = N;
				forn (j, sz(g)) {
					if (j != num[i] / D || i == root) {
						if (sz(g[j])) {
							umn(p[i], *g[j].begin());
						}
					} else {
						forn (k, min(D, sz(s) - j * D)) {
							if (j * D + k != num[i]) {
								if (sz(s[j * D + k])) {
									umn(p[i], *s[j * D + k].begin());
								}
							}
						}
					}
				}
			}
			szs.erase(mp(-ss[num[i]], num[i]));
			ss[num[i]]--;
			szs.insert(mp(-ss[num[i]], num[i]));
			szs.erase(mp(-ss[num[p[i]]], num[p[i]]));
			ss[num[p[i]]]--;
			szs.insert(mp(-ss[num[p[i]]], num[p[i]]));
			n1--;
			s[num[p[i]]].erase(p[i]);
			g[num[p[i]] / D].erase(p[i]);
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