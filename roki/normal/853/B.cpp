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

int n, m, k;

const int N = 1000 * 1000 + 5;
struct edge {
	int from, to, cost;
	edge(int f, int t, int c) {
		from = f, to = t, cost = c;
	}
};
vector<edge> e[N];

inline bool read() {
	cin >> n >> m >> k;
	forn (i, m) {
		int d, f, t, c;
		cin >> d >> f >> t >> c;
		e[d].pb(edge(f, t, c));
	}
	return true;
}

void upd(int d[N], int & cnt, li & sum, int v, int dist) {
	if (d[v] == INF) {
		cnt++;
	}
	sum -= d[v];
	d[v] = min(d[v], dist);
	sum += d[v];
}

li prefsum[N];
int prefd[N];
li sufsum[N];
int sufd[N];
bool ok[N];

inline void solve() {   
	forn (i, N)
		prefd[i] = sufd[i] = INF;
	forn (i, N)
		prefsum[i] = sufsum[i] = li(n) * INF;
	
	int cnt = 0;
	
	forn (i, N) {
		if (i)
			prefsum[i] = prefsum[i - 1];
		for (auto ce : e[i]) {
			int v = ce.from;
			if (v == 0)
				continue;
			int d = ce.cost;
			upd(prefd, cnt, prefsum[i], v, d);
		}
		ok[i] = cnt == n;
	}
	
	cnt = 0;
	
	li sum = li(n) * INF;
	
	li ans = INF64;
	
	for (int i = N - 1; i >= 0; --i) {
		for (auto ce : e[i]) {
			int v = ce.to;
			if (v == 0)
				continue;
			int d = ce.cost;
			upd(sufd, cnt, sum, v, d);
			if (cnt == n && i - 1 - k >= 0 && ok[i - 1 - k]) {
				ans = min(ans, prefsum[i - 1 - k] + sum);
			}
		}
	}
	if (ans > li(n) * INF)
		ans = -1;
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

	read();
	solve();

#ifdef _DEBUG
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}