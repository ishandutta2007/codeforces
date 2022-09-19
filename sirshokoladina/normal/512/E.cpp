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

const int N = 1000;

struct Input {
	int n;
	bool e0[N][N], e1[N][N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		memset(e0, 0, sizeof e0);
		memset(e1, 0, sizeof e1);
		forn (i, n - 3) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			e0[x][y] = 1;
			e0[y][x] = 1;
		}
		forn (i, n - 3) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			e1[x][y] = 1;
			e1[y][x] = 1;
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
		cout << sz(ans) << endl;
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
	ve<pii> make (bool e[N][N], bool q) {
		forn (i, n) {
			e[i][(i + 1) % n] = e[(i + 1) % n][i] = 1;
		}
		ve<pii> res;
		forn (i, 1, n - 2) {
			while (!e[0][i + 1]) {
				int j = i + 2;
				while (!e[0][j]) {
					++j;
				}
				int k = i + 1;
				while (!e[i][k] || !e[j][k]) {
					++k;
				}
				e[i][j] = e[j][i] = 0;
				e[0][k] = e[k][0] = 1;
				res.pb(q ? mp(0, k) : mp(i, j));
			}
		}
		return res;
	}
	
	void solve () {
		ve<pii> a0 = make(e0, 0);
		ve<pii> a1 = make(e1, 1);
		forn (i, sz(a0)) {
			ans.pb(a0[i]);
		}
		ford (i, sz(a1)) {
			ans.pb(a1[i]);
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