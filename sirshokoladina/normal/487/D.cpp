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
typedef unsigned int ui;
typedef unsigned char uc;
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
const int M = 10;
const int Q = 100000;

struct Input {
	int n, m, q;
	string s[N];
	int rx[Q], ry[Q];
	char rc[Q];
	
	bool read () {
		if (!(cin >> n >> m >> q)) {
			return 0;
		}
		getline(cin, s[0]);
		forn (i, n) {
			getline(cin, s[i]);
		}
		forn (i, q) {
			char c;
			scanf("%c %d %d", &c, &rx[i], &ry[i]);
			--rx[i];
			--ry[i];
			if (c == 'A') {
				rc[i] = 0;
			} else {
				scanf(" %c", &rc[i]);
			}
			string t;
			getline(cin, t);
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
		forn (i, sz(ans)) {
			printf("%d %d\n", ans[i].fs + 1, ans[i].sc + 1);
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	static const int S = 1 << 17;
	int sz;
	typedef ve<pii> item;
	item t[2 * S];
	int rb[2 * S];
	
	bool u[M];
	bool w[M];
	
	pii calc (int x, const string &s, item &res, int i) {
		if (i < 0 || i >= m) {
			return mp(x, i);
		}
		if (w[i]) {
			return res[i] = mp(-2, -2);
		}
		if (u[i]) {
			return res[i];
		}
		u[i] = 1;
		w[i] = 1;
		if (s[i] == '<') {
			res[i] = calc(x, s, res, i - 1);
		} else if (s[i] == '>') {
			res[i] = calc(x, s, res, i + 1);
		} else {
			res[i] = mp(x - 1, i);
		}
		w[i] = 0;
		return res[i];
	}
	
	item make (int x, const string &s) {
		memset(u, 0, sizeof u);
		memset(w, 0, sizeof w);
		item res(m);
		forn (i, m) {
			calc(x, s, res, i);
		}
		debug(s);
		debug(res);
		return res;
	}
	
	item uni (const item &a, const item &b) {
		item res(m);
		forn (i, m) {
			if (b[i].sc >= 0 && b[i].sc < m) {
				res[i] = a[b[i].sc];
			} else {
				res[i] = b[i];
			}
		}
		return res;
	}
	
	void upd (int x) {
		int v = x + sz;
		t[v] = make(x, s[x]);
		while (1) {
			v >>= 1;
			if (!v || rb[v] > n) {
				break;
			}
			t[v] = uni(t[2 * v], t[2 * v + 1]);
		}
	}
	
	item get (int r, int v = 1) {
		if (rb[v] <= r) {
			return t[v];
		}
		if (rb[2 * v] >= r) {
			return get(r, 2 * v);
		}
		return uni(get(r, 2 * v), get(r, 2 * v + 1));
	}
	
	void solve () {
		sz = 1;
		while (sz < n) {
			sz *= 2;
		}
		forn (i, sz) {
			rb[sz + i] = i + 1;
		}
		ford (i, sz) {
			rb[i] = rb[2 * i + 1];
		}
		forn (i, n) {
			t[sz + i] = make(i, s[i]);
		}
		ford (i, sz) {
			if (i && rb[i] <= n) {
				t[i] = uni(t[2 * i], t[2 * i + 1]);
			}
		}
		debug(t + 1, t + 2 * sz);
		forn (i, q) {
			if (rc[i]) {
				s[rx[i]][ry[i]] = rc[i];
				upd(rx[i]);
				debug(t + 1, t + 2 * sz);
			} else {
				ans.pb(get(rx[i] + 1)[ry[i]]);
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