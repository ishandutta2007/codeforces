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

struct Input {
	ll n;
	
	bool read () {
		return cin >> n;
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

	static const int R = 1000000;
	
	bool ispr[R + 1];
	ve<ll> pr;
	
	Solution () {
		memset(ispr, -1, sizeof ispr);
		ispr[0] = ispr[1] = 0;
		forn (i, R + 1) {
			if (ispr[i]) {
				pr.pb(i);
				for (int j = i + i; j <= R; j += i) {
					ispr[j] = 0;
				}
			}
		}
	}
	
	ve<ll> d;
	
	int u[R + 1];
	
	int pos (ll p) {
		if (n % p) {
			return -1;
		}
		ll q = n / p;
		if (p <= q) {
			return u[p];
		}
		return sz(d) - 1 - u[q];
	}
	
	int ok (ll p) {
		--p;
		if (p < 2) {
			return 0;
		}
		for (ll t: pr) {
			if (p % t == 0) {
				while (p % t == 0) {
					p /= t;
				}
				if (p == 1) {
					return t;
				}
				return 0;
			}
		}
		return p;
	}
	
	ve<pa<ll, ll> > g;
	
	static const ll D = 100000;
	
	ll q[D], w[D];
	
	void solve () {
		for (ll p = 1; p * p <= n; ++p) {
			if (n % p == 0) {
				d.pb(p);
				if (p * p < n) {
					d.pb(n / p);
				}
			}
		}
		sort(all(d));
		debug(d);
		memset(u, 0, sizeof u);
		forn (i, (sz(d) + 1) / 2) {
			u[d[i]] = i;
		}
		forn (i, sz(d)) {
			int r = ok(d[i]);
			if (r) {
				g.pb(mp(r, d[i]));
			}
		}
		sort(all(g));
		memset(q, 0, sizeof q);
		q[0] = 1;
		for (int j = 0; j < sz(g); ) {
			memcpy(w, q, sizeof q);
			int j0 = j;
			for (; j < sz(g) && g[j].fs == g[j0].fs; ++j) {
				ll p = g[j].sc;
				ll ms = n / p;
				forn (i, sz(d)) {
					if (d[i] > ms) {
						break;
					}
					int to = pos(d[i] * p);
						if (to == -1) {
						continue;
					}
					w[to] += q[i];
				}
			}
			memcpy(q, w, sizeof q);
		}
		ans = q[sz(d) - 1];
	}
	
	void clear () {
		*this = Solution();
	}
};

struct Stupid: Data {
	
	ll calc (ll p) {
		ll res = 1;
		for (ll i = 2; i * i <= p; ++i)  {
			if (p % i == 0) {
				ll cur = 1;
				while (p % i == 0) {
					p /= i;
					cur *= i;
				}
				res *= cur + 1;
			}
		}
		if (p > 1) {
			res *= p + 1;
		}
		return res;
	}
	
	void solve () {
		ans = 0;
		for (ll i = 1; i <= n; ++i) {
			debug(mp(i, calc(i)));
			if (calc(i) == n) {
				ans++;
			}
		}
	}
	
	void clear () {
		*this = Stupid();
	}
};

Stupid stu;

Solution sol;

int main () {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);
#ifdef SG
	forn (i, 1, 10001) {
		stu.n = i;
		sol.n = i;
		{
			deepen(0);
			sol.solve();
			stu.solve();
		}
//		debug(mt(i, sol.ans, stu.ans));
		if (sol.ans != stu.ans) {
			debug(i);
			exit(0);
		}
		sol.clear();
		stu.clear();
	}
	return 0;
	
	freopen("d.in", "r", stdin);
//	freopen("d.out", "w", stdout);
	while (sol.read()) {
		stu.init(sol);
		sol.solve();
		stu.solve();
		debug(sol.ans);
		debug(stu.ans);
		if (sol.ans != stu.ans) {
			assert(0);
		}
		sol.write();
		sol.clear();
		stu.clear();
	}
#else
	sol.read();
	sol.solve();
	sol.write();
#endif
	return 0;
}