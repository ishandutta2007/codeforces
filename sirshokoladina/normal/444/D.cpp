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

const int N = 50000;
const int M = 100000;

const int INF = 1000000000;

struct Input {
	string s;
	int m;
	string t1[M], t2[M];

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool read () {
		if (!(getline(cin, s))) {
			return 0;
		}
		cin >> m;
		string t;
		getline(cin, t);
		forn (i, m) {
			getline(cin, t);
			stringstream in(t);
			in >> t1[i] >> t2[i];
		}
		return 1;
	}

	int ans[M];
	
	void write () {
		forn (i, m) {
			printf("%d\n", (ans[i] >= INF) ? -1 : ans[i]);
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	static const int L = (N + 63) / 64;
	
	struct mask {
		ull a[L];

		void put (int i) {
			a[i >> 6] |= 1ull << (i & 63);
		}

		bool get (int i) {
			return a[i >> 6] & (1ull << (i & 63));
		}
	};
	
	int calc1 (const mask &p1, const mask &p2) {
		int ans = INF;
		int j = 0;
		forn (i, L) {
			if (p1.a[i]) {
				while (j < L && (j <= i || !p2.a[j])) {
					if (j == i && p2.a[j]) {
						ull x = p1.a[i];
						ull y = p2.a[j];
						if (x & y) {
							return 0;
						}
						int d = 1;
						int k = 0;
						bool bad = 0;
						while (1) {
							ull x1 = x | (x << (1 << k));
							if (y & x1) {
								break;
							}
							if (x == x1) {
								bad = 1;
								break;
							}
							d += 1 << k;
							x = x1;
							++k;
						}
						if (!bad) {
							ford (l, k) {
								ull x1 = x | (x << (1 << l));
								if (y & x1) {
									continue;
								}
								d += 1 << l;
								x = x1;
							}
							umn(ans, d);
						}
					}
					++j;
				}
				if (j < L) {
					umn(ans, 1 + __builtin_clzll(p1.a[i]) + 64 * (j - i - 1) + __builtin_ctzll(p2.a[j]));
				}
			}
		}
		debug(mt(ve<ll>(p1.a, p1.a + 2), ve<ll>(p2.a, p2.a + 2), ans));
		return ans;
	}
	
	int calc (const mask &p1, const mask &p2, int l1, int l2) {
		return max(l1, calc1(p1, p2) + l2);
	}
	
	mask p[26][4];
	mask p1, p2;

	map<pa<string, string>, int> mem;
	
	void solve () {
		debug(s);
		memset(p, 0, sizeof p);
		forn (i, sz(s)) {
			forn (j, 4) {
				if (j <= i) {
					p[s[i] - 'a'][j].put(i - j);
				}
			}
		}
		forn (i, m) {
			if (mem.count(mp(t1[i], t2[i]))) {
				ans[i] = mem[mp(t1[i], t2[i])];
				continue;
			}
			memset(&p1, -1, sizeof p1);
			memset(&p2, -1, sizeof p2);
			forn (j, sz(t1[i])) {
				forn (k, L) {
					p1.a[k] &= p[t1[i][j] - 'a'][j].a[k];
				}
			}
			forn (j, sz(t2[i])) {
				forn (k, L) {
					p2.a[k] &= p[t2[i][j] - 'a'][j].a[k];
				}
			}
			ans[i] = min(calc(p1, p2, sz(t1[i]), sz(t2[i])), calc(p2, p1, sz(t2[i]), sz(t1[i])));
			mem[mp(t1[i], t2[i])] = mem[mp(t2[i], t1[i])] = ans[i];
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