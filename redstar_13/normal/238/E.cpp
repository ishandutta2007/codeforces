#include<bits/stdc++.h>



using namespace std;



#define NN 111

#define inf 0x3f3f3f3f



int dp[NN][NN];

int path[NN][NN];

int dst[NN][NN];

vector<int> adj[NN];

int st[NN], ed[NN];

int n, m, src, tar;

int k;



int main() {

#ifndef ONLINE_JUDGE

	freopen("in.in", "r", stdin);

	freopen("out.out", "w", stdout);

#endif

	cin >> n >> m >> src >> tar;

	for(int i=0; i<NN; i++) for(int j=0; j<NN; j++) dst[i][j] = inf;

	for(int i=1; i<=n; i++) dst[i][i] = 0;

	

	for(int i=1, u, v; i<=m; i++) {

		cin >> u >> v;

		adj[u].push_back(v);

		dst[u][v] = 1;

	}

	

	for(int md=1; md<=n; md++) for(int i=1; i<=n; i++)

		for(int j=1; j<=n; j++) dst[i][j] = min(dst[i][j], dst[i][md] + dst[md][j]);

	

	cin >> k;

	for(int i=1; i<=k; i++) cin >> st[i] >> ed[i];

	

	for(int i=1; i<=k; i++) {

		if(dst[st[i]][ed[i]] == inf) continue;

		vector<int> res[NN];

		for(int j=1; j<=n; j++) if(dst[st[i]][j] + dst[j][ed[i]] == dst[st[i]][ed[i]]) {

			res[dst[st[i]][j]].push_back(j);

		}

		for(int j=0; j<NN; j++) if(res[j].size() == 1)

			path[i][res[j][0]] = 1;

	}

	

	int flag = 1;

	for(int i=0; i<NN; i++) for(int j=0; j<NN; j++)

		dp[i][j] = inf;

		

	for(int i=1; i<=k; i++) if(dst[st[i]][ed[i]] != inf and 

		dst[st[i]][ed[i]] == dst[st[i]][tar] + dst[tar][ed[i]]) {

		dp[i][tar] = 0, flag = 0;

	}

		

	if(flag) return puts("-1"), 0;

	

	do {

		flag = 0;

		for(int i=1; i<=k; i++) for(int j=1; j<=n; j++) {

			if(dst[st[i]][ed[i]] == inf) continue;

			if(dst[st[i]][ed[i]] == dst[st[i]][j] + dst[j][ed[i]]) {

				int x = dp[i][j];

				for(int t=1; t<=k; t++) if(path[t][j])

					dp[i][j] = min(dp[i][j], dp[t][j] + 1);

				int ma = 0;

				int FLAG = 0;

				for(auto u : adj[j]) {

					if(dst[st[i]][u] == dst[st[i]][j] + 1 and dst[st[i]][ed[i]] == dst[st[i]][u] + dst[u][ed[i]]) {

						FLAG = 1;

						ma = max(dp[i][u], ma);

					}

				}

				if(FLAG) dp[i][j] = min(dp[i][j], ma);

				if(x != dp[i][j]) flag = 1;

			}

		}

	} while(flag);

	

	int ans = inf;

	

	for(int i=1; i<=k; i++) if(path[i][src]) 

		ans = min(ans, dp[i][src]);

	

	if(ans == inf) puts("-1");

	else cout << ans + 1 << endl;

}