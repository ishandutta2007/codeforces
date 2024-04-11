#include <bits/stdc++.h>

using namespace std;

const int N = 2007;

int n;

bool adj[N][N];
bool used[N];

vector<int> order;

void dfs(int u){
	used[u] = true;

	for(int i = 1; i <= n; i++){
		if(!adj[u][i]){
			continue;
		}

		if(!used[i]){
			dfs(i);
		}
	}

	order.push_back(u);
}

void dfs2(int u){
	used[u] = true;

	for(int i = 1; i <= n; i++){
		if(!adj[i][u]){
			continue;
		}

		if(!used[i]){
			dfs2(i);
		}
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int x;

			cin >> x;

			if(x){
				adj[i][j] = true;
			}else{
				adj[i][j] = false;
			}
		}
	}

	for(int i = 1; i <= n; i++){
		if(!used[i]){
			dfs(i);
		}
	}

	for(int i = 1; i <= n; i++){
		used[i] = false;
	}

	dfs2(order.back());

	for(int i = 1; i <= n; i++){
		if(!used[i]){
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";

	return 0;
}