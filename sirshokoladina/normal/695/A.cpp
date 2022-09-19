#include <bits/stdc++.h>
using namespace std;

#define ARG4(a,b,c,d,...) d

#define forn3(i,a,b) for (int i = int(a); i < int(b); ++i)
#define forn2(i,n) forn3 (i, 0, n)
#define forn(...) ARG4(__VA_ARGS__, forn3, forn2) (__VA_ARGS__)

#define ford3(i,a,b) for (int i = int(b) - 1; i >= int(a); --i)
#define ford2(i,n) ford3 (i, 0, n)
#define ford(...) ARG4(__VA_ARGS__, ford3, ford2) (__VA_ARGS__)

#define ve vector
#define pa pair
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())

typedef long double ld;
typedef int64_t ll;
typedef uint8_t uc;
typedef uint16_t us;
typedef uint32_t ui;
typedef uint64_t ull;

typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = acos(-1.l);

template<typename A, typename B> bool umn (A &a, B b) {if (b < a) {a = b; return 1;} return 0;}
template<typename A, typename B> bool umx (A &a, B b) {if (a < b) {a = b; return 1;} return 0;}

#ifdef SG
	#include "debug.h"
#else
	#define debug(...)
	#define deepen(...)
#endif

const int N = 20;

struct Input {
	int n, k;
	ld p[N];
	
	bool read () {
		if (!(cin >> n >> k)) {
			return 0;
		}
		forn (i, n) {
			cin >> p[i];
		}
		return 1;
	}
	
	void init (const Input &o) {
		*this = o;
	}
};

struct Data : Input {
	ld ans[N];
	
	void write () {
		forn (i, n) {
			if (i) {
				printf(" ");
			}
			cout << ans[i];
		}
		puts("");
	}
};

struct Solution : Data {
	ld s[1 << N];
	ld a[1 << N];
	ld c[N + 1][N + 1];
	
	void solve () {
		int cnt = 0;
		forn (i, n) {
			if (p[i] > 1e-5) {
				cnt++;
			}
		}
		if (cnt <= k) {
			forn (i, n) {
				if (p[i] > 1e-5) {
					ans[i] = 1;
				} else {
					ans[i] = 0;
				}
			}
			return;
		}
		
		forn (i, n + 1) {
			forn (j, n + 1) {
				if (!i || !j) {
					c[i][j] = 1;
				} else {
					c[i][j] = c[i - 1][j] + c[i][j - 1];
				}
			}
		}
		forn (msk, 1 << n) {
			s[msk] = 0;
			forn (i, n) {
				if (msk & (1 << i)) {
					s[msk] += p[i];
				}
			}
		}
		forn (t, n) {
			memset(a, 0, sizeof a);
			forn (msk, 1 << n) {
				if (__builtin_popcount(msk) == k && (msk & (1 << t))) {
					a[msk] = 1 - s[msk];
				}
			}
			forn (i, n) {
				forn (msk, 1 << n) {
					msk |= 1 << i;
					a[msk - (1 << i)] -= a[msk];
				}
			}
			ans[t] = 0;
			forn (msk, 1 << n) {
//				int t = __builtin_popcount(msk);
				if (s[msk] > 1 - 1e-5) {
					continue;
				}
				ans[t] += a[msk] / (1 - s[msk]);
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
		freopen("a.in", "r", stdin);
		//freopen("a.out", "w", stdin);
		
		while (sol.read()) {
			sol.solve();
			sol.write();
			sol.clear();
		}
	#else
		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
		sol.read();
		sol.solve();
		sol.write();
	#endif
	
	/*
	int t;
	cin >> t;
	forn (i, t) {
		sol.read();
		sol.solve();
		sol.write();
		sol.clear();
	}
	*/
	
	return 0;
}