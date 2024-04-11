#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 5e5 + 7;

vector<array<long long, 2> > adj[MAXN];
long long n, k;
pair<long long, bool> dp[MAXN][2];

long long solve(long long u, bool used, long long p = -1){
	pair<long long, bool> &d = dp[u][used];

	if(d.second){
		return d.first;
	}
	d.second = true;
	d.first = 0;

	int mx = used ? (k - 1) : k;
	vector<array<long long, 2> > diff;
	for(array<long long, 2> e: adj[u]){
		if(e[0] == p){
			continue;
		}

		diff.push_back({solve(e[0], false, u) - solve(e[0], true, u) - e[1], e[0]});
		d.first += solve(e[0], false, u);
	}

	sort(diff.begin(), diff.end());

	for(int i = 0; i < mx && i < (int)diff.size(); ++i){
		if(diff[i][0] > 0){
			break;
		}
		d.first -= diff[i][0];
	}

	//cout << d.first << " u:" << u << " used:" << used << endl;  

	return d.first;
}

void solve(){
	cin >> n >> k;

	for(int i = 1; i <= n; ++i){
		adj[i].clear();
		dp[i][0].second = false;
		dp[i][1].second = false;
	}

	for(long long i = 0; i < n - 1; ++i){
		long long u, v, w;

		cin >> u >> v >> w;

		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	cout << solve(1, 0) << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long q;

	cin >> q;

	while(q--){
		solve();
	}

	return 0;
}