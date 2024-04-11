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

const int K = 4;
const int M = 500;
const int N = 1 << K;

const ll mod = 1000000007;

struct Input {
	string s;
	int n;
	int a[N][K], b[N];
	
	bool read () {
		while (!sz(s)) {
			if (!getline(cin, s)) {
				return 0;
			}
		}
		cin >> n;
		forn (i, n) {
			forn (j, K) {
				scanf("%d", &a[i][j]);
			}
			scanf("%d", &b[i]);
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
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	void calc_ch (char c, ve<ll> &res) {
		int msk = 0;
		bool x = (c >= 'a' && c <= 'z');
		int id = x ? (c - 'a') : (c - 'A');
		forn (i, N) {
			if (bool(i & (1 << id)) ^ x) {
				msk |= 1 << i;
			}
		}
		(res[msk] += 1) %= mod;
	}
	
	void calc_op (array<ve<ll>, 2> &&v, char c, ve<ll> &res) {
		if (c == '&') {
			forn (j, 1 << (N - 1)) {
				forn (i, 2) {
					swap(v[i][j], v[i][((1 << N) - 1) ^ j]);
				}
				swap(res[j], res[((1 << N) - 1) ^ j]);
			}
			calc_op(move(v), '|', res);
			forn (j, 1 << (N - 1)) {
				swap(res[j], res[((1 << N) - 1) ^ j]);
			}
			return;
		}
		forn (i, N) {
			forn (k, 2) {
				forn (j, 1 << N) {
					if (j & (1 << i)) {
						v[k][j] += v[k][j - (1 << i)];
					}
				}
			}
		}
		forn (i, 1 << N) {
			v[0][i] %= mod;
			v[0][i] += mod;
			v[0][i] %= mod;
			v[1][i] %= mod;
			v[1][i] += mod;
			v[1][i] %= mod;
		}
		forn (i, 1 << N) {
			(v[0][i] *= v[1][i]) %= mod;
		}
		forn (i, N) {
			forn (j, 1 << N) {
				if (j & (1 << i)) {
					v[0][j] += mod - v[0][j - (1 << i)];
				}
			}
		}
		forn (i, 1 << N) {
			(res[i] += v[0][i]) %= mod;
			res[i] += mod;
			res[i] %= mod;
		}
	}
	
	ve<ll> calc (int l, int r) {
		ve<ll> res(1 << N, 0);
		if (r - l == 1) {
			if (s[l] == '?') {
				for (char c : string("abcdABCD")) {
					calc_ch(c, res);
				}
			} else {
				calc_ch(s[l], res);
			}
			return res;
		}
		int mid;
		int sum = 0;
		for (mid = l; s[mid] == '(' || s[mid] == ')' || sum; ++mid) {
			if (s[mid] == '(') {
				sum++;
			}
			if (s[mid] == ')') {
				sum--;
			}
		}
		array<ve<ll>, 2> v;
		if (mid - l > r - mid) {
			v[0] = calc(l + 1, mid - 1);
			v[1] = calc(mid + 2, r - 1);
		} else {
			v[0] = calc(mid + 2, r - 1);
			v[1] = calc(l + 1, mid - 1);
		}
		if (s[mid] == '?') {
			for (char c : string("|&")) {
				calc_op(array<ve<ll>, 2>(v), c, res);
			}
		} else {
			calc_op(move(v), s[mid], res);
		}
		return res;
	}
	
	void solve () {
		ve<ll> v = calc(0, sz(s));
		ans = 0;
		forn (msk, 1 << N) {
			bool ok = 1;
			forn (i, n) {
				int pos = 0;
				forn (j, K) {
					pos |= a[i][j] << j;
				}
				if (bool(msk & (1 << pos)) != b[i]) {
					ok = 0;
				}
			}
			if (ok) {
				(ans += v[msk]) %= mod;
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
	sol.read();
	sol.solve();
	sol.write();
#endif
	return 0;
}