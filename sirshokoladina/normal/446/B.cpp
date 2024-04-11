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

const int N = 1000;
const int K = 1000000;

struct Input {
	int n, m, k, p;
	int a[N][N];

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool read () {
		if (!(cin >> n >> m >> k >> p)) {
			return 0;
		}
		forn (i, n) {
			forn (j, m) {
				scanf("%d", &a[i][j]);
			}
		}
		return 1;
	}

	ll ans;
	
	void write () {
		cout << ans << endl;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	ll d[N];
	multiset<ll> q;
	
	void make (ll* s, int w, int h) {
		forn (i, w) {
			q.insert(d[i]);
		}
		s[0] = 0;
		forn (i, k) {
			auto it = --q.end();
			ll val = *it;
			s[i + 1] = s[i] + val;
			q.erase(it);
			q.insert(val - p * h);
		}
		q.clear();
	}

	ll s[K + 1], t[K + 1];
	
	void solve () {
		memset(d, 0, sizeof d);
		forn (i, n) {
			forn (j, m) {
				d[i] += a[i][j];
			}
		}
		make(s, n, m);
		debug(s, s + k + 1);
		memset(d, 0, sizeof d);
		forn (i, n) {
			forn (j, m) {
				d[j] += a[i][j];
			}
		}
		make(t, m, n);
		debug(t, t + k + 1);
		ans = -1e18;
		forn (i, k + 1) {
			umx(ans, s[i] + t[k - i] - ll(i) * ll(k - i) * p);
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