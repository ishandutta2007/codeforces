#include<vector>
#include<iostream>
#include<stdio.h>
#include<set>
#include<algorithm>

using namespace std;
vector<vector<int> >g(150001);
vector<int>used(150001, 0),c;

void dfs(int v) {
	used[v] = 1;
	c.push_back(v);
	for (int i = 0; i < g[v].size(); i++) {
		if (!used[g[v][i]])
			dfs(g[v][i]);
	}
}

int main() {
	int n, m,a,b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			c.clear();
			dfs(i);
			for (int j = 0; j < c.size(); j++) {
				if (g[c[j]].size() != c.size() - 1) {
					cout << "NO";
					return 0;
				}
			}
		}
	}
	cout << "YES";
	return 0;
}