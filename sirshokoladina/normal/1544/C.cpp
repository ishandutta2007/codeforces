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

const int X = 100;

struct Input {
	int n;
	int a[X + 1], b[X + 1];
	
	bool read() {
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof a);
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			int x;
			scanf("%d", &x);
			a[x]++;
		}
		forn (i, n) {
			int x;
			scanf("%d", &x);
			b[x]++;
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans;

	void write() {
		cout << ans << endl;
	}
};


namespace Main {
	int calc(int a[X + 1], int m) {
		int res = 0;
		ford (i, X + 1) {
			int k = min(m, a[i]);
			res += i * k;
			m -= k;
		}
		return res;
	}
	
	struct Solution: Data {

		bool check(int k) {
			a[X] += k;
			b[0] += k;
			int take = n + k - (n + k) / 4;
			bool res = calc(a, take) >= calc(b, take);
			a[X] -= k;
			b[0] -= k;
			return res;
		}
		
		void solve() {
			int lb = 0, rb = n * 4;
			while (lb != rb) {
				int md = (lb + rb) / 2;
				if (check(md)) {
					rb = md;
				} else {
					lb = md + 1;
				}
			}
			ans = lb;
		}
		
		void clear() {
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
	#endif
	
	int t;
	cin >> t;
	forn (i, t) {
		sol.read();
		sol.solve();
		sol.write();
		sol.clear();
	}
	
	return 0;
}