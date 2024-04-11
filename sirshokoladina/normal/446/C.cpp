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

const int N = 300000;
const int M = 300000;

const ll mod = 1000000009;

struct Input {
	int n, m;
	int a[N];
	int t[M], l[M], r[M];
	
	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool read () {
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
		}
		forn (i, m) {
			scanf("%d%d%d", &t[i], &l[i], &r[i]);
			--t[i];
			--l[i];
		}
		return 1;
	}

	ve<ll> ans;
	
	void write () {
		forn (i, sz(ans)) {
			cout << ans[i] << endl;
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	ll v1[N + 2], v2[N + 2];
	ll s[4 * N], u1[4 * N], u2[4 * N];
	int lb[4 * N], rb[4 * N];
	int ts;
	
	void push (int v) {
		(s[v] += (v1[rb[v] + 1] + mod - v1[lb[v] + 1]) * u1[v]) %= mod;
		(s[v] += (v2[rb[v] + 1] + mod - v2[lb[v] + 1]) * u2[v]) %= mod;
		if (lb[v] + 1 < rb[v]) {
			(u1[2 * v + 1] += u1[v]) %= mod;
			(u2[2 * v + 1] += u2[v]) %= mod;
			(u1[2 * v + 2] += u1[v]) %= mod;
			(u2[2 * v + 2] += u2[v]) %= mod;
		}
		u1[v] = 0;
		u2[v] = 0;
	}
	
	void upd (int l, int r, ll q1, ll q2, int v) {
		push(v);
		if (lb[v] >= r || rb[v] <= l) {
			return;
		}
		if (lb[v] >= l && rb[v] <= r) {
			(u1[v] += q1) %= mod;
			(u2[v] += q2) %= mod;
			push(v);
			return;
		}
		upd(l, r, q1, q2, 2 * v + 1);
		upd(l, r, q1, q2, 2 * v + 2);
		s[v] = (s[2 * v + 1] + s[2 * v + 2]) % mod;
	}
	
	ull fnd (int l, int r, int v) {
		push(v);
		if (lb[v] >= r || rb[v] <= l) {
			return 0;
		}
		if (lb[v] >= l && rb[v] <= r) {
			return s[v];
		}
		return (fnd(l, r, 2 * v + 1) + fnd(l, r, 2 * v + 2)) % mod;
	}
	
	ll F[N + 10];
	ll q[N + 2];

	void solve () {
		F[0] = 0;
		F[1] = 1;
		forn (i, N + 8) {
			F[i + 2] = (F[i] + F[i + 1]) % mod;
		}
		forn (i, N + 2) {
			v1[i] = F[i + 1];
			v2[i] = F[i + 2];
			q[i] = F[i];
			if (!(i & 1)) {
				q[i] = (mod - q[i]) % mod;
			}
		}
		debug(q, q + 5);
		ts = 1;
		while (ts < n) {
			ts *= 2;
		}
		memset(u1, 0, sizeof u1);
		memset(u2, 0, sizeof u2);
		forn (i, ts) {
			lb[ts - 1 + i] = i;
			rb[ts - 1 + i] = i + 1;
			s[ts - 1 + i] = a[i];
		}
		ford (i, ts - 1) {
			lb[i] = lb[2 * i + 1];
			rb[i] = rb[2 * i + 2];
			s[i] = (s[2 * i + 1] + s[2 * i + 2]) % mod;
		}
		debug(s, s + 2 * ts - 1);
		debug(u1, u1 + 2 * ts - 1);
		debug(u2, u2 + 2 * ts - 1);
		forn (i, m) {
			if (t[i] == 0) {
				debug(mp(q[l[i] + 1], q[l[i]]));
				upd(l[i], r[i], q[l[i] + 1], q[l[i]], 0);
			} else {
				ans.pb(fnd(l[i], r[i], 0));
			}
			debug(s, s + 2 * ts - 1);
			debug(u1, u1 + 2 * ts - 1);
			debug(u2, u2 + 2 * ts - 1);
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