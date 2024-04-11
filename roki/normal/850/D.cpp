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
const int N = 33;
int a[N];

inline bool read() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	return true;
}
	
bool dp[2 * N][4 * N * N][N];
int from[2 * N][4 * N * N][N];

inline void solve() {
	sort(a, a + n);
	 dp[0][0][0] = true;
	 forn (i, 2 * N - 1)
	 	forn (prev, 4 * N * N)
	 		forn (last, n) {
	 			if (!dp[i][prev][last])
	 				continue;
	 			if (prev - i + a[last] >= 0) {
	 				dp[i + 1][prev - i + a[last]][last] = true;
	 				from[i + 1][prev - i + a[last]][last] = last;
	 			}
	 			if (prev - i + a[last] >= 0) {
	 				dp[i + 1][prev - i + a[last]][last + 1] = true;
	 				from[i + 1][prev - i + a[last]][last + 1] = last;
	 			}
	 		} 
	 int m = -1;
	 		
	 for (int i = 1; i < 2 * N; ++i) {
	 	if (dp[i][0][n]) {
	 		m = i;
	 		break;
	 	}
	 }
	 
	 if (m == -1) {
	 	cout << "=(" << endl;
	 	return;
	 }
	 
	 vector<int> ans;
	 
	 int last = n;
	 int sum = 0;
	 
	 while(m) {
	 	last = from[m][sum][last];
	 	ans.pb(a[last]);
	 	m--;
	 	sum = sum + m - a[last];
	 }
	 
	 int s = 0;
	 for (int x : ans)
	 	s += x;
	
	 cerr << s << ' ' << sz(ans) * (sz(ans) - 1) / 2 << endl;
	
	reverse(all(ans));
	for (int x : ans)
		cerr << x << ' ';
	cerr << endl;
	
	
	int g[2 * N][2 * N];
	memset(g, 0, sizeof g);
	
	vector<pt> v;
	forn (i, sz(ans)) {
		v.pb(mp(ans[i], i));
	}		
	
	int it = sz(v);
	
	forn (i, it) {
		sort(all(v));
		forn (j, sz(v))
			cerr << v[j].x << ' ';
		cerr << endl;
		for (int j = 1; j < sz(v); ++j) {
			if (v[0].x) {
				v[0].x--;
				g[v[0].y][v[j].y] = true;
			} else {
				v[j].x--;
				g[v[j].y][v[0].y] = true;
			}
		}
		v.erase(v.begin());
	}
	cout << it << endl;
	forn (i, it) {
		forn (j, it) {
			cout << g[i][j];
			//assert(g[i][j] != g[j][i]);
		}
		cout << endl;
	}
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

	read();
	solve();

#ifdef _DEBUG
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}