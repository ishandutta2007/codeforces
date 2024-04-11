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
typedef pair<ld, ld> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

int n;
const int N = 1000 + 5;
pt p[N];

inline bool read() {
	cin >> n;
	forn (i, n)
		cin >> p[i].x >> p[i].y;	
	return true;
}

bool ok(ld r) {
	forn (i, n) {
		int nt = (i + 2) % n;
		ld ang = atan2(p[nt].y - p[i].y, p[nt].x - p[i].x);
		ang += PI / 2;
		pt v = mp(p[i].x + cos(ang) * r, p[i].y + sin(ang) * r);
		pt u = mp(v.x + p[nt].x - p[i].x, v.y + p[nt].y - p[i].y);
		ld a = u.y - v.y, b = v.x - u.x;
		a = -a, b = -b;
		ld c = -(u.x * a + u.y * b);
		int j = (i + 1) % n;
		ld d = (a * p[j].x + b * p[j].y + c) / sqrt(sqr(a) + sqr(b));
		if (d - r < 0)
			return true;
	}
	return false;
}


inline void solve() {
	ld l = 0, r = INF64;
	forn (it, 200) {
		ld mid = (l + r) / 2;
		if (ok(mid))
			r = mid;
		else
			l = mid;
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