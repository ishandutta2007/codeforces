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
const int M = 200000;

struct Input {
	int n, m;
	ll l[N], r[N];
	ll a[M];
	
	bool read () {
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, n) {
			scanf("%" SCNd64 "%" SCNd64, &l[i], &r[i]);
		}
		forn (i, m) {
			scanf("%" SCNd64, &a[i]);
		}
		return 1;
	}
	
	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool ans;
	int mt[N - 1];
	
	void write () {
		if (!ans) {
			puts("No");
			return;
		}
		puts("Yes");
		forn (i, n - 1) {
			if (i) {
				printf(" ");
			}
			printf("%d", mt[i] + 1);
		}
		puts("");
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	void solve () {
		vector<pa<pll, int> > v;
		forn (i, n - 1) {
			v.pb(mp(mp(r[i + 1] - l[i], l[i + 1] - r[i]), i));
		}
		sort(all(v));
		set<pli> s;
		forn (i, m) {
			s.insert(mp(a[i], i));
		}
		debug(v);
		debug(s);
		forn (i, sz(v)) {
			auto it = s.lower_bound(mp(v[i].fs.sc, -1));
			if (it == s.end() || it->fs > v[i].fs.fs) {
				ans = 0;
				return;
			}
			mt[v[i].sc] = it->sc;
			s.erase(it);
		}
		ans = 1;
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