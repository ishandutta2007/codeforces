//: // ////: ///  / : //// / :
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

int n, sz[MAXN], D[MAXN];
bool R[MAXN];
vector<int> adj[MAXN];

int dfs(int v, int p) {
	sz[v] = 1;
	for (int u : adj[v])
		if (!R[u] && u != p)
			dfs(u, v), sz[v] += sz[u];

	return sz[v];
}

int find(int v, int p, int s) {
	for (int u : adj[v])
		if (!R[u] && u != p && sz[u] * 2 > s)
			return find(u, v, s);
	return v;
}

void centroid(int v, int val) {
	int c = find(v, 0, dfs(v, 0));
	D[c] = val;
	R[c] = true;
	
	for (int u : adj[c])
		if (!R[u])
			centroid(u, val + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	centroid(1, 0);
	for (int i = 1; i <= n; i++)
		cout << char(D[i] + 'A') << sep;
	cout << endl;
	return 0;
}