#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

int n, m;
vector<int> adj[MAXN];
bool adj_arr[MAXN];
set<int> not_used;

void dfs(int u){
	stack<int> st;

	st.push(u);
	not_used.erase(u);

	while(!st.empty()){
		u = st.top();
		st.pop();

		for(int to: adj[u]){
			adj_arr[to] = true;
		}

		vector<int> to_rem;
		for(int to: not_used){
			if(not_used.count(to) && !adj_arr[to]){
				st.push(to);
				to_rem.push_back(to);
			}
		}

		for(int to: to_rem){
			not_used.erase(to);
		}

		for(int to: adj[u]){
			adj_arr[to] = false;
		}
	}
}

void solve(){
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		not_used.insert(i);
	}

	for(int i = 1; i <= n; ++i){
		if(not_used.count(i)){
			dfs(i);
			++ans;
		}
	}

	cout << ans - 1 << "\n";
}

void read(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

int main(){
	read();
	solve();

	return 0;
}