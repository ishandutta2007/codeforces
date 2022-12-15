#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

vector<int> adj[MAXN];
bool used[MAXN];

int dfs(int x){
	used[x] = true;

	int ans = 1;
	for(int to: adj[x]){
		if(!used[to]){
			ans += dfs(to);
		}
	}

	return ans;	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;

	cin >> n >> k;

	for(int i = 0; i < k; ++i){
		int x, y;

		cin >> x >> y;

		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	int ans = k;
	for(int i = 1; i <= n; ++i){
		if(!used[i]){
			ans -= dfs(i) - 1;
		}
	}

	cout << ans << "\n";

	return 0;
}