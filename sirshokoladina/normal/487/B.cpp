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
typedef unsigned int ui;
typedef unsigned char uc;
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

const int N = 100000;
const int X = 1000000000;

struct Input {
	int n, s, k;
	int a[N];
	
	bool read () {
		if (!(cin >> n >> s >> k)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
		}
		return 1;
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
	vi add[N + 1];
	vi del[N + 1];
	
	void solve () {
		deque<int> mn, mx;
		int r = 0;
		multiset<int> q;
		add[0].pb(0);
		del[0].pb(0);
		forn (l, n) {
			forn (i, sz(add[l])) {
				q.insert(add[l][i]);
			}
			while (r < n && max(sz(mx) ? a[mx.front()] : -X, a[r]) - min(sz(mn) ? a[mn.front()] : X, a[r]) <= s) {
				while (sz(mn) && a[mn.back()] >= a[r]) {
					mn.pop_back();
				}
				mn.pb(r);
				while (sz(mx) && a[mx.back()] <= a[r]) {
					mx.pop_back();
				}
				mx.pb(r);
				++r;
			}
			if (sz(q) && r - l >= k) {
				add[l + k].pb(*q.begin() + 1);
				del[r].pb(*q.begin() + 1);
			}
			while (sz(mn) && mn.front() == l) {
				mn.pop_front();
			}
			while (sz(mx) && mx.front() == l) {
				mx.pop_front();
			}
			forn (i, sz(del[l])) {
				q.erase(q.find(del[l][i]));
			}
		}
		forn (i, sz(add[n])) {
			q.insert(add[n][i]);
		}
		ans = (sz(q)) ? *q.begin() : -1;
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