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

const int N = 5000;
const int X = 1000000000;

struct Input {
	int n;
	int b;
	int c[N], d[N];
	vi e[N];
	
	bool read () {
		if (!(cin >> n >> b)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d%d", &c[i], &d[i]);
			if (i) {
				int pr;
				scanf("%d", &pr);
				--pr;
				e[pr].pb(i);
			}
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans;
	
	void write () {
		cout << ans << endl;
	}
};


namespace Main {
	const int inf = X + 1;
	
	struct Solution: Data {
		int cnt[N];
		
		ve<pii> dfs (int v) {
			cnt[v] = 1;
			ve<pii> res(2);
			res[0] = mp(0, inf);
			res[1] = mp(c[v], c[v] - d[v]);
			for (int to : e[v]) {
				ve<pii> cur = dfs(to);
				
				ve<pii> tmp;
				tmp.swap(res);
				res.assign(cnt[v] + cnt[to] + 1, mp(inf, inf));
				
				forn (i, cnt[v] + 1) {
					forn (j, cnt[to] + 1) {
						umn(res[i + j].fs, tmp[i].fs + cur[j].fs);
						umn(res[i + j].sc, tmp[i].sc + cur[j].fs);
						umn(res[i + j].sc, tmp[i].sc + cur[j].sc);
					}
				}
				
				cnt[v] += cnt[to];
			}
			return res;
		}
		
		void solve () {
			ve<pii> res = dfs(0);
			ans = 0;
			forn (i, n + 1) {
				if (min(res[i].fs, res[i].sc) <= b) {
					umx(ans, i);
				}
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
		sol.clear();
	}
	*/
	
	return 0;
}