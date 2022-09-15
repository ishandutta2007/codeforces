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

const int N = 1000010;
const int M = 10010;
const int G = 1010;

struct Input {
	int n, m, g, r;
	int a[M];
	
	bool read() {
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, m) {
			scanf("%d", &a[i]);
		}
		cin >> g >> r;
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
	const int D = 2 * N * G;
	const int B = 64;
	const int C = 2 * G + 1;
	
	struct Solution: Data {
		int cnt[D / B + 1];
		ve<pii> q[C];
		pii pos[M][G + 1];

		void set_d(int i, int j, int t) {
			debug(mt(i, j, t));
			int &cur_t = pos[i][j].fs;
			int &cur_p = pos[i][j].sc;
			if (cur_t != -1 && cur_t <= t) {
				return;
			}
			if (cur_t != -1) {
				--cnt[cur_t / B];
				ve<pii> &cur_q = q[cur_t % C];
				auto lst = cur_q.back();
				cur_q.pop_back();
				pos[lst.fs][lst.sc].sc = cur_p;
				cur_q[cur_p] = lst;
			}
			{
				cur_t = t;
				ve<pii> &cur_q = q[cur_t % C];
				cur_p = sz(cur_q);
				cur_q.pb(mp(i, j));
				++cnt[cur_t / B];
			}
		}
		
		void solve() {
			sort(a, a + m);
			memset(pos, -1, sizeof pos);
			set_d(0, 0, 0);
			ans = -1;
			for (int t = 0; t < D; ) {
				{
					deepen(t < 50);
					debug(t);
				}
				if (!cnt[t / B]) {
					t += B - t % B;
					continue;
				}
				ve<pii> &cur_q = q[t % C];
				if (!sz(cur_q)) {
					++t;
					continue;
				}
				auto lst = cur_q.back();
				int i = lst.fs;
				int j = lst.sc;
				assert(j == t % (g + r));
				cur_q.pop_back();
				--cnt[t / B];
				if (i == m - 1) {
					ans = t;
					return;
				}
				if (j == g) {
					set_d(i, 0, t + r);
				}
				if (i > 0 && j + (a[i] - a[i - 1]) <= g) {
					set_d(i - 1, j + (a[i] - a[i - 1]), t + (a[i] - a[i - 1]));
				}
				if (i + 1 < m && j + (a[i + 1] - a[i]) <= g) {
					set_d(i + 1, j + (a[i + 1] - a[i]), t + (a[i + 1] - a[i]));
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