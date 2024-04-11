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

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 100000;

struct Input {
	ld ax, ay, bx, by, cx, cy;
	int n;
	ld x[N], y[N];
	
	bool read () {
		if (!(cin >> ax >> ay >> bx >> by >> cx >> cy >> n)) {
			return 0;
		}
		forn (i, n) {
			int xx, yy;
			scanf("%d%d", &xx, &yy);
			x[i] = xx;
			y[i] = yy;
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ld ans;
	
	void write () {
		cout << ans << endl;
	}
};

struct Solution: Data {
	ld vala[N + 1], valb[N + 1];
	int numa[N + 1], numb[N + 1];
	
	void solve () {
		ld sum = 0;
		
		forn (i, n) {
			sum += 2 * sqrtl(sqr(cx - x[i]) + sqr(cy - y[i]));
			vala[i] = sqrtl(sqr(ax - x[i]) + sqr(ay - y[i])) - sqrtl(sqr(cx - x[i]) + sqr(cy - y[i]));
			valb[i] = sqrtl(sqr(bx - x[i]) + sqr(by - y[i])) - sqrtl(sqr(cx - x[i]) + sqr(cy - y[i]));
		}
		vala[n] = valb[n] = 0;
		forn (i, n + 1) {
			numa[i] = numb[i] = i;
		}
		sort(numa, numa + n + 1, [&] (int i, int j) {
			return vala[i] < vala[j];
		});
		sort(numb, numb + n + 1, [&] (int i, int j) {
			return valb[i] < valb[j];
		});
		ans = 1e100;
		forn (t1, 2) {
			forn (t2, 2) {
				if (numa[t1] != numb[t2])
				umn(ans, sum + vala[numa[t1]] + valb[numb[t2]]);
			}
		}
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
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);
	sol.read();
	sol.solve();
	sol.write();
#endif
	return 0;
}