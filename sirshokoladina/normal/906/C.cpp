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

const int N = 22;

struct Input {
	int n;
	int e[N];
	
	bool read () {
		int m;
		if (!(cin >> n >> m)) {
			return 0;
		}
		memset(e, 0, sizeof e);
		forn (i, n) {
			e[i] |= 1 << i;
		}
		forn (i, m) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			e[x] |= 1 << y;
			e[y] |= 1 << x;
		}
		return 1;
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
		vi v;
		
		int rev[1 << N];
		
		bool check (int msk) {
			v.clear();
			
			int cur = 0;
			forn (i, n) {
				if (msk & (1 << i)) {
					cur = 1 << i;
					break;
				}
			}
			
			while (1) {
				int www = cur & msk;
				if (!www) {
					break;
				}
				www ^= www - 1;
				int i = rev[(www + 1) / 2];
				msk -= 1 << i;
				cur |= e[i];
				v.pb(i);
			}
			
			return cur == (1 << n) - 1;
		}
		
		void solve () {
			forn (i, n) {
				rev[1 << i] = i;
			}
			
			bool ok = 1;
			forn (i, n) {
				ok &= (e[i] == (1 << n) - 1);
			}
			if (ok) {
				return;
			}
			int mn = n + 1;
			forn (msk, 1, 1 << n) {
				if (check(msk) && umn(mn, sz(v))) {
					ans = v;
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