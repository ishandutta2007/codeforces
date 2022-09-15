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
	int n, k;
	vi f[N];
	int p[N];
	
	bool read() {
		int m;
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, m) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			f[y].pb(x);
		}
		cin >> k;
		forn (i, k) {
			scanf("%d", &p[i]);
			--p[i];
		}
		debug(f, f + n);
		debug(p, p + k);
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans_l, ans_r;
	
	void write() {
		cout << ans_l << ' ' << ans_r << endl;
	}
};


namespace Main {
	
	struct Solution: Data {
		int l[N], cnt[N];
		
		void solve() {
			forn (i, n) {
				l[i] = N + 1;
				cnt[i] = 0;
			}
			vi q;
			int st = p[0];
			int fn = p[k - 1];
			l[fn] = 0;
			cnt[fn] = 0;
			q.pb(fn);
			forn (i, sz(q)) {
				int v = q[i];
				for (int to : f[v]) {
					if (umn(l[to], l[v] + 1)) {
						cnt[to] = 0;
						q.pb(to);
					}
					if (l[to] == l[v] + 1) {
						cnt[to]++;
					}
				}
			}
			debug(l, l + n);
			debug(cnt, cnt + n);
			ans_l = ans_r = 0;
			forn (i, k - 1) {
				if (l[p[i]] != l[p[i + 1]] + 1) {
					ans_l++;
					ans_r++;
				} else if (cnt[p[i]] > 1) {
					ans_r++;
				}
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