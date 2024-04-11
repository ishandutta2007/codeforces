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

const int N = 2000;

struct Input {
	int n;
	string s[N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		getline(cin, s[0]);
		forn (i, n) {
			getline(cin, s[i]);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	vi ans[N];
	
	void write () {
		forn (i, n) {
			printf("%d", sz(ans[i]));
			forn (j, sz(ans[i])) {
				printf(" %d", ans[i][j]);
			}
			puts("");
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	static const int L = (N + 63) >> 6;
	ull m[N][L];
	ull u[N][L];
	bool need[N];
	int pos[N];
	
	void solve () {
		memset(m, 0, sizeof m);
		forn (i, n) {
			ve<ull> q((sz(s[i]) + 8) / 9, 0);
			ford (j, sz(s[i])) {
				(q[sz(q) - 1 - j / 9] *= 10) += s[i][sz(s[i]) - 1 - j] - '0';
			}
			forn (k, L * 2) {
				ull r = 0;
				forn (j, sz(q)) {
					q[j] += r * 1000000000;
					r = q[j] & ((1ull << 32) - 1);
					q[j] >>= 32;
				}
				m[i][k >> 1] |= r << (32 * (k & 1));
			}
		}
		memset(u, 0, sizeof u);
		forn (i, n) {
			u[i][i >> 6] |= 1ull << (i & 63);
			forn (j, i) if (need[j]) {
				if (m[i][pos[j] >> 6] & (1ull << (pos[j] & 63))) {
					forn (k, L) {
						m[i][k] ^= m[j][k];
					}
					forn (k, (i + 63) >> 6) {
						u[i][k] ^= u[j][k];
					}
				}
			}
			need[i] = 0;
			forn (j, N) {
				if (m[i][j >> 6] & (1ull << (j & 63))) {
					need[i] = 1;
					pos[i] = j;
					break;
				}
			}
			if (!need[i]) {
				forn (j, i) {
					if (u[i][j >> 6] & (1ull << (j & 63))) {
						ans[i].pb(j);
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