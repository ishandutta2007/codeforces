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
const int N = 1000 * 1000;
string s;

inline bool read() {
	cin >> n >> s;
	return true;
}

int used[N];
bool f[N];   

bool dfs(int v) {
	used[v] = 1;
	int to = v + 1;
	if (s[v] == '<')
		to = v - 1;
	if (to < 0 || to >= n) {
		used[v] = 2;
		return f[v] = true;
	}
	if (used[to] == 1) {
		used[v] = 2;
		return f[v] = false;
	}
	if (used[to] == 2) {
		used[v] = 2;
		return f[v] = f[to];
	}
	f[v] = dfs(to);
	used[v] = 2;
	return f[v];
}

inline void solve() {
   int ans = 0;
   forn (i, n)
  	 	dfs(i);
  	forn (i, n)
  		ans += f[i];
  	cout << ans << endl;
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