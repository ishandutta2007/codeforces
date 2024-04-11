#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;

vector<int> vs;
vector<bool> visited;
vector<vector<int>> graph;
vector<vector<int>> transpose;
vector<int> roots;

void DFS(int v) {
	visited[v] = true;
	for (int next : graph[v]) {
		if (!visited[next]) {
			DFS(next);
		}
	}
	vs.push_back(v);
}

void DFSS2(int v, int root) {
	roots[v] = root;
	for (int next : transpose[v]) {
		if (roots[next] == -1) {
			DFSS2(next, root);
		}
	}
}

int main() {
	int n, m, h; cin >> n >> m >> h;
	vector<int> hours(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> hours[i];
	}
	graph = vector<vector<int>>(n, vector<int>());
	for (int i = 0; i < m; ++i) {
		int c1, c2; cin >> c1 >> c2;
		--c1; --c2;
		if (hours[c1] > hours[c2]) {
			swap(c1, c2);
		} // now WLOG c1 <= c2
		//cout << "hour pair " << hours[c1] << " " << hours[c2] << endl;
		if (hours[c1] + 1 == hours[c2]) {
			graph[c1].push_back(c2);
		} 
		if (hours[c1] == 0 && hours[c2] == h - 1) {
			graph[c2].push_back(c1);
		}
	}
	visited = vector<bool>(n, false);
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			DFS(i);
		}
	}
	roots = vector<int>(n, -1);
	transpose = vector<vector<int>>(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		for (int j : graph[i]) {
			transpose[j].push_back(i);
		}
	}
	reverse(vs.begin(), vs.end());
	for (int v : vs) {
		if (roots[v] == -1) {
			DFSS2(v, v);
		}
	}
	map<int, int> occs;
	map<int, int> outDeg;
	for (int i = 0; i < n; ++i) {
		++occs[roots[i]];
		//cout << "root[" << i << "] = " << roots[i] << endl;
	}
	for (int i = 0; i < n; ++i) {
		for (int j : graph[i]) {
			//cout << "edge" << i << " " << j << endl;
			if (roots[i] != roots[j]) {
				++outDeg[roots[i]];
			}
		}
	}
	int bestTwist = n;
	int rootOfBest = 0;
	for (auto kvp : occs) {
		if (outDeg[kvp.first] == 0 && kvp.second < bestTwist) {
			rootOfBest = kvp.first;
			bestTwist = kvp.second;
		}
	}
	cout << bestTwist << endl;
	for (int i = 0; i < n; ++i) {
		if (roots[i] == rootOfBest) {
			cout << (i == 0 ? "" : " ") << i + 1;
		}
	}
	cout << endl;
	return 0;
}