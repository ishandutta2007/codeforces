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

int n;
const int N = 200 * 1000 + 5;
int p[N], a[N], b[N];

int m;

inline bool read() {
	scanf("%d", &n);
	forn (i, n)
		scanf("%d", &p[i]);
	forn (i, n)
		scanf("%d", &a[i]);
	forn (i, n)
		scanf("%d", &b[i]);
	return true;
}
   
inline void solve() {   
	scanf("%d", &m);
	set<pt> s[4];
	forn (i, n) {
		s[a[i]].insert(mp(p[i], i));
		s[b[i]].insert(mp(p[i], i));
	}
	forn (i, m) {
		int color;
		scanf("%d", &color);
		if (s[color].empty()) {
			printf("-1 ");
			continue;
		}
		int cur = s[color].begin()->y;
		printf("%d ", p[cur]);
		s[a[cur]].erase(mp(p[cur], cur));
		s[b[cur]].erase(mp(p[cur], cur));
	}
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