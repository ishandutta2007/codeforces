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

const int N = 30000;
const int M = 30000;

struct Input {
	int mod;
	int n, m;
	int a[N];
	int l[M], r[M];
	
	bool read () {
		if (!(cin >> n >> mod)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
		}
		cin >> m;
		forn (i, m) {
			scanf("%d%d", &l[i], &r[i]);
			--l[i];
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans[M];
	
	void write () {
		forn (i, m) {
			cout << ans[i] << endl;
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	static const int K = 11;
	static const int D = N / K + 1;
	
	int f[N + 10];
	int p[N], rev[N];
	
	int cnt[M];
	int hv[M];
	
	int msk[N + 1];
	int mb[1 << K], bt[2][1 << K], v[2][1 << K][2];
	
	void solve () {
		f[0] = 1;
		f[1] = 0;
		forn (i, N + 8) {
			f[i + 2] = (f[i] + f[i + 1]) % mod;
		}
		forn (i, n) {
			p[i] = i;
		}
		sort(p, p + n, [&] (int i, int j) {
			return a[i] < a[j];
		});
		forn (i, n) {
			rev[p[i]] = i;
		}
		mb[0] = -1;
		forn (i, K) {
			forn (q, 1 << i) {
				mb[q | (1 << i)] = i;
			}
		}
		memset(ans, 0, sizeof ans);
		memset(cnt, 0, sizeof cnt);
		memset(hv, -1, sizeof hv);
		forn (t, D) {
			if (t * K >= n) {
				break;
			}
			msk[0] = 0;
			forn (i, n) {
				msk[i + 1] = msk[i];
				if (rev[i] >= t * K && rev[i] < (t + 1) * K) {
					msk[i + 1] |= 1 << (rev[i] - t * K);
				}
			}
			memset(v, 0, sizeof v);
			memset(bt, 0, sizeof bt);
			forn (w, 2) {
				forn (i, min(K, n - t * K)) {
					forn (q, 1 << i) {
						if (i ? (a[p[t * K + i]] == a[p[t * K + i - 1]]) : w) {
							int q0 = i ? (q | (1 << (i - 1))) : q;
							forn (z, 2) {
								v[w][q | (1 << i)][z] = v[w][q0][z];
							}
							bt[w][q | (1 << i)] = bt[w][q0];
						} else {
							forn (z, 2) {
								v[w][q | (1 << i)][z] = (v[w][q][z] + f[bt[w][q] + z] * (a[p[t * K + i]] % mod)) % mod;
							}
							bt[w][q | (1 << i)] = bt[w][q] + 1;
						}
					}
				}
			}
			forn (i, m) {
				int ttt = (hv[i] == -1) ? 0 : (a[p[hv[i]]] == a[p[t * K]]);
				int mmm = msk[r[i]] & ~msk[l[i]];
				forn (z, 2) {
					ans[i] = (ans[i] + v[ttt][mmm][z] * f[cnt[i] + 2 + z]) % mod;
				}
				cnt[i] += bt[ttt][mmm];
				if (mb[mmm] != -1) {
					hv[i] = t * K + mb[mmm];
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