#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main() {
	ios_base::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	vector<string> grid(n, "");
	for (int i = 0; i < n; ++i) {
		cin >> grid[i];
	}
	string ins; cin >> ins;
	pair<int, int> start, end;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == 'S') {
				start = make_pair(i, j);
			} else if (grid[i][j] == 'E') {
				end = make_pair(i, j);
			}
		}
	}
	int ways = 0;
	vector<int> mapping(4, 0);
	for (int i = 0; i < 4; ++i) {
		mapping[i] = i;
	}
	do {
		int cx = start.first;
		int cy = start.second;
		bool success = false;
		for (char com : ins) {
			cx += dx[mapping[com - '0']];
			cy += dy[mapping[com - '0']];
			if (cx < 0 || n <= cx || cy < 0 || m <= cy || grid[cx][cy] == '#') {
				break;
			}
			if (cx == end.first && cy == end.second) {
				success = true;
				break;
			}
		}
		if (success) {
			++ways;
		}
	} while (next_permutation(mapping.begin(), mapping.end()));
	cout << ways;
	return 0;
}