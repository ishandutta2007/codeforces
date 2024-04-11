#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int n, m;
vector<int> orderToRemove;
vector<bool> visited;
vector<vector<int>> graph;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

pair<int, int> decode(int x) {
	return make_pair(x / m, x % m);
}

int encode(int x, int y) {
	return (x*m + y);
}

int encode(pair<int, int> x) {
	return encode(x.first, x.second);
}

void DFS(int i) {
	//cout << "visiting " << i << endl;
	visited[i] = true;
	for (int neigh : graph[i]) {
		if (!visited[neigh]) {
			DFS(neigh);
		}
	}
	orderToRemove.push_back(i);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> n >> m >> k;
	vector<string> immutgrid(n, "");
	for (int i = 0; i < n; ++i) {
		cin >> immutgrid[i];
	}
	vector<vector<char>> grid(n, vector<char>());
	for (int i = 0; i < n; ++i) {
		grid[i] = vector<char>(immutgrid[i].begin(), immutgrid[i].end());
	}
	int si = 0;
	int sj = 0;
	graph = vector<vector<int>>(n*m, vector<int>());
	visited = vector<bool>(n*m, false);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == '.') {
				si = i;
				sj = j;
			}
			for (int mt = 0; mt < 4; ++mt) {
				int ni = i + dx[mt];
				int nj = j + dy[mt];
				if (0 <= ni && ni < n && 0 <= nj && nj < m && grid[i][j] == '.' && grid[ni][nj] == '.') {
					graph[encode(i, j)].push_back(encode(ni, nj));
				}
			}
		}
	}
	//cout << "graph initialized" << endl;
	DFS(encode(si, sj));
	//cout << "dfs finished" << endl;
	for (int i = 0; i < k; ++i) {
		auto tr = decode(orderToRemove[i]);
		grid[tr.first][tr.second] = 'X';
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << grid[i][j];
		}
		cout << endl;
	}
	return 0;
}