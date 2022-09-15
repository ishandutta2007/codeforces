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

const int N = 100000;
const int M = 1800000;

struct Input {
	string s;
	
	bool read() {
		return !!(cin >> s);
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	vi ans;
	
	void write() {
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
		vi sum;
		vi t[2];

		int go(int k, int pos) {
			if (k < 2) {
				return pos;
			}
			int lk = k / 2;
			int rk = k - lk;
			pos = go(lk, pos);
			if (pos > sz(s)) {
				return pos;
			}
			pos = go(rk, pos);
			if (pos > sz(s)) {
				return pos;
			}
			int k0 = pos - sum[pos] + lk;
			int k1 = sum[pos] + rk;
			int r0 = (k0 > sz(t[0])) ? sz(s) : t[0][k0 - 1];
			int r1 = (k1 > sz(t[1])) ? sz(s) : t[1][k1 - 1];
			return min(r0, r1) + 1;
		}

		vi a;
		vi b;

		void merge_sort(int l, int r, int &pos) {
			if (r - l < 2) { 
				return;
			}
			int m = (l + r) / 2;
			merge_sort(l, m, pos);
			merge_sort(m, r, pos);
			for (int i = l, j = m, k = l; i < m || j < r; ) {
				if (j == r || (i < m && s[pos++] == '0')) {
					b[k++] = a[i++];
				} else {
					b[k++] = a[j++];
				}
			}
			forn (i, l, r) {
				a[i] = b[i];
			}
		}
		
		void solve() {
			sum.pb(0);
			forn (i, sz(s)) {
				sum.pb(sum.back() + (s[i] - '0'));
				t[s[i] - '0'].pb(i);
			}
			int lb = 0, rb = N;
			while (lb != rb) {
				int md = (lb + rb) / 2;
				if (go(md, 0) < sz(s)) {
					lb = md + 1;
				} else {
					rb = md;
				}
			}
			int n = lb;
			a.resize(n);
			b.resize(n);
			iota(all(a), 0);
			int pos = 0;
			merge_sort(0, n, pos);
			assert(pos == sz(s));
			ans.resize(n);
			forn (i, n) {
				ans[a[i]] = i;
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