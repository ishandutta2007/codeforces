#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#define INF 1000000000
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool isNumeric(char c) {
	return (c >= '0' && c <= '9');
}

struct SearchData {
	pair<int, int> ptTo;
	int dist;
	SearchData(pair<int, int> p, int d) : ptTo(p), dist(d) {}
};

bool isValid(int r, int c, int x, int y) {
	return !(x < 0 || x >= r || y < 0 || y >= c);
}

int main() {
	int r, c;
	cin >> r >> c;

	vector<string> grid(r, "");
	for (int row = 0; row < r; ++row) {
		cin >> grid[row];
	}

	pair<int, int> exitIdx;
	pair<int, int> startIdx;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (grid[i][j] == 'E') {
				exitIdx = make_pair(i, j);
			}
			if (grid[i][j] == 'S') {
				startIdx = make_pair(i, j);
			}
		}
	}

	vector<vector<int>> distToExit(r, vector<int>(c, INF));
	queue<SearchData> q;
	q.emplace(exitIdx, 0);
	distToExit[exitIdx.first][exitIdx.second] = 0;
	while (!q.empty()) {

		SearchData cur = q.front(); q.pop();
		int cx = cur.ptTo.first;
		int cy = cur.ptTo.second;

		for (int moveType = 0; moveType < 4; ++moveType) {
			int newX = cx + dx[moveType];
			int newY = cy + dy[moveType];
			if (isValid(r, c, newX, newY) && grid[newX][newY] != 'T' && distToExit[newX][newY] == INF) {
				distToExit[newX][newY] = cur.dist + 1;
				q.emplace(make_pair(newX, newY), cur.dist + 1);
			}
		}
	}

	int totalBattles = 0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (distToExit[i][j] <= distToExit[startIdx.first][startIdx.second] && isNumeric(grid[i][j])) {
				totalBattles += (grid[i][j] - '0');
			}
		}
	}

	cout << totalBattles;

	return 0;
}