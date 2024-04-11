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

const int N = 100010;
const ll mod = 1000000007;

struct Input {
	string s, t;
	
	bool read () {
		return getline(cin, s) && getline(cin, t);
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
	static const ll mod1 = 1000000007;
	static const ll mod2 = 1000000009;
	static const ll p1 = 31;
	static const ll p2 = 29;
	
	ll pp1[N + 1], pp2[N + 1];
	
	ll sh1[N + 1], sh2[N + 1];
	ll th1, th2;
	
	bool ok[N + 1];
	int mnr[N + 1];
	
	ll a[N + 1], b[N + 1];
	
	void solve () {
		pp1[0] = pp2[0] = 1;
		forn (i, N) {
			pp1[i + 1] = pp1[i] * p1 % mod1;
			pp2[i + 1] = pp2[i] * p2 % mod2;
		}
		sh1[0] = sh2[0] = 0;
		forn (i, sz(s)) {
			sh1[i + 1] = (sh1[i] * p1 + s[i]) % mod1;
			sh2[i + 1] = (sh2[i] * p2 + s[i]) % mod2;
		}
		th1 = th2 = 0;
		forn (i, sz(t)) {
			th1 = (th1 * p1 + t[i]) % mod1;
			th2 = (th2 * p2 + t[i]) % mod2;
		}
		forn (i, sz(s) + 1) {
			ok[i] = (
				i + sz(t) <= sz(s) &&
				(sh1[i] * pp1[sz(t)] + th1) % mod1 == sh1[i + sz(t)] &&
				(sh2[i] * pp2[sz(t)] + th2) % mod2 == sh2[i + sz(t)]
			);
		}
		mnr[sz(s)] = N + 1;
		ford (i, sz(s)) {
			if (ok[i]) {
				mnr[i] = i + sz(t);
			} else {
				mnr[i] = mnr[i + 1];
			}
		}
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		a[0] = 1;
		forn (i, sz(s)) {
			(a[i + 1] += a[i]) %= mod;
			(b[i + 1] += b[i]) %= mod;
			if (mnr[i] != N + 1) {
				(b[mnr[i]] += a[i]) %= mod;
			}
			(a[i + 1] += b[i + 1]) %= mod;
		}
		debug(ok, ok + sz(s) + 1);
		debug(a, a + sz(s) + 1);
		debug(b, b + sz(s) + 1);
		ans = (a[sz(s)] + mod - 1) % mod;
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