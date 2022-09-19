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

const int N = 5005;
const ll mod = 1000000007;

struct Input {
	int n;
	char c[N];

	bool read () {
		string s;
		if (!getline(cin, s)) {
			return 0;
		}
		n = sz(s);
		forn (i, n) {
			c[i] = s[i];
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ll ans1, ans2;
	
	void write () {
		cout << ans1 << endl << ans2 << endl;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	int pos[N], rev[N];
	int lcp[N - 1];
	int lcp_[N][N];

	int ds[N + 1][N + 1], dm[N + 1][N + 1];
	
	void solve () {
		forn (i, n) {
			pos[i] = i;
		}
		sort(pos, pos + n, [&] (int i, int j) {
			int l = min(n - i, n - j);
			int q = memcmp(c + i, c + j, l);
			if (q) {
				return q < 0;
			}
			return i > j;
		});
		debug(pos, pos + n);
		forn (i, n) {
			rev[pos[i]] = i;
		}
		forn (i, n - 1) {
			lcp[i] = 0;
			while (pos[i] + lcp[i] < n && pos[i + 1] + lcp[i] < n && c[pos[i] + lcp[i]] == c[pos[i + 1] + lcp[i]]) {
				++lcp[i];
			}
		}
		debug(lcp, lcp + n - 1);
		forn (i, n) {
			forn (j, n) {
				if (i == j) {
					lcp_[i][j] = n;
				}
				if (i > j) {
					lcp_[i][j] = min(lcp_[i - 1][j], lcp[i - 1]);
				}
				if (i < j) {
					lcp_[i][j] = min(lcp_[i][j - 1], lcp[j - 1]);
				}
			}
		}
		forn (i, n) {
			debug(lcp_[i], lcp_[i] + n);
		}
		forn (i, N + 1) {
			forn (j, N + 1) {
				ds[i][j] = 0;
				dm[i][j] = N + 1;
			}
		}
		ds[0][1] = 1;
		dm[0][1] = 1;
		forn (r, n) {
			if (c[r] == '0') {
				continue;
			}
			forn (l, r) {
				if (c[l] == '0') {
					continue;
				}
				int k = 2 * r - l;
				if (lcp_[rev[l]][rev[r]] < r - l && rev[l] > rev[r]) {
					k++;
				}
				if (k > n) {
					continue;
				}
				debug(mt(l, r, k));
				(ds[r][k] += ds[l][r]) %= mod;
				umn(dm[r][k], dm[l][r] + 1);
			}
			for (int rr = r + 1; rr < n; ++rr) {
				(ds[r][rr + 1] += ds[r][rr]) %= mod;
				umn(dm[r][rr + 1], dm[r][rr]);
			}
		}
		forn (i, n) {
			debug(ds[i], ds[i] + n + 1);
		}
		forn (i, n) {
			debug(dm[i], dm[i] + n + 1);
		}
		ans1 = 0;
		int lst = 0;
		forn (i, n) {
			(ans1 += ds[i][n]) %= mod;
			if (dm[i][n] <= N) {
				lst = i;
			}
		}
		if (n - lst <= 20) {
			ans2 = 1e9;
			int d = 1;
			int s = 0;
			for (int i = n - 1; i >= n - 20 && i >= 0; --i) {
				s += (c[i] - '0') * d;
				d *= 2;
				if (dm[i][n] <= N) {
					umn(ans2, s + dm[i][n]);
				}
			}
			return;
		}
		ans2 = 0;
		for (int i = lst; i < n; ++i) {
			((ans2 *= 2) += c[i] - '0') %= mod;
		}
		(ans2 += dm[lst][n]) %= mod;
	}
	
	void clear () {
		//*this = Solution();
	}
};

Solution sol;

int main () {
	deepen(0);
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