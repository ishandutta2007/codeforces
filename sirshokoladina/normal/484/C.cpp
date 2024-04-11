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

const int N = 1000000;
const int M = 1000000;

struct Input {
	int n;
	string s;
	int m;
	int k[M], d[M];
	
	bool read () {
		if (!getline(cin, s) || !sz(s)) {
			return 0;
		}
		n = sz(s);
		cin >> m;
		forn (i, m) {
			scanf("%d%d", &k[i], &d[i]);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	string ans[M];
	
	void write () {
		forn (i, m) {
			puts(ans[i].c_str());
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	
	void solve () {
		forn (f, m) {
			vi p(n), q(n);
			ve<pii> qwe;
			forn (i, k[f]) {
				qwe.pb(mp(i % d[f], i));
			}
			sort(all(qwe));
			forn (i, n) {
				p[i] = i;
				if (i < k[f]) {
					q[qwe[i].sc] = i;
				} else {
					q[i] = i;
				}
			}
			int x = n + 1 - k[f];
			deepen(f == 1);
			for (int t = 0; (1 << t) <= x; ++t) {
				debug(mp(p, q));
				vi qq(n);
				forn (i, 1 << t) {
					qq[i] = i;
				}
				forn (i, n - (1 << t)) {
					qq[i + (1 << t)] = q[i] + (1 << t);
				}
				vi pp(n);
				forn (i, 1 << t) {
					pp[i] = i;
				}
				forn (i, n - (1 << t)) {
					pp[i + (1 << t)] = p[i] + (1 << t);
				}
				vi q0 = q;
				if (x & (1 << t)) {
					forn (i, n) {
						p[i] = pp[q0[i]];
					}
				}
				forn (i, n) {
					q[i] = qq[q0[i]];
				}
			}
			debug(mp(p, q));
			ans[f].resize(n);
			forn (i, n) {
				ans[f][p[i]] = s[i];
			}
			s = ans[f];
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