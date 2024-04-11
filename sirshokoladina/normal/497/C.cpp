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
const int M = 100000;

struct Input {
	int n;
	int a[N], b[N];
	int m;
	int c[M], d[M], k[M];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d%d", &a[i], &b[i]);
		}
		cin >> m;
		forn (i, m) {
			scanf("%d%d%d", &c[i], &d[i], &k[i]);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool res;
	int ans[N];
	
	void write () {
		if (!res) {
			puts("NO");
			return;
		}
		puts("YES");
		forn (i, n) {
			if (i) {
				printf(" ");
			}
			printf("%d", ans[i] + 1);
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
		ve<pa<int, pii> > q;
		forn (i, n) {
			q.pb(mp(b[i], mp(0, i)));
		}
		forn (i, m) {
			q.pb(mp(d[i], mp(1, i)));
		}
		sort(all(q));
		
		set<pii> s;
		forn (i, sz(q)) {
			if (q[i].sc.fs == 0) {
				s.insert(mp(-a[q[i].sc.sc], q[i].sc.sc));
			} else {
				forn (j, k[q[i].sc.sc]) {
					auto it = s.upper_bound(mp(-c[q[i].sc.sc], N));
					if (it == s.begin()) {
						break;
					}
					--it;
					ans[it->sc] = q[i].sc.sc;
					s.erase(it);
				}
			}
		}
		res = s.empty();
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