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

const int N = 100000;

struct Input {
	int n;
	int a[N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
			--a[i];
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ve<pii> ans;
	
	void write () {
		cout << sz(ans) << endl;
		forn (i, sz(ans)) {
			printf("%d %d\n", ans[i].fs, ans[i].sc);
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	int s0[N + 1], s1[N + 1];
	int p0[N], p1[N];
	int cnt0, cnt1;
	
	void solve () {
		cnt0 = cnt1 = 0;
		s0[0] = s1[0] = 0;
		forn (i, n) {
			s0[i + 1] = s0[i] + (a[i] == 0);
			s1[i + 1] = s1[i] + (a[i] == 1);
			if (a[i] == 0) {
				p0[cnt0++] = i;
			} else {
				p1[cnt1++] = i;
			}
		}
		for (int k = 1; k <= n; ++k) {
			int t0 = 0, t1 = 0;
			int i = 0;
			bool ok = 1;
			int lst = 0;
			while (i < n) {
				int j0 = (s0[i] + k > cnt0) ? n + 1 : p0[s0[i] + k - 1] + 1;
				int j1 = (s1[i] + k > cnt1) ? n + 1 : p1[s1[i] + k - 1] + 1;
				if (min(j0, j1) > n) {
					ok = 0;
					break;
				}
				if (j0 < j1) {
					i = j0;
					t0++;
					lst = 0;
				} else {
					i = j1;
					t1++;
					lst = 1;
				}
			}
			if (t0 == t1 || ((t0 < t1) ^ lst)) {
				ok = 0;
			}
			if (ok) {
				ans.pb(mp(max(t0, t1), k));
			}
		}
		sort(all(ans));
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