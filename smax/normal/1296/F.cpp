
// Problem : F. Berland Beauty
// Contest : Codeforces Round #617 (Div. 3)
// URL : https://codeforces.com/contest/1296/problem/F
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;

int ret[5000] = {};
pair<pair<int, int>, int> queries[5000];
vector<pair<int, int>> adj[5000];

bool dfs(int u, int y, int g, int p, int id) {
	bool isPath = (u == y);
	for (auto e : adj[u])
		if (e.first != p)
			isPath |= dfs(e.first, y, g, u, e.second);
	if (isPath && id != -1)
		ret[id] = max(ret[id], g);
	return isPath;
}

int minVal;

bool dfs2(int u, int y, int p, int id) {
	bool isPath = (u == y);
	for (auto e : adj[u])
		if (e.first != p)
			isPath |= dfs2(e.first, y, u, e.second);
	if (isPath && id != -1)
		minVal = min(minVal, ret[id]);
	return isPath;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    for (int i=0; i<n-1; i++) {
    	int x, y;
    	cin >> x >> y;
    	adj[x-1].emplace_back(y-1, i);
    	adj[y-1].emplace_back(x-1, i);
    }
    
    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
    	cin >> queries[i].first.first >> queries[i].first.second >> queries[i].second;
    	queries[i].first.first--, queries[i].first.second--;
    	dfs(queries[i].first.first, queries[i].first.second, queries[i].second, -1, -1);
    }
    
    for (int i=0; i<m; i++) {
    	minVal = INT_MAX;
    	dfs2(queries[i].first.first, queries[i].first.second, -1, -1);
    	if (minVal != queries[i].second) {
    		cout << "-1\n";
    		return 0;
    	}
    }
    
    for (int i=0; i<n-1; i++)
    	cout << (ret[i] == 0 ? 5 : ret[i]) << " ";
    cout << "\n";

    return 0;
}