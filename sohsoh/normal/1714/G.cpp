#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll LOG = 20;

ll par[MAXN][LOG], A[MAXN], ps[MAXN], n, H[MAXN];
vector<int> adj[MAXN];

void dfs(int v) {
	H[v] = H[par[v][0]] + 1;
	A[v] += A[par[v][0]];
	ps[v] += ps[par[v][0]];

	for (int u : adj[v])
		dfs(u);
}

inline void solve() {
	for (int i = 0; i < n + 10; i++)
		adj[i].clear();

	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> par[i][0];
		adj[par[i][0]].push_back(i);
		cin >> A[i] >> ps[i];
	}

	dfs(1);
	for (int i = 1; i < LOG; i++)
		for (int v = 1; v <= n; v++)
			par[v][i] = par[par[v][i - 1]][i - 1];

	for (int v = 2; v <= n; v++) {
		int u = v;
		for (int i = LOG - 1; i >= 0; i--)
			if (ps[par[u][i]] > A[v])
				u = par[u][i];
		
		cout << (ps[u] > A[v] ? H[par[u][0]] : H[u]) - 1 << sep;
	}

	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}