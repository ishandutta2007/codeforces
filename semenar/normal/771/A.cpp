//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<bool> checked(n);
	vector<vector<int>> graph(n);
	for (int i = 0; i < n; i++) {
		graph[i].push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	for (int i = 0; i < n; i++) {
		if (checked[i]) continue;
		checked[i] = true;
		for (int j = 0; j < graph[i].size(); j++) {
			if (graph[i][j] == i) continue;
			int x = graph[i][j];
			if (graph[i].size() != graph[x].size()) {
				cout << "NO" << endl;
				return 0;
			}
			for (int k = 0; k < graph[x].size(); k++) {
				if (graph[i][k] != graph[x][k]) {
					cout << "NO" << endl;
					return 0;
				}
			}
			checked[x] = true;
		}
	}

	cout << "YES" << endl;
	return 0;
}