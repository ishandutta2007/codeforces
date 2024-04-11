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

const ll MAXN = 600 + 10;
const ll INF = 8e18;
const ll MOD = 998244353;


int dist[MAXN][MAXN], par[MAXN][MAXN], n, m;
bool U[MAXN][MAXN], in_P[MAXN];
vector<int> adj[MAXN];
ll ans[MAXN], t_dist[MAXN];

inline void BFS(int s) {
	memset(dist[s], 63, sizeof dist[s]);
	dist[s][s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		int d_v = dist[s][v];
		
		for (int u : adj[v]) {
			if (d_v + 1 < dist[s][u]) {
				dist[s][u] = d_v + 1;
				q.push(u);
				U[s][u] |= U[s][v];
				par[s][u] = v;
			} else if (d_v == t_dist[u]) U[s][u] = true;
		}		
	}
}

inline ll Ans(int v, int u) {
	if (U[v][u]) return 0;
	
	memset(ans, 0, sizeof ans);
	memset(in_P, false, sizeof in_P);
	memset(t_dist, 63, sizeof t_dist);
	queue<int> q;
	
	in_P[v] = in_P[u] = true;
	int tu = u;
	ans[u] = ans[v] = 1;
	while (par[v][tu]) {
		in_P[tu] = true;	
		ans[tu] = 1;
		tu = par[v][tu];
	}	

	t_dist[u] = t_dist[v] = 0;
	q.push(u);
	if (u != v) q.push(v);
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		int d_t = t_dist[t];
		for (int t2 : adj[t]) {
			if (d_t + 1 < t_dist[t2]) {
				t_dist[t2] = d_t + 1;
				q.push(t2);
				if (in_P[t2]) continue;
				if (dist[u][t] + 1 == dist[u][t2] && dist[v][t] + 1 == dist[v][t2]) ans[t2]++;
			} else if (d_t + 1 == t_dist[t2]) {	
				if (in_P[t2]) continue;
				if (dist[u][t] + 1 == dist[u][t2] && dist[v][t] + 1 == dist[v][t2]) ans[t2]++;	
			}
		}
	}
	

	ll fans = 1;
	for (int i = 1; i <= n; i++) fans *= ans[i], fans %= MOD;
	return fans;
}

ll ffans[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}

	for (int i = 1; i <= n; i++) BFS(i);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			ffans[i][j] = Ans(i, j);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i < j) cout << ffans[j][i] << sep;
			else cout << ffans[i][j] << sep;
		}
		
		cout << endl;
	}
	return 0;
}