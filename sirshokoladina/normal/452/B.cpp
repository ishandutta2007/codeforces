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

struct Input {
	int n, m;

	bool read () {
		return cin >> n >> m;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ve<pii> ans;

	void write () {
		forn (i, sz(ans)) {
			cout << ans[i].fs << ' ' << ans[i].sc << endl;
		}
		debug();
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	set<pii> q;

	void solve () {
		forn (x, min(4, n + 1)) {
			forn (y, min(4, m + 1)) {
				if ((x + 1) * (y + 1) > 4) {
					continue;
				}
				q.insert(mp(x, y));
				q.insert(mp(x, m - y));
				q.insert(mp(n - x, y));
				q.insert(mp(n - x, m - y));
			}
		}
		ld res = 0;
		for (auto p1: q) {
			for (auto p2: q) {
				for (auto p3: q) {
					for (auto p4: q) {
						ve<pii> v = {p1, p2, p3, p4};
						bool ok = 1;
						forn (i, 4) {
							forn (j, i) {
								if (v[i] == v[j]) {
									ok = 0;
								}
							}
						}
						if (!ok) {
							continue;
						}
						ld cur = 0;
						forn (i, 3) {
							cur += sqrtl(sqr(v[i].fs - v[i + 1].fs) + sqr(v[i].sc - v[i + 1].sc));
						}
						if (umx(res, cur)) {
							ans = v;
						}
					}
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