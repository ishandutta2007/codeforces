#include <bits/stdc++.h>

using namespace std;

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
const int inf = 1e9;

clock_t timer = clock();

int m_rand(int l, int r){
	return mt() % (r - l + 1) + l;
}

bool time_left(){
	return ((float)clock() - (float)timer) / (float)CLOCKS_PER_SEC <= (float)2.8;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<vector<int>> adj(n, vector<int>(n));
	vector<bool> col(n);
	vector<vector<int>> dist(n, vector<int>(n));
	vector<vector<int>> dp(n, vector<int>(k + 1));

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> adj[i][j];

	for(int i = 0; i < n; ++i)
		dist[i][i] = inf;

	k /= 2;

	int ans = inf;
	while(time_left()){
		col[0] = 0;
		for(int i = 1; i < n; ++i)
			col[i] = m_rand(0, 1);

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				dist[i][j] = inf;

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				for(int u = 0; u < n; ++u)
					if(col[i] == 0 && col[j] == 0 && col[u] == 1)
						dist[i][j] = min(dist[i][j], adj[i][u] + adj[u][j]);

		for(int i = 0; i < n; ++i){
			if(i == 0)
				dp[i][0] = 0;
			else
				dp[i][0] = inf;
		}

		for(int j = 1; j <= k; ++j){
			for(int i = 0; i < n; ++i){
				dp[i][j] = inf;
				for(int u = 0; u < n; ++u)
					dp[i][j] = min(dp[u][j - 1] + dist[u][i], dp[i][j]);
			}
		}

		ans = min(ans, dp[0][k]);
	}

	cout << ans << "\n";
}