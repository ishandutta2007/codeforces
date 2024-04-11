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
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 1000000;
const int M = 50;

struct Input {
	int n, m;
	int a[2 * N];
	ll b[M];
	
	bool read () {
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
		}
		forn (i, m) {
			cin >> b[i];
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans[M];
	
	void write () {
		forn (i, m) {
			cout << ans[i] << endl;
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	int go[2 * N + 1];
	int b[N + 1];
	
	void solve () {
		memcpy(a + n, a, n * sizeof(int));
		forn (t, m) {
			{
				ll s = 0;
				int r = 2 * n;
				go[r] = r;
				ford (l, 2 * n) {
					s += a[l];
					while (s > Data::b[t]) {
						--r;
						s -= a[r];
					}
					go[l] = r;
				}
			}
			b[0] = 0;
			ans[t] = 0;
			while (b[ans[t]] < n) {
				b[ans[t] + 1] = go[b[ans[t]]];
				ans[t]++;
			}
			if (ans[t] == 1) {
				continue;
			}
			int bst = 0, mn = n;
			forn (i, ans[t] - 1) {
				if (umn(mn, b[i + 1] - b[i])) {
					bst = i;
				}
			}
			forn (i, b[bst], b[bst + 1] + 1) {
				int pos = i;
				forn (j, ans[t] - 1) {
					pos = go[pos];
				}
				if (pos >= i + n) {
					ans[t]--;
					break;
				}
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