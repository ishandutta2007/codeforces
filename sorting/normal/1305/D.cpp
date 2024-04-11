#include <bits/stdc++.h>

using namespace std;

const int kN = 1007;

set<int> adj[kN];

int dfs(int u, int par = -1){
	int cnt = 1;
	for(int to: adj[u]){
		if(to == par)
			continue;

		cnt += dfs(to, u);
	}

	return cnt;
}

pair<int, int> dfs2(int u, int par = -1){
	pair<int, int> ret = {u, 0};
	for(int to: adj[u]){
		if(to == par)
			continue;

		pair<int, int> curr = dfs2(to, u);
		curr.second += 1;
		if(curr.second > ret.second)
			ret = curr;
	}
	return ret;
}

int to_where(int start, int end, int par = -1){
	if(start == end)
		return start;

	for(int to: adj[start]){
		if(to == par)
			continue;

		int x = to_where(to, end, start);
		if(x != -1)
			return to;
	}

	return -1;
}

int query(int u, int v){
	cout << "? " << u << " " << v << "\n";
	cout.flush();

	int lca;
	cin >> lca;

	return lca;
}

int do_path(int u, int v){
	int lca = query(u, v);

	int to_u = to_where(lca, u);
	if(lca != u)
		adj[lca].erase(to_u);

	int to_v = to_where(lca, v);
	if(lca != v)
		adj[lca].erase(to_v);

	return lca;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);

	int n;
	cin >> n;

	for(int i = 0; i < n - 1; ++i){
		int x, y;
		cin >> x >> y;

		adj[x].insert(y);
		adj[y].insert(x);
	}

	int pr = 1;
	while(true){
		int curr = dfs(pr);
		if(curr == 1)
			break;
		if(curr == 2){
			pr = query(pr, *adj[pr].begin());
			break;
		}

		pair<int, int> d = dfs2(pr);
		if(d.second >= 2){
			pr = do_path(pr, d.first);
		}
		else{
			auto it = adj[pr].begin();
			int to1 = *it;
			++it;
			int to2 = *it;

			pr = do_path(to1, to2);
		}
	}

	cout << "! " << pr << "\n";
	cout.flush();
}