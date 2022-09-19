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
const int Q = 100000;

struct Input {
	int n;
	int a[N], b[N], l[N];
	int q;
	int r[N], w[N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n - 1) {
			scanf("%d%d%d", &a[i], &b[i], &l[i]);
			--a[i];
			--b[i];
		}
		cin >> q;
		forn (i, q) {
			scanf("%d%d", &r[i], &w[i]);
			--r[i];
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ld ans[Q];
	
	void write () {
		forn (i, q) {
			printf("%0.20lf\n", double(ans[i]));
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	vi e[N];
	int cnt[N];
	
	void dfs (int v, int pr) {
		cnt[v] = 1;
		forn (i, sz(e[v])) {
			int to = e[v][i];
			if (to != pr) {
				dfs(to, v);
				cnt[v] += cnt[to];
			}
		}
	}
	
	ld f (int i) {
		int k = min(cnt[a[i]], cnt[b[i]]);
		return (6.l * k * (k - 1) * (n - k) + 6.l * (n - k) * (n - k - 1) * k) / n / (n - 1) / (n - 2);
	}
	
	void solve () {
		forn (i, n - 1) {
			e[a[i]].pb(b[i]);
			e[b[i]].pb(a[i]);
		}
		dfs(0, -1);
		ld cur = 0;
		forn (i, n - 1) {
			cur += f(i) * l[i];
		}
		forn (i, q) {
			cur -= f(r[i]) * (l[r[i]] - w[i]);
			l[r[i]] = w[i];
			ans[i] = cur;
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