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
const int X = 1000000000;

struct Input {
	int n, m, k;
	int a[N];
	vi v1, v2;
	
	bool read () {
		if (!(cin >> n >> m >> k)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
		}
		{
			int t;
			cin >> t;
			v1.resize(t);
			forn (i, t) {
				scanf("%d", &v1[i]);
				--v1[i];
			}
		}
		{
			int t;
			cin >> t;
			v2.resize(t);
			forn (i, t) {
				scanf("%d", &v2[i]);
				--v2[i];
			}
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ll ans;
	
	void write () {
		cout << ans << endl;
	}
};


namespace Main {
	typedef ve<vi> mask;
	
	struct Solution: Data {
		bool t1[N], t2[N];
		set<pii> s[2][2];
		set<pii, greater<pii> > q[2][2];
		
		ll sum;
		int tot;
		
		bool tuda (const mask &b) {
			int bst1, bst2;
			int mn = X + 1;
			forn (i, 2) {
				forn (j, 2) {
					if (b[i][j] && sz(s[i][j]) && umn(mn, s[i][j].begin()->fs)) {
						bst1 = i;
						bst2 = j;
					}
				}
			}
			if (mn == X + 1) {
				return 0;
			}
			sum += mn;
			tot++;
			q[bst1][bst2].insert(*s[bst1][bst2].begin());
			s[bst1][bst2].erase(s[bst1][bst2].begin());
			return 1;
		}
		
		bool suda (const mask &b) {
			int bst1, bst2;
			int mx = -X - 1;
			forn (i, 2) {
				forn (j, 2) {
					if (b[i][j] && sz(q[i][j]) && umx(mx, q[i][j].begin()->fs)) {
						bst1 = i;
						bst2 = j;
					}
				}
			}
			if (mx == -X - 1) {
				return 0;
			}
			sum -= mx;
			tot--;
			s[bst1][bst2].insert(*q[bst1][bst2].begin());
			q[bst1][bst2].erase(q[bst1][bst2].begin());
			return 1;
		}
		
		void solve () {
			memset(t1, 0, sizeof t1);
			memset(t2, 0, sizeof t2);
			forn (i, sz(v1)) {
				t1[v1[i]] = 1;
			}
			forn (i, sz(v2)) {
				t2[v2[i]] = 1;
			}
			forn (i, n) {
				s[t1[i]][t2[i]].insert(mp(a[i], i));
			}
			sum = 0;
			tot = 0;
			ans = -1;
			while (tot < m) {
				if (!tuda(mask({{0, 0}, {0, 1}}))) {
					break;
				}
			}
			while (sz(q[0][1]) + sz(q[1][1]) < k) {
				if (!tuda(mask({{0, 1}, {0, 0}}))) {
					debug();
					return;
				}
			}
			while (sz(q[1][0]) + sz(q[1][1]) < k) {
				if (!tuda(mask({{0, 0}, {1, 0}}))) {
					debug();
					return;
				}
			}
			if (tot > m) {
				debug();
				return;
			}
			while (tot < m) {
				if (!tuda(mask({{1, 1}, {1, 1}}))) {
					debug();
					return;
				}
			}
			
			ans = sum;
			
			while (sz(q[1][1])) {
				assert(suda(mask({{0, 0}, {0, 1}})));
				while (sz(q[0][1]) + sz(q[1][1]) < k) {
					if (!tuda(mask({{0, 1}, {0, 0}}))) {
						return;
					}
				}
				while (sz(q[1][0]) + sz(q[1][1]) < k) {
					if (!tuda(mask({{0, 0}, {1, 0}}))) {
						return;
					}
				}
				while (tot < m) {
					if (!tuda(mask({{1, 1}, {1, 0}}))) {
						return;
					}
				}
				while (tot > m) {
					if (!suda(mask({{1, sz(q[0][1]) + sz(q[1][1]) > k}, {sz(q[1][0]) + sz(q[1][1]) > k, 0}}))) {
						return;
					}
				}
				umn(ans, sum);
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