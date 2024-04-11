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

const int N = 200000;

struct Input {
	int n;
	int a[N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans[N];
	
	void write () {
		forn (i, 1, n) {
			if (i > 1) {
				printf(" ");
			}
			printf("%d", ans[i]);
		}
		puts("");
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	
	static const int M = 1 << 18;
	
	int m;
	int lb[2 * M], rb[2 * M], t[2 * M];
	
	void upd (int i, int x) {
		i += m;
		while (i) {
			t[i] += x;
			i /= 2;
		}
	}
	
	int fnd (int l, int r, int v) {
		if (l >= rb[v] || r <= lb[v]) {
			return 0;
		}
		if (l <= lb[v] && r >= rb[v]) {
			return t[v];
		}
		return fnd(l, r, 2 * v) + fnd(l, r, 2 * v + 1);
	}
	
	ve<pii> q;
	
	void solve () {
		m = 1;
		while (m < n) {
			m *= 2;
		}
		memset(t, 0, sizeof t);
		forn (i, m) {
			lb[i + m] = i;
			rb[i + m] = i + 1;
		}
		ford (i, 1, m) {
			lb[i] = lb[2 * i];
			rb[i] = rb[2 * i + 1];
		}
		forn (i, n) {
			q.pb(mp(a[i], i));
		}
		sort(all(q));
		memset(ans, 0, sizeof ans);
		forn (i, sz(q)) {
			upd(q[i].sc, 1);
			for (int j = 1; j < n && q[i].sc * j + 1 < n; ++j) {
				ans[j] += fnd(q[i].sc * j + 1, min((q[i].sc + 1) * j + 1, n), 1);
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