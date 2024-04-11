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
	vi e[N];
	
	bool read() {
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

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool ans;
	
	void write() {
		puts(ans ? "YES" : "NO");
	}
};


namespace Main {
	
	struct Solution: Data {

		void del1(int v1, int v2) {
			forn (i, sz(e[v1])) {
				if (e[v1][i] == v2) {
					swap(e[v1][i], e[v1].back());
					e[v1].pop_back();
					return;
				}
			}
			assert(false);
		}

		void del(int v1, int v2) {
			del1(v1, v2);
			del1(v2, v1);
		}
		
		vi f;

		int dfs(int k, int v, int pr, int &v1, int &v2) {
			int cnt = 1;
			for (int to : e[v]) {
				if (to == pr) {
					continue;
				}
				cnt += dfs(k, to, v, v1, v2);
			}
			if (cnt == f[k - 1]) {
				v1 = v;
				v2 = pr;
			}
			if (cnt == f[k - 2]) {
				v2 = v;
				v1 = pr;
			}
			return cnt;
		}

		bool check(int r, int k) {
			deepen();
			debug(mt(r, k, f[k]));
			if (k < 2) {
				return true;
			}
			int v1 = -1, v2 = -1;
			dfs(k, r, -1, v1, v2);
			debug(mt(v1, v2));
			if (v1 == -1) {
				return false;
			}
			del(v1, v2);
			return check(v1, k - 1) && check(v2, k - 2);
		}
		
		void solve() {
			f.pb(1);
			f.pb(1);
			while (f.back() < n) {
				f.pb(f[sz(f) - 2] + f[sz(f) - 1]);
			}
			if (f.back() != n) {
				ans = 0;
				return;
			}
			ans = check(0, sz(f) - 1);
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