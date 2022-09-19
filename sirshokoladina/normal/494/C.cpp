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

const int M = 100000;
const int N = 5000;

struct Input {
	int m, n;
	int a[M];
	int l[N], r[N];
	ld p[N];
	
	bool read () {
		if (!(cin >> m >> n)) {
			return 0;
		}
		forn (i, m) {
			scanf("%d", &a[i]);
		}
		forn (i, n) {
			double p_;
			scanf("%d%d%lf", &l[i], &r[i], &p_);
			--l[i];
			p[i] = p_;
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
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	vi op[M + 1];
	int cl[M + 1];
	vi num;
	int mx[N + 1];
	int mxx;
	vi e[N + 1];
	
	ve<ld> uni (ve<ld> a, ve<ld> b) {
		deepen();
		debug(a);
		debug(b);
		int n = max(sz(a), sz(b));
		if (!n) {
			return a;
		}
		a.resize(n, 0);
		b.resize(n, 0);

		forn (i, n - 1) {
			a[i + 1] += a[i];
		}
		ld da = 1 - a[n - 1];
		forn (i, n) {
			a[i] += da;
		}
		

		forn (i, n - 1) {
			b[i + 1] += b[i];
		}
		ld db = 1 - b[n - 1];
		forn (i, n) {
			b[i] += db;
		}
		
		forn (i, n) {
			a[i] *= b[i];
		}
		
		ford (i, n - 1) {
			a[i + 1] -= a[i];
		}
		a[0] -= da * db;
		
		debug(a);
		return a;
	}
	
	ve<ld> calc (int v, int from) {
		deepen();
		debug(mp(v, from));
		ve<ld> res;
		if (mx[v] >= from) {
			res.resize(mx[v] - from, 0);
			res.pb(1);
		}
		forn (i, sz(e[v])) {
			int to = e[v][i];
			ve<ld> cur = calc(to, from - 1);
			forn (i, sz(cur)) {
				if (i) {
					cur[i - 1] += cur[i] * (1 - p[to]);
				}
				cur[i] *= p[to];
			}
			res = uni(res, cur);
		}
		debug(res);
		return res;
	}
	
	void solve () {
		forn (i, n) {
			num.pb(i);
		}
		sort(all(num), [&] (int i, int j) {
			return r[i] - l[i] > r[j] - l[j];
		});
		memset(cl, 0, sizeof cl);
		forn (i, n) {
			op[l[num[i]]].pb(num[i]);
			cl[r[num[i]]]++;
		}
		mxx = 0;
		forn (i, m) {
			umx(mxx, a[i]);
		}
		memset(mx, 0, sizeof mx);
		{
			vi q(1, n);
			forn (i, m) {
				forn (t, sz(op[i])) {
					q.pb(op[i][t]);
				}
				umx(mx[q.back()], a[i]);
				forn (t, cl[i + 1]) {
					int cur = q.back();
					q.pop_back();
					e[q.back()].pb(cur);
				}
			}
		}
		auto q = calc(n, mxx);
		ans = mxx;
		forn (i, sz(q)) {
			ans += i * q[i];
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