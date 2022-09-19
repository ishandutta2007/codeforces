#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
#else
	template<typename T> struct outputer;
	struct outputable {};
	#define PRINT(...)
	#define OUTPUT(...)
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
	#define fbegin(...)
	#define fend
	#define pbegin(...)
	#define pend
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
#define pb emplace_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long double ld;
typedef int64_t ll;
typedef uint64_t ull;
typedef uint32_t ui;
typedef uint16_t us;
typedef uint8_t uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

struct Input {
	int st, fn, p;
	
	bool read () {
		return !!(cin >> st >> fn >> p);
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	vi ans;
	
	void write () {
		cout << sz(ans) << endl;
		forn (i, sz(ans)) {
			if (i) {
				printf(" ");
			}
			printf("%d", ans[i] + 1);
		}
		puts("");
	}
};


namespace Main {
	
	struct Solution: Data {
		int inc (int x) {
			return (x + 1) % p;
		}
		
		int dec (int x) {
			return (x + p - 1) % p;
		}
		
		int pw (int x, int n) {
			int res = 1;
			while (n) {
				if (n & 1) {
					res = res * 1ll * x % p;
				}
				x = x * 1ll * x % p;
				n >>= 1;
			}
			return res;
		}
		
		int inv (int x) {
			return pw(x, p - 2);
		}
		
		unordered_map<int, int> s[2];
		
		int rev (int t) {
			if (t == 2) {
				return t;
			}
			return 1 - t;
		}
		
		void go (vi &v, int t, int x) {
			while (s[t][x] != -1) {
				debug(mt(t, x));
				v.pb(s[t][x]);
				if (s[t][x] == 0) {
					x = dec(x);
				} else if (s[t][x] == 1) {
					x = inc(x);
				} else if (s[t][x] == 2) {
					x = inv(x);
				}
			}
		}

		ve<pii>	q;
		
		bool add (int t, int v, int r) {
			if (s[t].count(v)) {
				return 0;
			}
			debug(mt(t, v, r));
			s[t][v] = r;
			q.pb(mp(v, t));
			if (s[!t].count(v)) {
				debug(s[0]);
				debug(s[1]);
				vi v0, v1;
				go(v0, 0, v);
				go(v1, 1, v);
				ford (i, sz(v0)) {
					ans.pb(v0[i]);
				}
				forn (i, sz(v1)) {
					ans.pb(rev(v1[i]));
				}
				debug(v0);
				debug(v1);
				return 1;
			}
			return 0;
		}
		
		void solve () {
			deepen(0);
			if (add(0, st, -1)) {
				return;
			}
			if (add(1, fn, -1)) {
				return;
			}
			forn (i, sz(q)) {
				int v = q[i].fs;
				int t = q[i].sc;
				if (add(t, inc(v), 0)) {
					return;
				}
				if (add(t, dec(v), 1)) {
					return;
				}
				if (add(t, inv(v), 2)) {
					return;
				}
			}
			assert(0);
		}
		
		void clear () {
			*this = Solution();
		}
	};
}


Main::Solution sol;

int main () {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);

	#ifdef SG
		freopen((problemname + ".in").c_str(), "r", stdin);
//		freopen((problemname + ".out").c_str(), "w", stdout);
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