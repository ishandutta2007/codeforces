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

const int N = 200000;

struct Input {
	int n;
	int a[N];
	
	bool read() {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
			--a[i];
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ve<pii> ans;
	
	void write() {
		cout << sz(ans) << endl;
		forn (i, sz(ans)) {
			printf("%d %d\n", ans[i].fs + 1, ans[i].sc + 1);
		}
	}
};


namespace Main {
	
	struct Solution: Data {
		bool u[N];

		int b[N];

		void add(int i, int j) {
			debug(a, a + n);
			debug(b, b + n);
			debug(mt(i, j));
			assert(i != j);
			swap(a[i], a[j]);
			swap(b[i], b[j]);
			b[i] ^= 1;
			b[j] ^= 1;
			ans.pb(mp(i, j));
			debug(a, a + n);
			debug(b, b + n);
		}

		void proc3(int v1, int v2, int v3) {
			debug(mt(v1, v2, v3));
			assert(b[v1]);
			assert(b[v2]);
			assert(!b[v3]);
			assert(a[v1] == v2);
			assert(a[v2] == v3);
			assert(a[v3] == v1);

			add(v2, v3);
			add(v1, v2);

			assert(!b[v1]);
			assert(!b[v2]);
			assert(!b[v3]);
			assert(a[v1] == v1);
			assert(a[v2] == v2);
			assert(a[v3] == v3);
		}

		void make2(pii c1, pii c2) {
			debug(mt(c1, c2));
			int v1 = c1.fs;
			int v2 = c2.fs;
			assert(v1 != v2);
			add(v1, v2);
			assert(a[v1] != v1);
			assert(a[v1] != v2);
			assert(a[v2] != v1);
			assert(a[v2] != v2);
			while (a[v1] != v2) {
				int nx = a[v1];
				debug(mt(v1, v2, nx));
				add(v1, nx);
				// v1 = nx;
			}
			while (a[a[v2]] != v1) {
				int nx = a[v2];
				add(v2, nx);
				// v2 = nx;
			}

			int v3 = a[v2];

			proc3(v1, v2, v3);
		}

		void make1(pii c) {
			debug(c);
			assert(c.sc > 1);
			int v1 = c.fs;
			int v2 = a[v1];
			if (c.sc == 2) {
				int v3 = 0;
				while (v3 < n && a[v3] != v3) {
					v3++;
				}
				assert(v3 < n);
				add(v1, v3);
				proc3(v1, v3, v2);
				return;
			}
			add(v1, v2);
			assert(a[v2] == v2);
			assert(a[v1] != v1);
			assert(a[v1] != v2);
			debug(mt(v1, v2));
			while (a[a[v1]] != v1) {
				int nx = a[v1];
				add(v1, nx);
				// v1 = nx;
			}

			int v3 = a[v1];
			add(v2, v3);
			debug(mt(v1, v2, v3));
			proc3(v2, v1, v3);
		}
		
		void solve() {
			memset(u, 0, sizeof u);
			memset(b, 0, sizeof b);

			debug(a, a + n);

			ve<pii> c;
			forn (i, n) {
				if (u[i]) {
					continue;
				}
				int len = 0;
				while (!u[i]) {
					u[i] = 1;
					i = a[i];
					len++;
				}
				if (len > 1) {
					c.pb(mp(i, len));
				}
			}
			debug(c);

			while (sz(c) > 1) {
				make2(c[sz(c) - 1], c[sz(c) - 2]);
				c.pop_back();
				c.pop_back();
			}
			if (sz(c) > 0) {
				assert(sz(c) == 1);
				make1(c[0]);
				c.pop_back();
			}
		}
		
		void clear() {
			*this = Solution();
		}
	};
}


Main::Solution sol;

int main() {
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