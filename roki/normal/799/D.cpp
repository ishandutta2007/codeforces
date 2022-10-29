#include <bits/stdc++.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

int a, b, w, h, n;

const int N = 100 * 1000 + 5;
int v[N];

inline bool read() {
	cin >> a >> b >> h >> w >> n;
	forn (i, n)
		cin >> v[i];
	sort(v, v + n);
	reverse(v, v + n);
	n = min(n, 40);
	return true;
}

int dp[N];
vector<pt> c;
   
int ans = INF;

void rec(int ca, int cb, int pos, int take) {
	if (ca >= a && cb >= b) {
		ans = min(ans, take);
		return;
	}
	if (pos == sz(c))
		return;
	li x = c[pos].y;
	int need = 0;
	li add = 1;
	while(ca * add < a) {
		add *= x;
		need++;
	}
	add = 1;
	while(cb * add < b) {
		add *= x;
		need++;
	}
	if (need <= c[pos].x) {
		ans = min(ans, take + need);
		return;
	}
	vector<li> d(c[pos].x + 1);
	d[0] = 1;
	for (int i = 1; i < sz(d); ++i)
		d[i] = min((li)INF, d[i - 1] * x);
	if (cb < b)
		rec(ca, min((li)INF, cb * d[c[pos].x]), pos + 1, take + c[pos].x);
	forn (i, c[pos].x) {
		ca = min((li)INF, ca * x);
		int ncb = min((li)INF, cb * d[c[pos].x - 1 - i]);
		rec(ca, ncb, pos + 1, take + c[pos].x);
		if (ca >= a)
			break;
	}
}

inline void solve() {   
	int l = 0;
	while(l < n) {
		int r = l;
		while(r < n && v[r] == v[l])
			r++;
		c.pb(mp(r - l, v[l]));
		l = r;
	}
	rec(w, h, 0, 0);
	rec(h, w, 0, 0);
	if (ans == INF)
		ans = -1;
	cout << ans << endl;
}

int main()
{
#ifdef SU2
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));

	assert(read());
	solve();

#ifdef SU2
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}