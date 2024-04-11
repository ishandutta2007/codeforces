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

const int N = 1000100;

struct Input {
	int n;
	int tp[N], t[N], x[N];
		
	bool read () {
		if (scanf("%d", &n) != 1)
			return 0;
		forn(i, n) {
			scanf("%d%d%d", &tp[i], &t[i], &x[i]);
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
		forn(i, sz(ans)) {
			printf("%d\n", ans[i]);
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct seg_tree {
	int sz;
	vi t;
	
	seg_tree(){}
	seg_tree(int n) {
		sz = 1;
		while(sz < n) sz <<= 1;
		t.assign(2 * sz, 0);
	}
	
	int fnd(int i, int x, int y, int l, int r) {
		if (x > r || y < l)
			return 0;
		if (x >= l && y <= r) {
			return t[i];
		}
		return fnd(2 * i, x, (x + y) >> 1, l, r) + fnd(2 * i + 1, ((x + y) >> 1) + 1, y, l, r);
	}
	
	void upd(int v, int k) {
		v += sz;
		while (v > 0) {
			t[v] += k;
			v >>= 1;
		}
	}
};


struct Solution: Data {
	seg_tree st[N];
	
	map<int, int> m;
	int ord[N];
	int cnt;
	ve<pii> r[N];
	
	void solve () {
		forn(i, n) {
			ord[i] = x[i];
		}	
		sort(ord, ord + n);
		cnt = 0;
		for (int i = 0; i < n;) {
			int j = i;
			for (; j < n && ord[i] == ord[j]; ++j);
			m[ord[i]] = cnt++;
			i = j;
		}
		forn(i, n) {
			x[i] = m[x[i]];
			r[x[i]].pb(mp(t[i], i));
		}
		forn(i, cnt) {
			sort(all(r[i]));
			int tek = 0;
			for (int j = 0; j < sz(r[i]);) {
				int k = j;
				for (; k < sz(r[i]) && r[i][k].fs == r[i][j].fs; ++k) {
					t[r[i][k].sc] = tek;
				}
				tek++;
				j = k;
			}	
			st[i] = seg_tree(tek);
		}
		forn(i, n) {
			if (tp[i] == 1) {
				st[x[i]].upd(t[i], 1);
			} else if (tp[i] == 2) {
				st[x[i]].upd(t[i], -1);
			} else {
				ans.pb(st[x[i]].fnd(1, 0, st[x[i]].sz - 1, 0, t[i])); 
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
    sol.read();
    sol.solve();
	sol.write();
#endif
	return 0;
}