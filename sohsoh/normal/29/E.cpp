#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
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

const int MAXN = 500 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, dist[MAXN][MAXN];
vector<int> adj[MAXN];
queue<pair<int, int>> q;
pair<int, int> par[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) dist[i][j] = INF;
	q.push({1, n});
	dist[1][n] = 0;
	while (!q.empty()) {
		int v = q.front().X, u = q.front().Y;
		q.pop();
		for (int v_a : adj[v]) {
			for (int u_a : adj[u]) {
				if (dist[v_a][u_a] == INF && v_a != u_a) {
					dist[v_a][u_a] = dist[v][u] + 1;
				       	par[v_a][u_a] = {v, u};
					q.push({v_a, u_a});	
				}
			}
		}
	}

	if (dist[n][1] == INF) return printf("%d \n", -1), 0;
	printf("%d \n", dist[n][1]);

	vector<pair<int, int>> ans;
	pair<int, int> v = {n, 1};
	while (par[v.X][v.Y].X > 0) {
		ans.push_back(v);
		v = par[v.X][v.Y];
	}

	ans.push_back({1, n});
	reverse(all(ans));
	for (pair<int, int> e : ans) printf("%d ", e.X);
	printf("\n");
	for (pair<int, int> e : ans) printf("%d ", e.Y);
	printf("\n");
	return 0;
}