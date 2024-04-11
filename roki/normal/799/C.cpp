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

vector<pt> diamond;
vector<pt> coin;

int n, C, D;

inline bool read() {
	scanf("%d%d%d", &n, &C, &D);
	forn (i, n) {
		pt p;
		scanf("%d%d", &p.y, &p.x);
		char c;
		cin >> c;
		if (c == 'C')
			coin.pb(p);
		else
			diamond.pb(p);
	}
	return true;
}
   
int get(vector<pt> &v, int w) {
	int ans = -INF;
	for (pt p : v)
		if (p.x <= w)
			ans = max(ans, p.y);
	return ans;
}

int both(vector<pt> &v, int w) {

	if (sz(v) == 0)
		return -INF;

	vector<int> maxi(sz(v));
	maxi[0] = v[0].y;
	for (int i = 1; i < sz(v); ++i) {
		maxi[i] = max(maxi[i - 1], v[i].y);
	}	
	int r = 0;
	
	int ans = -INF;
	
	for (int i = 1; i < sz(v); ++i) {
		if (v[i].x + v[i - 1].x <= w)
			r = i - 1;
		while(r >= 0 && v[i].x + v[r].x > w) 
			r--;
		if (r >= 0)
			ans = max(ans, v[i].y + maxi[r]);	
	}

	return ans;
}

inline void solve() {
	sort(all(coin));
	sort(all(diamond));
	
	int ans = 0;
	
	{
		int bc = get(coin, C);
		int bd = get(diamond, D);
		ans = max(ans, bc + bd);
	}
	
	ans = max(ans, both(coin, C));
	ans = max(ans, both(diamond, D));
	
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