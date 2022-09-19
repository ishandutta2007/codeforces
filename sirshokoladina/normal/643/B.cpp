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

const int N = 3010;

struct Input {
	int n, k;
	int a, b, c, d;
	
	bool read () {
		if (scanf("%d%d" ,&n, &k) != 2)
			return 0;
		cin >> a >> b >> c >> d;
		a--, b--, c--, d--;
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	vi ans[2];
	bool ok;
	
	void write () {
		if (!ok) {
			puts("-1");
			return;
		}
		forn(i, 2) {
			forn(j, sz(ans[i])) {
				cout << ans[i][j] + 1 << ' ';
			}
			cout << endl;
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {

	void rest(vi& res) {
		forn(i, n) {
			if (i != a && i != b && i != c && i != d) {
				res.pb(i);	
			}
		}
	}
	
	void solve () {
		if (n == 4) {
			ok = 0;
			return;
		}
		if (k < n + 1) {
			ok = 0;
			return;
		}	
		ok = 1;
		ans[0].pb(a);
		ans[0].pb(c);
		rest(ans[0]);
		ans[0].pb(d);
		ans[0].pb(b);
		ans[1].pb(c);
		ans[1].pb(a);
		forn(i, 2, sz(ans[0]) - 2) {
			ans[1].pb(ans[0][i]);
		}
		ans[1].pb(b);
		ans[1].pb(d);
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