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

const int N = 1000 * 1000 + 5;
pt p[N];
int n, m, k;

set<int> a[N];

inline bool read() {
	cin >> n >> m >> k;
	forn (i, k)
		cin >> p[i].x >> p[i].y;
	return true;
}
   
li ans[N];

inline void solve() {   

	forn (i, N)
		ans[i] = -1;
	set<pair<pt, pt> > used;
	
	forn (i, k) {
		a[p[i].x + p[i].y].insert(i);
		a[2 * (n + m) + p[i].x - p[i].y].insert(i);
	}
	
	int x = 0, y = 0;
	int dx = 1, dy = 1;
	for (int i = -1; i <= 1; ++i)
		for (int j = -1; j <= 1; ++j) {
			used.insert(mp(mp(0, m), mp(i, j)));
			used.insert(mp(mp(n, m), mp(i, j)));
			used.insert(mp(mp(n, 0), mp(i, j)));
			if (i != 1 || j != 1)
				used.insert(mp(mp(0, 0), mp(i, j)));	
		}
		
	li curt = 0;
		
	while(!used.count(mp(mp(x, y), mp(dx, dy)))) {
		used.insert(mp(mp(x, y), mp(dx, dy)));
		int tx = dx == 1 ? n - x : x;
		int ty = dy == 1 ? m - y : y;
		int t = min(tx, ty);
		
		int id1 = x + y;
		for (int id : a[id1]) {
			ans[id] = curt + (p[id].x - x) / dx;
			int _id = 2 * (n + m) + p[id].x - p[id].y;
			a[_id].erase(id);		
		}
		a[id1].clear();
		
		int id2 = 2 * (n + m) + x - y;
		for (int id : a[id2]) {
			ans[id] = curt + (p[id].x - x) / dx;
			int _id = p[id].x + p[id].y;
			a[_id].erase(id);		
		}
		a[id2].clear();
		
		x += dx * t;
		y += dy * t;
		curt += t;
//		cerr << x << ' ' << y << endl;
		if (x == 0 || x == n)
			dx *= -1;
		else
			dy *= -1;
	}
	forn (i, k)
		cout << ans[i] << endl;
}

int main()
{
#ifdef _DEBUG
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));

	assert(read());
	solve();

#ifdef _DEBUG
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}