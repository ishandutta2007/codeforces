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

const int N = 1000000;
const int X = 1000000;
const ll mod = 1000000007;

struct Input {
	int n;
	int a[N];

	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
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
	static const int D = 20;
	ll d2[N + 1];
	int s[X][D + 1];
	int cnt[X + 1];
	
	void solve () {
		memset(s, 0, sizeof s);
		forn (i, n) {
			s[a[i]][0]++;
		}
		ford (i, X + 1) {
			forn (j, D) {
				s[i][j + 1] += s[i][j];
				if (i & (1 << j)) {
					s[i - (1 << j)][j + 1] += s[i][j];
				}
			}
			cnt[i] = s[i][D];
		}
		d2[0] = 0;
		forn (i, N) {
			d2[i + 1] = (d2[i] * 2 + 1) % mod;
		}
		ans = 0;
		forn (i, X + 1) {
			if (cnt[i]) {
				debug(mt(i, __builtin_parity(i), cnt[i], d2[cnt[i]]));
			}
			if (__builtin_parity(i)) {
				(ans += mod - d2[cnt[i]]) %= mod;
			} else {
				(ans += d2[cnt[i]]) %= mod;
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