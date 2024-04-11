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
const int M = 100000;

struct Input {
	int n, m;
	int g[M], l[M], r[M];
	
	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool read () {
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, m) {
			int t;
			scanf("%d%d%d", &t, &l[i], &r[i]);
			--l[i];
			if (t == 1) {
				scanf("%d", &g[i]);
				--g[i];
			} else {
				g[i] = -1;
			}
		}
		return 1;
	}

	ve<ll> ans;
	
	void write () {
		forn (i, sz(ans)) {
			printf("%I64d\n", ans[i]);
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	static const int D = 300;
	static const int K = 2 * D - 1;
	
	int c[N];
	ll x[N];
	
	int pos[N + 1];
	
	ll s[K];
	int cg[K];
	ll xg[K];
	
	void solve () {
		forn (i, n) {
			c[i] = i;
			x[i] = 0;
		}
		forn (t, (m + D - 1) / D) {
			int ft = t * D;
			int lt = min((t + 1) * D, m);
			vi b;
			for (int i = ft; i < lt; ++i) {
				b.pb(l[i]);
				b.pb(r[i]);
			}
			sort(all(b));
			b.erase(unique(all(b)), b.end());
			forn (i, sz(b)) {
				pos[b[i]] = i;
			}
			memset(cg, -1, sizeof cg);
			memset(xg, 0, sizeof xg);
			memset(s, 0, sizeof s);
			forn (i, sz(b) - 1) {
				for (int j = b[i]; j < b[i + 1]; ++j) {
					s[i] += x[j];
				}
			}
			for (int i = ft; i < lt; ++i) {
				int lb = pos[l[i]];
				int rb = pos[r[i]];
				if (g[i] == -1) {
					ll val = 0;
					for (int j = lb; j < rb; ++j) {
						val += s[j];
					}
					ans.pb(val);
				} else {
					for (int j = lb; j < rb; ++j) {
						if (cg[j] == -1) {
							for (int l = b[j]; l < b[j + 1]; ++l) {
								x[l] += abs(c[l] - g[i]);
								s[j] += abs(c[l] - g[i]);
							}
							cg[j] = g[i];
						} else {
							xg[j] += abs(cg[j] - g[i]);
							s[j] += abs(cg[j] - g[i]) * ll(b[j + 1] - b[j]);
							cg[j] = g[i];
						}
					}
				}
			}
			forn (i, sz(b) - 1) {
				if (cg[i] != -1) {
					for (int j = b[i]; j < b[i + 1]; ++j) {
						c[j] = cg[i];
						x[j] += xg[i];
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