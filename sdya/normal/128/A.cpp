#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 8;
int n;
string s[maxN];

bool visited[maxN][maxN][maxN * maxN];
vector < pair < int, int > > t;

bool valid(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void dfs(int x, int y, int moves) {
	if (moves >= maxN * maxN) {
		return;
	}
	if (visited[x][y][moves]) {
		return;
	}

	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			if (!valid(x + i, y + j)) {
				continue;
			}

			bool isOk = true;
			for (int k = 0; k < t.size(); ++k) {
				if (t[k].first + moves == x + i && t[k].second == y + j) {
					isOk = false;
					break;
				}
			}
			if (!isOk) {
				continue;
			}

			if (x + i == 0 && y + j == n - 1) {
				cout << "WIN" << endl;
				exit(0);
			}

			for (int k = 0; k < t.size(); ++k) {
				if (t[k].first + moves + 1 == x + i && t[k].second == y + j) {
					isOk = false;
					break;
				}
			}
			if (isOk) {
				dfs(x + i, y + j, moves + 1);
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	n = 8;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		for (int j = 0; j < n; ++j) {
			if (s[i][j] == 'S') {
				t.push_back(make_pair(i, j));
			}
		}
	}

	dfs(n - 1, 0, 0);

	cout << "LOSE" << endl;

	return 0;
}