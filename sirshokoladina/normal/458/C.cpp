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

const int N = 100000;
const int M = 100001;

struct Input {
	int n;
	int a[N], b[N];
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d%d", &a[i], &b[i]);
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
		cout << ans << endl;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	ve<pii> v[M];
	
	void solve () {
		forn (i, n) {
			v[a[i]].pb(mp(b[i], i));
		}
		forn (i, M) {
			sort(all(v[i]));
		}
		int s0 = sz(v[0]);
		set<pa<pii, int>, greater<pa<pii, int> > > fr;
		for (int i = 1; i < M; ++i) {
			forn (j, sz(v[i])) {
				fr.insert(mp(mp(sz(v[i]) - 1 - j, v[i][j].fs), v[i][j].sc));
			}
		}
		int t = n;
		set<pii, greater<pii> > q;
		int sum = 0;
		for (auto x: fr) {
			q.insert(mp(x.fs.sc, x.sc));
			sum += x.fs.sc;
		}
		ans = sum;
		for (; t >= s0; --t) {
			while (fr.size() && fr.begin()->fs.fs >= t - 1) {
				if (!q.erase(mp(fr.begin()->fs.sc, fr.begin()->sc))) {
					sum += fr.begin()->fs.sc;
				}
				fr.erase(fr.begin());
			}
			int cnt = t - s0 - (n - s0 - sz(fr));
			if (cnt < 0) {
				break;
			}
			while (sz(q) > cnt) {
				sum -= q.begin()->fs;
				q.erase(q.begin());
			}
			umn(ans, sum);
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