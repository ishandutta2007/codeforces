#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int n, m; 

int encodePair(int x, int y) {
	return m*x + y;
}

pair<int, int> decodePair(int a) {
	return make_pair(a/m, a%m);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	string rowDir, colDir;
	cin >> rowDir >> colDir;
	vector<vector<int>> graph(n*m, vector<int>());
	for (int row = 0; row < n; ++row) {
		for (int cPair = 0; cPair < m - 1; ++cPair) {
			int from, to;
			if (rowDir[row] == '<') {
				from = cPair + 1; 
				to = cPair;
			} else {
				from = cPair;
				to = cPair + 1;
			}
			graph[encodePair(row, from)].push_back(encodePair(row, to));
			//cout << "built edge " << row << " " << from << "-" << row << " " << to << endl;
		}
	}
	//cout << "done with row edges\n";
	for (int col = 0; col < m; ++col) {
		for (int cPair = 0; cPair < n - 1; ++cPair) {
			int from, to;
			if (colDir[col] == '^') {
				from = cPair + 1;
				to = cPair;
			} else {
				from = cPair;
				to = cPair + 1;
			}
			graph[encodePair(from, col)].push_back(encodePair(to, col));
			//cout << "built edge " << from << " " << col << "-" << to << " " << col << endl;
		}
	}
	bool isAllReachable = true;
	for (int startR = 0; startR < n; ++startR) {
		for (int startC = 0; startC < m; ++startC) {
			//cout << "BFS from " << startR << " " << startC << endl;
			vector<vector<bool>> visited(n, vector<bool>(m, false));
			queue<pair<int, int>> q;
			visited[startR][startC] = true;
			q.emplace(startR, startC);
			while (!q.empty()) {
				auto curr_c = q.front(); q.pop();
				//cout << "visiting " << curr_c.first<< curr_c.second;
				for (int neigh : graph[encodePair(curr_c.first, curr_c.second)]) {
					int nx = decodePair(neigh).first;
					int ny = decodePair(neigh).second;
					//cout << nx << " " << ny << " are adj\n";
					if (!visited[nx][ny]) {
						//cout << "moving to " << nx << " " << ny << endl;
						q.emplace(nx, ny);
						visited[nx][ny] = true;
					}
				}
			}
			for (int tcr = 0; tcr < n; ++tcr) {
				for (int tcc = 0; tcc < m; ++tcc) {
					if (!visited[tcr][tcc]) {
						//cout << tcr << " " << tcc << " unreachable from " << startR << " " << startC << endl;
						isAllReachable = false;
						break;
					}
				}
			}
		}
	}
	cout << (isAllReachable ? "YES" : "NO") << endl;
	return 0;
}