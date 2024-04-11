#include <bits/stdc++.h>
                                                   
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i < int(n); i++)
#define nfor(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forr(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define forft(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ms(a, v) memset(a, v, sizeof(a))
#define x first
#define y second
#define X first
#define Y second
#define ft first
#define sc second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 100 * 1000 + 5;
ld a[N], b[N];
int n;
ld p;

inline bool read() {
	cin >> n >> p;
	forn (i, n)
		cin >> a[i] >> b[i];
	return true;
}

ld c[N];

bool ok(ld t) {
	forn (i, n)
		c[i] = b[i] - t * a[i];
	forn (i, n) {
		if (c[i] < 0)
			t -= -c[i] / p;
	}
	return t >= 0;
}

inline void solve() {
	ld l = 0, r = 1e18;
	if (ok(r)) {
		cout << -1 << endl;
		return;
	}
	
	forn (it, 200) {
		ld mid = (l + r) / 2;
		if (ok(mid))
			l = mid;
		else
			r = mid;
	}
	cout << l << endl;
}

int main() {
#ifdef SU2_PROJ
	assert(freopen("input.txt", "rt", stdin));
	assert(freopen("output.txt", "wt", stdout));
#endif

	srand(time(NULL));

	cout << setprecision(10) << fixed;
	cerr << setprecision(5) << fixed;

	read();
	solve();

#ifdef SU2_PROJ
	cerr << "Time: " << clock() << endl;
#endif
	
	return 0;
}