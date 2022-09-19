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

struct Input {
	string s;
	
	bool read () {
		return getline(cin, s) && sz(s);
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	vi ans;
	
	void write () {
		int res = 0;
		forn (i, sz(ans) - 1) {
			res += ans[i + 1] < ans[i];
		}
		cout << res << endl;
		forn (i, sz(ans)) {
			if (i) {
				printf(" ");
			}
			printf("%d", ans[i] + 1);
		}
		puts("");
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	int n;
	int t[N];
	deque<pii> a[2][2];
	int go[N];
	
	void solve () {
		n = sz(s);
		memset(go, -1, sizeof go);
		forn (i, n) {
			t[i] = (s[i] == 'L');
		}
		forn (i, n) {
			bool ok = 0;
			forn (q, 2) {
				if (sz(a[q][!t[i]])) {
					go[a[q][!t[i]].back().sc] = i;
					a[q][t[i]].pb(mp(a[q][!t[i]].back().fs, i));
					a[q][!t[i]].pop_back();
					ok = 1;
					break;
				}
			}
			if (!ok) {
				a[t[i]][t[i]].pb(mp(i, i));
			}
		}
		while (sz(a[0][0]) + sz(a[0][1]) + sz(a[1][0]) + sz(a[1][1]) > 1) {
			debug(go, go + n);
			debug((deque<pii>*)a, (deque<pii>*)a + 4);
			bool ok = 0;
			forn (x, 2) {
				forn (y, 2) {
					forn (z, 2) {
						if (sz(a[x][y]) && sz(a[!y][z]) && (mp(x, y) != pii(!y, z) || sz(a[x][y]) >= 2)) {
							go[a[x][y].front().sc] = a[!y][z].back().fs;
							int st = a[x][y].front().fs;
							int fn = a[!y][z].back().sc;
							a[x][y].pop_front();
							a[!y][z].pop_back();
							a[x][z].pb(mp(st, fn));
							ok = 1;
						}
					}
				}
			}
			if (ok) {
				debug("ok");
				continue;
			}
			debug("not");
			deque<pii> &p = a[0][1];
			deque<pii> &q = a[1][0];
			int x = p.back().fs, y = p.back().sc;
			int z = q.back().fs, w = q.back().sc;
			p.pop_back();
			q.pop_back();
			if (x > z) {
				swap(x, z);
				swap(y, w);
			}
			int f = go[x];
			go[x] = z;
			a[t[x]][t[w]].pb(mp(x, w));
			a[t[f]][t[y]].pb(mp(f, y));
			debug("1");
		}
		debug();
			debug(go, go + n);
			debug((deque<pii>*)a, (deque<pii>*)a + 4);
		debug();
		int st = -1;
		forn (x, 2) {
			forn (y, 2) {
				if (sz(a[x][y])) {
					st = a[x][y].back().fs;
				}
			}
		}
		while (st != -1) {
			debug(st);
			ans.pb(st);
			st = go[st];
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
	sol.read();
	sol.solve();
	sol.write();
#endif
	return 0;
}