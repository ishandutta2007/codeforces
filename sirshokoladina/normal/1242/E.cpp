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

const int N = 100000;

struct Input {
	int n;
	int a[N];
	
	bool read() {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int res;
	vi ans[N];

	void write() {
		cout << res << endl;
		forn (i, n) {
			forn (j, a[i]) {
				if (j) {
					printf(" ");
				}
				printf("%d", ans[i][j] + 1);
			}
			puts("");
		}
	}
};


namespace Main {

	struct G {
		int n;
		deque<int> r;
		vi nums;
		ve<vi> g;

		G(int num, int s) {
			n = s;
			r.resize(n);
			g.resize(1);
			g[0].resize(n);
			iota(all(r), 0);
			iota(all(g[0]), 0);
			nums = {num};
		}
	};

	void unite(G &a, G &b, int m) {
		debug(a.n);
		debug(a.r);
		debug(a.nums);
		debug(a.g);
		debug(b.n);
		debug(b.r);
		debug(b.nums);
		debug(b.g);


		int mx = min(sz(a.r), sz(b.r));
		if (sz(a.r) == sz(b.r)) {
			mx--;
		}

		debug(mx);

		vi to(b.n, -1);
		int len = sz(a.r) + sz(b.r);
		int cnt = 0;
		forn (i, mx) {
			if (len <= m) {
				break;
			}
			to[b.r[i]] = a.r[(sz(a.r) - i) % sz(a.r)];
			if (i < 2) {
				len--;
			} else {
				len -= 2;
			}
			cnt++;
		}

		debug(cnt);
		debug(len);
		debug(to);

		int n1 = a.n;
		forn (i, b.n) {
			if (to[i] == -1) {
				to[i] = n1++;
			}
		}

		debug(to);

		assert(n1 == a.n + b.n - cnt);
		for (auto &v : b.g) {
			for (auto &x : v) {
				x = to[x];
			}
		}
		for (auto &x : b.r) {
			x = to[x];
		}
		a.n = n1;
		forn (i, sz(b.nums)) {
			a.nums.pb(b.nums[i]);
			a.g.pb(b.g[i]);
		}
		assert(cnt >= 2);
		forn (i, cnt - 2) {
			a.r.pop_back();
		}
		forn (i, cnt, sz(b.r)) {
			a.r.pb(b.r[i]);
		}
		assert(sz(a.r) == len);

		a.r.pb(a.r.front());
		a.r.pop_front();

		debug(a.n);
		debug(a.r);
		debug(a.nums);
		debug(a.g);
	}
	
	struct Solution: Data {
		
		void solve() {
			ve<G> v;
			forn (i, n) {
				v.pb(G(i, a[i]));
			}
			sort(all(v), [&] (const G &l, const G &r) {
				return sz(l.r) > sz(r.r);
			});
			forn (i, 1, n) {
				unite(v[0], v[i], (i + 1 < n) ? sz(v[i + 1].r) : 0);
			}
			debug();
			assert(sz(v[0].nums) == n);
			res = v[0].n;
			forn (i, n) {
				ans[v[0].nums[i]] = v[0].g[i];
			}
			debug();
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