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

const int N = 100000;

struct Input {
	int n;
	bool f[N];
	vi e[N];
	
	bool read () {
		int m, k;
		if (!(cin >> n >> m >> k)) {
			return 0;
		}
		memset(f, 0, sizeof f);
		forn (i, k) {
			int x;
			scanf("%d", &x);
			--x;
			f[x] = 1;
		}
		forn (i, m) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			e[x].pb(y);
			e[y].pb(x);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool ans[N];
	
	void write () {
		int cnt = 0;
		forn (i, n) {
			cnt += ans[i];
		}
		cout << cnt << endl;
		bool first = 1;
		forn (i, n) {
			if (ans[i]) {
				if (!first) {
					printf(" ");
				}
				first = 0;
				printf("%d", i + 1);
			}
		}
		puts("");
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	int d[N];
	ld c[N];
	int when[N];
	
	void solve () {
		forn (i, n) {
			d[i] = sz(e[i]);
			c[i] = 0;
		}
		forn (i, n) {
			if (!f[i]) {
				for (int j : e[i]) {
					if (!f[j]) {
						c[j] += 1. / d[j];
					}
				}
			}
		}
		set<pa<ld, int> > s;
		forn (i, n) {
			if (!f[i]) {
				s.insert(mp(c[i], i));
				when[i] = -1;
			} else {
				when[i] = n;
			}
		}
		ld mx = -1;
		int best = n;
		while (sz(s)) {
			ld cur = s.begin()->fs;
			if (umx(mx, cur)) {
				best = sz(s);
			}
			int i = s.begin()->sc;
			s.erase(s.begin());
			when[i] = sz(s);
			for (int j : e[i]) {
				if (when[j] == -1) {
					s.erase(mp(c[j], j));
					c[j] -= 1. / d[j];
					s.insert(mp(c[j], j));
				}
			}
		}
		forn (i, n) {
			ans[i] = when[i] < best;
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