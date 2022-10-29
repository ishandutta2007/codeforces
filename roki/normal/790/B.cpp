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

const int N = 200 * 1000 + 5;
int n, k;
vector<int> g[N];

inline bool read() {
	cin >> n >> k;
	forn (i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	return true;
}

li dp[N][5];
int cnt[N][5];
li ans = 0;   

void dfs(int v, int p) {
	cnt[v][0] = 1;
	dp[v][0] = 0;
	for (int to : g[v]) {
		if (to == p)
			continue; 
		dfs(to, v);
		li tmp[5];
		int pcnt[5];
		forn (i, k) {
			pcnt[i] = cnt[to][(i + k - 1) % k];
			tmp[i] = dp[to][(i + k - 1) % k] + cnt[to][(i + k - 1) % k]; 
		}
		forn (i, k)
			forn (j, k) {
				li x = (dp[v][i] - cnt[v][i] * i) / k;
				if (i)
					x += cnt[v][i];
				li y = (tmp[j] - pcnt[j] * j) / k;
				if (j)
					y += pcnt[j];
				ans += x * pcnt[j];
				ans += y * cnt[v][i];
				if ((k - i) % k + (k - j) % k >= k)
					ans -= li(pcnt[j]) * cnt[v][i];
			}
		forn (i, k) {
			dp[v][i] += tmp[i];
			cnt[v][i] += pcnt[i];
		}
	}
}

inline void solve() {   
	dfs(0, -1);
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