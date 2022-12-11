#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<vector<int>> graph;
vector<int> low;
vector<int> disc;
vector<int> aPoints;
int t = 0;

void findAPs(int i, int p) {
	low[i] = disc[i] = t++;
	bool hasLowChild = false;
	int treeChildren = 0;
	for (int next : graph[i]) {
		if (disc[next] == -1) {
			//cout << "tree edge " << i << "->" << next << endl;
			findAPs(next, i);
			low[i] = min(low[i], low[next]);
			if (low[next] >= disc[i]) {
				hasLowChild = true;
			}
			++treeChildren;
		} else if (next != p) {
			low[i] = min(low[i], disc[next]);
		}
	}
	if ((p != -1 && hasLowChild) || (p == -1 && treeChildren > 1)) {
		//cout << (p != 1) << hasLowChild;
		//cout << "marking AP " << i << " with " << treeChildren << " TCs" << endl;
		aPoints.push_back(i);
	}
}

int main() {
	int n, m; cin >> n >> m;
	vector<string> grid(n, "");
	for (int i = 0; i < n; ++i) {
		cin >> grid[i];
	}
	vector<vector<int>> graphIdx(n, vector<int>(m, -1));
	int gn = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == '#') {
				graphIdx[i][j] = gn++;
			}
		}
	}
	if (gn < 2) {
		cout << -1 << endl;
		return 0;
	}
	graph = vector<vector<int>>(gn, vector<int>());
	low = disc = vector<int>(gn, -1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int mt = 0; mt < 4; ++mt) {
				int ni = i + dx[mt];
				int nj = j + dy[mt];
				if (0 <= ni && ni < n && 0 <= nj && nj < m && grid[i][j] == '#' && grid[ni][nj] == '#') {
					graph[graphIdx[i][j]].push_back(graphIdx[ni][nj]);
					//cout << "graph edge " << graphIdx[i][j] << " " << graphIdx[ni][nj] << endl;
				}
			}
		}
	}
	findAPs(0, -1);
	for (int i = 0; i < gn; ++i) {
		if (disc[i] == -1) {
			cout << 0 << endl;
			return 0;
		}
	}
	if (aPoints.size() > 0) {
		cout << 1 << endl;
		return 0;
	}
	for (int i = 0; i < gn; ++i) {
		if (graph[i].size() >= 2) {
			cout << 2 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}