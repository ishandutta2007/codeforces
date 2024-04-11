#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 3e2;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, k, p_v[MAXN][MAXN], t = 1, dist[MAXN][MAXN], dp[MAXN][MAXN], par[MAXN][MAXN], A[MAXN], P[MAXN];
char val[MAXN][MAXN][MAXN];
vector<int> adj[MAXN];

inline void Clear(int msk, int v) {
	for (int i = 0; i < t; i++) 
		val[msk][v][i] = '.';
}

inline void AddPath(int msk, int c, int v, int u) {
	val[msk][c][v] = val[msk][c][u] = 'X';
	while (u != v) {
		val[msk][c][u] = 'X';
		u = par[v][u];
	}
}

inline void Merge(int msk, int c, int msk1, int c1, int msk2, int c2) {
	for (int i = 0; i < t; i++) 
		if (val[msk1][c1][i] == 'X' || val[msk2][c2][i] == 'X') 
			val[msk][c][i] = 'X';
}

inline void Dijkstra(int s) {
	memset(dist[s], 63, sizeof dist[s]);
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	dist[s][s] = A[s];
	pq.push({A[s], s});

	while (!pq.empty()) {
		int v = pq.top().Y, d_v = pq.top().X;	
		pq.pop();
		if (d_v != dist[s][v]) continue;
		
		for (int u : adj[v]) {
			int d_u = d_v + A[u];
			if (d_u < dist[s][u]) {
				dist[s][u] = d_u;
				par[s][u] = v;
				pq.push({d_u, u});
			}
		}
	}
}

inline void Print(int msk, int c) {	
	cout << dp[msk][c] << endl;
	for (int i = 1; i < t; i++) {
		cout << val[msk][c][i];
		if (i % m == 0) cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int k;
			cin >> k;
			A[t] = k;
			p_v[i][j] = t;
			t++;
		}
	}

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		P[i] = p_v[x][y];
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int v = p_v[i][j];
			if (i > 1) adj[v].push_back(p_v[i - 1][j]);
			if (j > 1) adj[v].push_back(p_v[i][j - 1]);
			if (i < n) adj[v].push_back(p_v[i + 1][j]);
			if (j < m) adj[v].push_back(p_v[i][j + 1]);
		}
	}

	for (int i = 1; i < t; i++) Dijkstra(i);

	int MSK = (1 << k);
	for (int msk = 1; msk < MSK; msk++) {
		int cnt = __builtin_popcount(msk);
		for (int v = 1; v < t; v++) {
			dp[msk][v] = INF;
			Clear(msk, v);
			if (cnt == 1) {
				dp[msk][v] = dist[v][P[__builtin_ctz(msk)]];	
				AddPath(msk, v, v, P[__builtin_ctz(msk)]);
				continue;
			}

			for (int submsk1 = 1; submsk1 < msk; submsk1++) {
				if ((submsk1 | msk) != msk) continue;
				int submsk2 = msk ^ submsk1;
				int tdp = dp[submsk1][v] + dp[submsk2][v] - A[v];
				if (tdp < dp[msk][v]) {
					Clear(msk, v);
					dp[msk][v] = tdp;
					Merge(msk, v, submsk1, v, submsk2, v);
				}
			}
		}

		for (int v=  1; v < t; v++) {	
			for (int u = 1; u < t; u++) {
				int tdp = dp[msk][u] + dist[v][u] - A[u];
				if (tdp < dp[msk][v]) {
					if (msk == 3 && v == 1) debug(u)
					dp[msk][v] = tdp;
					for (int i = 1; i < t; i++) val[msk][v][i] = val[msk][u][i];
					AddPath(msk, v, v, u);
				}
			}
		}
	}
	
	Print(MSK - 1, P[0]);
	return 0;
}