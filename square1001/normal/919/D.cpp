#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int V, E, a, b, cmp[300009], ip[300009], dp[300009]; bool used[300009]; vector<int> G[300009], rG[300009], vs; string s;
void add_edge(int from, int to) {
	G[from].push_back(to);
	rG[to].push_back(from);
}
void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++) {
		if (!used[G[v][i]]) dfs(G[v][i]);
	}
	vs.push_back(v);
}
void rdfs(int v, int k) {
	used[v] = true;
	cmp[v] = k;
	for (int i = 0; i < rG[v].size(); i++) {
		if (!used[rG[v][i]]) rdfs(rG[v][i], k);
	}
}
int scc() {
	fill(used, used + V, false);
	vs.clear();
	for (int v = 0; v < V; v++) {
		if (!used[v]) dfs(v);
	}
	fill(used, used + V, false);
	int k = 0;
	for (int i = vs.size() - 1; i >= 0; i--) {
		if (!used[vs[i]]) rdfs(vs[i], k++);
	}
	return k;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> V >> E >> s;
	bool flag = false;
	for (int i = 0; i < E; i++) {
		cin >> a >> b; a--, b--;
		if (a == b) flag = true;
		add_edge(a, b);
	}
	int cnt = scc();
	if (flag || cnt != V) cout << "-1\n";
	else {
		for (int i = 0; i < V; i++) ip[cmp[i]] = i;
		int ret = 0;
		for (char c = 'a'; c <= 'z'; c++) {
			for (int i = 0; i < V; i++) {
				dp[ip[i]] = 0;
				for (int j : rG[ip[i]]) dp[ip[i]] = max(dp[ip[i]], dp[j]);
				dp[ip[i]] += (s[ip[i]] == c);
			}
			ret = max(ret, *max_element(dp, dp + V));
		}
		cout << ret << "\n";
	}
	return 0;
}