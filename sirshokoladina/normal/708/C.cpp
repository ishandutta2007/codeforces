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

const int N = 400000;

struct Input {
	int n;
	vi e[N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n - 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			e[x].pb(y);
			e[y].pb(x);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool ans[N];
	
	void write () {
		forn (i, n) {
			if (i) {
				printf(" ");
			}
			printf("%d", int(ans[i]));
		}
		puts("");
	}
};


namespace Main {
	
	struct Solution: Data {
		int cnt[N];
		
		void calc_cnt (int v, int pr) {
		debug(mt(v, pr));
			cnt[v] = 1;
			for (int to : e[v]) {
				if (to == pr) {
					continue;
				}
				calc_cnt(to, v);
				cnt[v] += cnt[to];
			}
		}
		
		void check (int v, int pr, const set<int> &q, bool bbb) {
			debug(mt(v, cnt[v], q));
			bbb |= (cnt[v] * 2 == n);
			if (bbb) {
				ans[v] = 1;
				debug("ok");
			} else {
				debug(n - cnt[v] - n / 2);
				auto it = q.lower_bound(n - cnt[v] - n / 2);
				if (it != q.end()) {
					int val = *it;
					debug(val);
					if (val * 2 <= n) {
						ans[v] = 1;
						debug("ok");
					}
				}
			}
			for (int to : e[v]) {
				if (to == pr) {
					continue;
				}
				check(to, v, q, bbb);
			}
		}
		
		void add (int v, int pr, set<int> &q) {
			q.insert(cnt[v]);
			for (int to : e[v]) {
				if (to == pr) {
					continue;
				}
				add(to, v, q);
			}
		}
		
		void solve () {
			memset(ans, 0, sizeof ans);
			calc_cnt(0, -1);
			debug();
			int rt = 0;
			while (1) {
				debug(rt);
				bool done = 0;
				for (int to : e[rt]) {
					if (cnt[to] < cnt[rt] && cnt[to] * 2 > n) {
						rt = to;
						done = 1;
						break;
					}
				}
				if (!done) {
					break;
				}
			}
			debug();
			calc_cnt(rt, -1);
			debug();
			
			ans[rt] = 1;
			
			set<int> q;
			
			debug();
			q.clear();
			forn (i, sz(e[rt])) {
				check(e[rt][i], rt, q, 0);
				add(e[rt][i], rt, q);
			}
			debug();
			
			q.clear();
			ford (i, sz(e[rt])) {
				check(e[rt][i], rt, q, 0);
				add(e[rt][i], rt, q);
			}
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
	}
	*/
	
	return 0;
}