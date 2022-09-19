#include <bits/stdc++.h>

using namespace std;

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

#ifdef SG
	#include <E:\YandexDisk\Programming\SportProgramming\MyLibs\debug.h>
#else
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
#endif

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
template<typename T1, typename T2> inline void umx (T1& a, T2 b) {if (a < b) {a = b;}}
template<typename T1, typename T2> inline void umn (T1& a, T2 b) {if (b < a) {a = b;}}

const int N = 100;
const int M = 5;

struct Input {
	int n;
	int x[N], y[N];

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			string s;
			cin >> s;
			forn (j, M) {
				if ("RGBYW"[j] == s[0]) {
					x[i] = j;
				}
			}
			y[i] = s[1] - '1';
		}
		return 1;
	}
	
	int ans;
	
	void write () {
		cout << ans << endl;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	bool check (int msk1, int msk2) {
		int a[M], b[M];
		forn (i, M) {
			if (msk1 & (1 << i)) {
				a[i] = i;
			} else {
				a[i] = -1;
			}
		}
		forn (i, M) {
			if (msk2 & (1 << i)) {
				b[i] = i;
			} else {
				b[i] = -1;
			}
		}
		map<pii, set<pii> > q;
		forn (i, n) {
			q[mp(a[x[i]], b[y[i]])].insert(mp(x[i], y[i]));
		}
		for (const auto &g: q) {
			if (g.sc.size() > 1) {
				return 0;
			}
		}
		return 1;
	}

	void solve () {
		ans = 2 * M;
		forn (msk1, 1 << M) {
			forn (msk2, 1 << M) {
				if (check(msk1, msk2)) {
					ans = min(ans, __builtin_popcount(msk1) + __builtin_popcount(msk2));
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