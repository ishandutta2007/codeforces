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
	int n, x1, x2;
	int a[N];
	
	bool read () {
		if (!(cin >> n >> x1 >> x2)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool res;
	vi ans1, ans2;

	void write () {
		if (!res) {
			puts("No");
			return;
		}
		puts("Yes");
		printf("%d %d\n", sz(ans1), sz(ans2));
		forn (i, sz(ans1)) {
			if (i) {
				printf(" ");
			}
			printf("%d", ans1[i] + 1);
		}
		puts("");
		forn (i, sz(ans2)) {
			if (i) {
				printf(" ");
			}
			printf("%d", ans2[i] + 1);
		}
		puts("");
	}
};


namespace Main {
	
	struct Solution: Data {
		int num[N];
		int pos[N];

		void check () {
			int k1 = 1;
			while (k1 <= n) {
				int mn = (x1 + k1 - 1) / k1;
				int cnt = n - (int)(lower_bound(a, a + n, mn) - a);
				if (cnt >= k1) {
					break;
				}
				k1++;
			}
			if (k1 > n) {
				return;
			}
			int k2 = 1;
			while (k1 + k2 <= n) {
				int mn = (x2 + k2 - 1) / k2;
				int cnt = n - (int)(lower_bound(a, a + n, mn) - a);
				if (cnt >= k1 + k2) {
					break;
				}
				k2++;
			}
			if (k1 + k2 > n) {
				return;
			}
			res = true;
			forn (i, k1) {
				ans1.pb(num[n - 1 - i]);
			}
			forn (i, k2) {
				ans2.pb(num[n - k1 - 1 - i]);
			}
		}
		
		void solve () {
			iota(num, num + n, 0);
			sort(num, num + n, [&] (int i, int j) {
				return a[i] < a[j];
			});
			forn (i, n) {
				pos[num[i]] = i;
			}
			sort(a, a + n);
			res = false;
			check();
			if (res) {
				return;
			}
			swap(x1, x2);
			swap(ans1, ans2);
			check();
			swap(x1, x2);
			swap(ans1, ans2);
		}
		
		void clear () {
			*this = Solution();
		};
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