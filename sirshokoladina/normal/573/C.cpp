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

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 100000;

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
	bool ans;
	
	void write () {
		puts(ans ? "Yes" : "No");
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	bool need[N];
	int cnt[N];
	bool need2[N];
	int cnt2[N];

	void dfs0 (int v, int pr) {
		need[v] = sz(e[v]) > 2;
		cnt[v] = need[v];
		need2[v] = sz(e[v]) > 3;
		cnt2[v] = need2[v];
		for (int to : e[v]) if (to != pr) {
			dfs0(to, v);
			cnt[v] += cnt[to];
			cnt2[v] += cnt2[to];
		}
	}
	
	bool dfs2 (int v, int pr, int k) {
		debug(mt(v, pr, k));
		deepen();
		vi nums;
		for (int to : e[v]) if (to != pr) {
			if (cnt[to] - need[to] || cnt2[to]) {
				nums.pb(to);
			}
		}
		if (sz(nums) > k) {
			return 0;
		}
		for (int to : nums) {
			if (!dfs2(to, v, 1)) {
				return 0;
			}
		}
		return 1;
	}
	
	bool dfs1 (int v, int pr) {
		debug(mt(v, pr));
		deepen();
		if ((pr != -1 && need[pr]) || need2[v]) {
			return dfs2(v, pr, 2);
		}
		vi nums;
		for (int to : e[v]) if (to != pr) {
			if (cnt[to]) {
				nums.pb(to);
			}
		}
		if (sz(nums) > 1) {
			return dfs2(v, pr, 2);
		}
		if (sz(nums) == 0) {
			return 1;
		}
		return dfs1(nums[0], v);
	}
	
	void solve () {
		memset(cnt, 0, sizeof cnt);
		memset(cnt2, 0, sizeof cnt2);
		dfs0(0, -1);
		debug(need, need + n);
		debug(cnt, cnt + n);
		ans = dfs1(0, -1);
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
	freopen((problemname + ".in").c_str(), "r", stdin);
//	freopen((problemname + ".out").c_str(), "w", stdout);
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