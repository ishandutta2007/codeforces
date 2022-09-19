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
typedef int64_t ll;
typedef uint64_t ull;
typedef uint32_t ui;
typedef uint16_t us;
typedef uint8_t uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 150;
const int X = 1000000000;
const int inf = X + N + 10;

struct Input {
	int n, st, fn;
	int d[N][N];
	
	bool read () {
		int m;
		if (!(cin >> n >> m)) {
			return 0;
		}
		st = 0, fn = n - 1;
		forn (i, n) {
			forn (j, n) {
				d[i][j] = inf;
			}
		}
		forn (i, m) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			--x;
			--y;
			umn(d[x][y], z);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans;
	
	void write () {
		if (ans == inf) {
			puts("Impossible");
			return;
		}
		printf("%d\n", ans);
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	static const int D = 64;
	static const int L = (N + D - 1) / D;
	
	bool can[N], can0[N];
	int l[N];
	
	ull a[2][N][L];
	ull b[N][L];
	
	ull tmp1[N][L], tmp2[N][L];
	
	void solve () {
		vi v;
		forn (i, n) {
			forn (j, n) {
				v.pb(d[i][j]);
			}
		}
		v.pb(0);
		v.pb(inf);
		sort(all(v));
		v.erase(unique(all(v)), v.end());
		v.pop_back();
		memset(can, 0, sizeof can);
		can[st] = 1;
		ans = inf;
		
		forn (i, n) {
			debug(d[i], d[i] + n);
		}
		
		forn (t, sz(v)) {
			forn (i, n) {
				l[i] = inf;
			}
			queue<int> q;
			forn (i, n) {
				if (can[i]) {
					q.push(i);
					l[i] = 0;
				}
			}
			while (sz(q)) {
				int x = q.front();
				q.pop();
				forn (i, n) {
					if (d[x][i] <= v[t] && umn(l[i], l[x] + 1)) {
						q.push(i);
					}
				}
			}
			umn(ans, v[t] + l[fn]);
			
			debug(v[t]);
			debug(l, l + n);
			
			if (t + 1 == sz(v)) {
				break;
			}
			
			memset(a, 0, sizeof a);
			forn (i, n) {
				forn (j, n) {
					if (d[i][j] <= v[t]) {
						a[0][i][j / D] |= 1ull << (j % D);
						a[1][j][i / D] |= 1ull << (i % D);
					}
				}
			}
			
			forn (i, n) {
				debug(bitset<64>(a[0][i][0]));
			}
			
			memset(b, 0, sizeof b);
			forn (i, n) {
				b[i][i / D] |= 1ull << (i % D);
				b[i][i / D] |= 1ull << (i % D);
			}
			int pw = v[t + 1] - v[t];
			
			debug(pw);
			
			while (pw) {
				if (pw & 1) {
					memcpy(tmp1, b, sizeof b);
					memset(b, 0, sizeof b);
					forn (i, n) {
						forn (j, n) {
							forn (k, (n + D - 1) / D) {
								if (tmp1[i][k] & a[1][j][k]) {
									b[i][j / D] |= 1ull << (j % D);
									break;
								}
							}
						}
					}
				}
				memcpy(tmp1, a[0], sizeof a[0]);
				memcpy(tmp2, a[1], sizeof a[1]);
				memset(a, 0, sizeof a);
				forn (i, n) {
					forn (j, n) {
						forn (k, (n + D - 1) / D) {
							if (tmp1[i][k] & tmp2[j][k]) {
								a[0][i][j / D] |= 1ull << (j % D);
								a[1][j][i / D] |= 1ull << (i % D);
								break;
							}
						}
					}
				}
				pw /= 2;
			}
			
			forn (i, n) {
				debug(bitset<64>(b[i][0]));
			}
			
			memcpy(can0, can, sizeof can);
			memset(can, 0, sizeof can);
			forn (i, n) {
				if (can0[i]) {
					forn (j, n) {
						if (b[i][j / D] & (1ull << (j % D))) {
							can[j] = 1;
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