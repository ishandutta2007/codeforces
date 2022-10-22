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

const ll MAXN = 1e2 + 10;
const ll INF = 1e9;

int dist[MAXN][MAXN], f_dist[MAXN][MAXN][MAXN], 
    n, m, k, a, b, S[MAXN], T[MAXN], ans[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> a >> b;
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			dist[i][j] = INF;
			for (int k = 0; k < MAXN; k++)
				f_dist[i][j][k] = INF;
		
			if (j != i)
				f_dist[i][j][j] = 0;
			
			ans[i][j] = INF;
		}

		dist[i][i] = 0;
	}

	while (m--) {
		int u, v;
		cin >> u >> v;
		dist[u][v] = 1;
		
		for (int i = 1; i <= n; i++) 
			if (i != u && i != v)
				f_dist[i][u][v] = 1;
	}

	for (int i = 1; i <= n; i++)
		for (int v = 1; v <= n; v++)
			for (int u = 1; u <= n; u++)
				dist[v][u] = min(dist[v][u], dist[v][i] + dist[i][u]);

	for (int t = 1; t <= n; t++)
		for (int i = 1; i <= n; i++)
			for (int v = 1; v <= n; v++)
				for (int u = 1; u <= n; u++)
					f_dist[t][u][v] = min(f_dist[t][u][v], f_dist[t][u][i] + f_dist[t][i][v]);


	cin >> k;
	for (int i = 1; i <= k; i++) {
		cin >> S[i] >> T[i];
		ans[b][i] = 1;
	}

	int R = MAXN;
	while (R--) {
		for (int v = 1; v <= n; v++) {
			for (int i = 1; i <= k; i++) {
				if (v != T[i]) {
					int tans = 0;
					for (int u = 1; u <= n; u++)
						if (dist[v][u] == 1 && dist[u][T[i]] == dist[v][T[i]] - 1)
							tans = max(tans, ans[u][i]);
					ans[v][i] = min(ans[v][i], tans);
				}

				for (int j = 1; j <= k; j++)
					if (f_dist[v][S[j]][T[j]] != dist[S[j]][T[j]])
						ans[v][i] = min(ans[v][i], ans[v][j] + 1);
			}
		}
	}

	int tans = INF;
	for (int i = 1; i <= k; i++)
		if (f_dist[a][S[i]][T[i]] != dist[S[i]][T[i]])
			tans = min(tans, ans[a][i]);
	cout << (tans == INF ? -1 : tans) << endl;
	return 0;
}