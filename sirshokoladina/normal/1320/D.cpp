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
const int Q = 200000;

struct Input {
	int n;
	string s;
	int q;
	int l1[Q], l2[Q], len[Q];
	
	bool read() {
		if (!(cin >> n)) {
			return 0;
		}
		getline(cin, s);
		getline(cin, s);
		cin >> q;
		forn (i, q) {
			scanf("%d%d%d", &l1[i], &l2[i], &len[i]);
			--l1[i];
			--l2[i];
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool ans[Q];
	
	void write() {
		forn (i, q) {
			puts(ans[i] ? "Yes" : "No");
		}
	}
};


namespace Main {
	const int K = 8;
	
	struct Solution: Data {
		vi pos;
		int ss;
		bool a[2][N];
		uc b[2][K][(N + K - 1) / K];

		
		void solve() {
			forn (i, n) {
				if (s[i] == '0') {
					pos.pb(i);
				}
			}
			ss = sz(pos);
			forn (t, 2) {
				forn (i, ss) {
					a[t][i] = (pos[i] & 1) ^ t;
				}
			}
			memset(b, 0, sizeof b);
			forn (t, 2) {
				forn (j, K) {
					forn (i, ss - j + 1) {
						b[t][j][i / K] ^= uc(a[t][j + i] << (i % K));
					}
				}
			}
			forn (i, q) {
				int L1 = lower_bound(all(pos), l1[i]) - pos.begin();
				int R1 = lower_bound(all(pos), l1[i] + len[i]) - pos.begin();
				int L2 = lower_bound(all(pos), l2[i]) - pos.begin();
				int R2 = lower_bound(all(pos), l2[i] + len[i]) - pos.begin();
				bool t1 = l1[i] & 1;
				bool t2 = l2[i] & 1;
				debug(a[t1] + L1, a[t1] + R1);
				debug(a[t2] + L2, a[t2] + R2);
				if (R1 - L1 != R2 - L2) {
					ans[i] = 0;
					continue;
				}
				ans[i] = 1;
				while ((R1 - L1) % K) {
					if (a[t1][L1] != a[t2][L2]) {
						ans[i] = 0;
						break;
					}
					++L1;
					++L2;
				}
				if (!ans[i]) {
					continue;
				}
				ans[i] = 0 == memcmp(b[t1][L1 % K] + (L1 / K), b[t2][L2 % K] + (L2 / K), (R1 - L1) / K);
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