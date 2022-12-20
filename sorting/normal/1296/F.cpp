#include <bits/stdc++.h>

using namespace std;
void read();

const int kMaxN = 5007;
const int kMaxVal = 1e6;
vector<int> adj[kMaxN];
int a[kMaxN], b[kMaxN], g[kMaxN], val[kMaxN], par[kMaxN];
int idx[kMaxN][kMaxN];
int n, m;

vector<int> dfs(int from, int to){
	stack<int> st;
	st.push(from);
	par[from] = -1;

	while(!st.empty()){
		int u = st.top();
		st.pop();

		for(int to: adj[u]){
			if(to == par[u])
				continue;

			par[to] = u;
			st.push(to);
		}
	}

	vector<int> path;
	while(to != from){
		path.push_back(to);
		to = par[to];
	}
	path.push_back(from);

	return path;
}

void solve(){
	for(int i = 0; i < n; ++i)
		val[i] = 1;

	for(int i = 0; i < m; ++i){
		vector<int> path = dfs(a[i], b[i]);
		for(int j = 0; j < (int)path.size() - 1; ++j){
			int u = path[j], v = path[j + 1];
			val[idx[u][v]] = max(val[idx[u][v]], g[i]);
		}
	}

	for(int i = 0; i < m; ++i){
		vector<int> path = dfs(a[i], b[i]);
		int mn = kMaxVal;
		for(int j = 0; j < (int)path.size() - 1; ++j){
			int u = path[j], v = path[j + 1];
			mn = min(val[idx[u][v]], mn);
		}

		if(mn != g[i]){
			cout << "-1\n";
			return;
		}
	}

	for(int i = 0; i < n - 1; ++i)
		cout << val[i] << " ";
	return ;
}

int main(){
	read();
	solve();
}
void read(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
		idx[u][v] = i;
		idx[v][u] = i;
	}

	cin >> m;
	for(int i = 0; i < m; ++i)
		cin >> a[i] >> b[i] >> g[i];
}