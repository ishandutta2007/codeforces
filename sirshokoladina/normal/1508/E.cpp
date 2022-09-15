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

const int N = 300000;

struct Input {
	int n;
	vi e[N];
	int a[N];
	
	bool read() {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
			--a[i];
		}
		forn (i, n - 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			e[x].pb(y);
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool ans_can;
	int ans[N];
	ll ans_cnt;

	void write() {
		if (!ans_can) {
			puts("NO");
			return;
		}
		puts("YES");
		cout << ans_cnt << endl;
		forn (i, n) {
			if (i) {
				printf(" ");
			}
			printf("%d", ans[i] + 1);
		}
		puts("");
	}
};


namespace Main {
	const int L = 20;
	
	struct Solution: Data {
		int p[N];
		// int pr[N][L];

		int lvl[N];

		void dfs(int v, int cur_l, int &cur_cnt) {
			lvl[v] = cur_l++;
			ans[v] = cur_cnt++;
			for (int to : e[v]) {
				dfs(to, cur_l, cur_cnt);
			}
		}

		int ch_cnt[N];

		int pos[N];

		int bad_num = -1;
		int bad_v = -1;

		int b[N];

		void dfs1(int v, int &cur_cnt) {
			for (int to : e[v]) {
				dfs1(to, cur_cnt);
			}
			if (cur_cnt < bad_num) {
				b[v] = cur_cnt++;
			}
		}

		bool dfs2(int v, int &cur_cnt) {
			if (b[v] != -1) {
				return 0;
			}
			if (lvl[v] == lvl[bad_v]) {
				b[v] = cur_cnt++;
				return 1;
			}
			for (int to : e[v]) {
				if (dfs2(to, cur_cnt)) {
					return 1;
				}
			}
			return 1;
		}

		void dfs3(int v, int &cur_cnt) {
			if (b[v] == -1) {
				b[v] = cur_cnt++;
			}
			for (int to : e[v]) {
				dfs3(to, cur_cnt);
			}
		}
		
		void solve() {
			memset(p, -1, sizeof p);
			forn (i, n) {
				sort(all(e[i]), [&] (int x, int y) {
					return a[x] < a[y];
				});
				for (int to : e[i]) {
					p[to] = i;
				}
			}
			debug(a, a + n);
			debug(e, e + n);
			int root = 0;
			while (p[root] != -1) {
				++root;
			}
			{
				int cur_cnt = 0;
				dfs(root, 0, cur_cnt);
			}

			forn (i, n) {
				ch_cnt[i] = sz(e[i]);
				pos[a[i]] = i;
			}

			debug(pos, pos + n);

			ans_cnt = 0;
			forn (i, n) {
				int v = pos[i];
				ans_cnt += lvl[v];
				if (ch_cnt[v] > 0) {
					bad_num = i;
					bad_v = v;
					break;
				}
				if (p[v] == -1) {
					continue;
				}
				ch_cnt[p[v]]--;
			}
			debug(mt(bad_num, bad_v));

			if (bad_num == -1) {
				ans_can = 1;
				return;
			}

			memset(b, -1, sizeof b);
			{
				int cur_cnt = 0;
				dfs1(root, cur_cnt);
				debug(b, b + n);
				dfs2(root, cur_cnt);
				debug(b, b + n);
				dfs3(root, cur_cnt);
				debug(b, b + n);
			}
			ans_can = 1;
			forn (i, n) {
				ans_can &= (b[i] == a[i]);
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