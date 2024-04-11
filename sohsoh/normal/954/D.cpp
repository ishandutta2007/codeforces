#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e3 + 10;
const ll INF = 1e8;

int n, m, s, t, dist[MAXN][MAXN];
vector<int> adj[MAXN];
bool E[MAXN][MAXN];

inline void BFS(int s) {
	queue<int> q;
	fill(dist[s], dist[s] + MAXN, INF);	
	dist[s][s] = 0;
	q.push(s);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : adj[v]) {
			if (dist[s][u] == INF) {
				dist[s][u] = dist[s][v] + 1;
				q.push(u);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		E[u][v] = E[v][u] = true;
	}

	for (int i = 1; i <= n; i++) BFS(i);
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (!E[i][j] && dist[s][i] + dist[j][t] + 1 >= dist[s][t] && dist[s][j] + dist[i][t] + 1 >= dist[s][t]) ans++;
	cout << ans << endl;
	return 0;
}