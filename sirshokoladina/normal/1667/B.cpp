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

const int N = 500000;

struct Input {
	int n;
	int a[N];
	
	bool read() {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
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
	
	struct Solution: Data {
		ll pref_sum[N + 1];
		int pos[N + 1];
		int tree[4 * N + 100];
		int mem[N + 1];

		void upd(int v, int lb, int rb, int l, int r, int val) {
			if (lb >= r || rb <= l) {
				return;
			}
			if (lb >= l && rb <= r) {
				umn(tree[v], val);
				return;
			}
			upd(2 * v + 1, lb, (lb + rb) / 2, l, r, val);
			upd(2 * v + 2, (lb + rb) / 2, rb, l, r, val);
		}

		int get(int v, int lb, int rb, int l, int r) {
			if (lb >= r || rb <= l) {
				return 10 * n;
			}
			if (lb >= l && rb <= r) {
				return tree[v];
			}
			return min(tree[v], min(
				get(2 * v + 1, lb, (lb + rb) / 2, l, r),
				get(2 * v + 2, (lb + rb) / 2, rb, l, r)
			));
		}
		
		void solve() {
			pref_sum[0] = 0;
			forn (i, n) {
				pref_sum[i + 1] = pref_sum[i] + a[i];
			}
			debug(pref_sum, pref_sum + n + 1);
			{
				ve<ll> v(pref_sum, pref_sum + n + 1);
				map<ll, int> sum_to_ind;
				sort(all(v));
				v.erase(unique(all(v)), v.end());
				sum_to_ind.clear();
				forn (i, sz(v)) {
					sum_to_ind[v[i]] = i;
				}
				forn (i, n + 1) {
					pos[i] = sum_to_ind[pref_sum[i]];
				}
			}
			debug(pos, pos + n + 1);
			forn (i, 4 * n + 100) {
				tree[i] = 10 * n;
			}
			forn (i, n + 1) {
				mem[i] = -10 * n;
			}

			int last_val = 0;
			forn (i, n) {
				// debug(tree, tree + 4 * n + 10);
				upd(0, 0, n + 10, pos[i] + 1, n + 10, last_val);
				umx(mem[pos[i]], i - last_val);
				last_val += 2;
				umn(last_val, get(0, 0, n + 10, pos[i + 1], pos[i + 1] + 1));
				umn(last_val, i + 1 - mem[pos[i + 1]]);
				debug(mt(i + 1, last_val));
			}
			ans = n - last_val;
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