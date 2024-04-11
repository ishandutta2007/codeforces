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
	int n, a, b;
	int x[N];

	bool read () {
		if (!(cin >> n >> a >> b)) {
			return 0;
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
	bool ans;
	bool s[N];

	void write () {
		if (!ans) {
			puts("NO");
			return;
		}
		puts("YES");
		forn (i, n) {
			if (i) {
				printf(" ");
			}
			printf("%d", (int)s[i]);
		}
		puts("");
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	map<int, int> num;
	bool u1[N], u2[N];

	int dfs1 (int v) {
		if (u1[v]) {
			return -1;
		}
		u1[v] = 1;
		if (!num.count(a - x[v])) {
			return 1;
		} else {
			int q = dfs1(num[a - x[v]]);
			if (q != -1) {
				return q;
			}
		}
		if (!num.count(b - x[v])) {
			return 0;
		} else {
			int q = dfs1(num[b - x[v]]);
			if (q != -1) {
				return q;
			}
		}
		return -1;
	}

	bool dfs2 (int v, bool c) {
		if (u2[v]) {
			return 1;
		}
		u2[v] = 1;
		s[v] = c;
		if (!num.count(a - x[v])) {
			if (c == 0) {
				return 0;
			}
		} else {
			if (!dfs2(num[a - x[v]], c)) {
				return 0;
			}
		}
		if (!num.count(b - x[v])) {
			if (c == 1) {
				return 0;
			}
		} else {
			if (!dfs2(num[b - x[v]], c)) {
				return 0;
			}
		}
		return 1;
	}
	
	void solve () {
		forn (i, n) {
			num[x[i]] = i;
		}
		memset(u1, 0, sizeof u1);
		memset(u2, 0, sizeof u2);
		ans = 1;
		forn (i, n) {
			if (!u1[i]) {
				int c = dfs1(i);
				bool ok = dfs2(i, c);
				if (!ok) {
					ans = 0;
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