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

inline bool read() {
	cin >> n;
	return true;
}

const int N = 1005;
int ans[N];
bool x[N][N];

int cnt = 0;

void mq(bitset<N> &q) {
	vector<int> v;
	forn (i, n)
		if (q[i])
			v.pb(i + 1);
	
	if (sz(v) == 0)
		return;
	
	cout << sz(v) << endl;
	forn (i, sz(v))
		cout << v[i] << ' ';
	cout << endl;
			
	forn (i, n) {
		int t;
		cin >> t;
		if (!q[i])
			ans[i] = min(ans[i], t);
	}
}

bitset<N> ask[N];

void q(int lvl, int lx, int rx) {
	if (lx == rx)
		return;
	int midx = (lx + rx) / 2;
	
	for (int i = lx; i <= midx; ++i)
		ask[2 * lvl][i] = true;
	for (int i = midx + 1; i <= rx; ++i)
		ask[2 * lvl + 1][i] = true;
	
	q(lvl + 1, lx, midx);
	q(lvl + 1, midx + 1, rx);
}
   
inline void solve() {   
	forn (i, N)
		ans[i] = INF;
	q(0, 0, n - 1);
	forn (i, 20)
		mq(ask[i]);			
	
	cout << -1 << endl;
	
	forn (i, n)
		cout << ans[i] << ' ';
	cout.flush();
}

int main()
{

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