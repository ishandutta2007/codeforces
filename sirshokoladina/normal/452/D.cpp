#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
#else
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
#endif

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define forv(i,v) for (auto i = v.begin(); i != v.end(); ++i)
#define forr(i,v) for (auto i = v.end(); i != v.begin() && (--i, 1); )
#define ve vector
#define pa pair
#define tu tuple
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T> inline T abs (T x) {return x > T() ? x : -x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int K = 10000;
const int T = 1000;

struct Input {
	int k, n[3], t[3];
	bool read () {
		return cin >> k >> n[0] >> n[1] >> n[2] >> t[0] >> t[1] >> t[2];
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
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	static const int X = K * T + 1;
	
	int a[X];

	void solve () {
		int q[3] = {0, 0, 0};
		int cur = 0;
		memset(a, 0, sizeof a);
		forn (i, k) {
			while (1) {
				bool ok = 1;
				forn (j, 3) {
					if (q[j] == n[j]) {
						ok = 0;
						break;
					}
				}
				if (!ok) {
					++cur;
					forn (j, 3) {
						if (cur >= t[j]) {
							q[j] -= a[cur - t[j]];
						}
					}
					continue;
				}
				++a[cur];
				forn (j, 3) {
					++q[j];
				}
				break;
			}
		}
		ans = cur + t[0] + t[1] + t[2];
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
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
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
	return 0;
}