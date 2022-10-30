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

const int maxN = 60;
int n, m;
int k;

string s[maxN];

int dx[] = { 0, 1, 0,-1};
int dy[] = { 1, 0,-1, 0};

bool valid(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m && s[x][y] != '0';
}

bool isValid(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

pair < int, int > pos[maxN][maxN][4];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	m = s[0].size();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int cp = 0; cp < 4; ++cp) {
				for (int k = 0; ; ++k) {
					if (isValid(i + dx[cp] * k, j + dy[cp] * k)) {
						int ni = i + dx[cp] * k;
						int nj = j + dy[cp] * k;
						if (s[ni][nj] == s[i][j]) {
							pos[i][j][cp] = make_pair(ni, nj);
						} else {
							break;
						}
					} else {
						break;
					}
				}
			}
		}
	}

	int x = 0, y = 0, cp = 3, dp = 0;
	for (int i = 0; i < k; ++i) {
		pair < int, int > u = pos[x][y][dp];
		pair < int, int > v = pos[u.first][u.second][cp];

		int nx = v.first;
		int ny = v.second;

		if (valid(nx + dx[dp], ny + dy[dp])) {
			x = nx + dx[dp];
			y = ny + dy[dp];
			continue;
		}

		if ((cp + 1) % 4 == dp) {
			cp = (dp + 1) % 4;
		} else {
			cp = dp;
			dp = (dp + 1) % 4;
		}
	}

	printf("%c\n", s[x][y]);

	return 0;
}