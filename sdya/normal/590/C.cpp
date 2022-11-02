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
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100;
const int inf = 100000000;
int n, m;
char s[maxN][maxN];
int d[3][maxN][maxN];

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

int dp[3][3];

bool isValid(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m && s[i][j] != '#';
}

void build(int start, int d[maxN][maxN]) {
	queue < pair < int, int > > q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == '1' + start) {
				q.push(make_pair(i, j));
				d[i][j] = 0;
			} else {
				d[i][j] = inf;
			}
		}
	}

	while (!q.empty()) {
		pair < int, int > p = q.front();
		q.pop();
		int x = p.first;
		int y = p.second;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isValid(nx, ny) && d[nx][ny] > d[x][y] + 1) {
				d[nx][ny] = d[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] >= '1' && s[i][j] <= '3') {
				int value = d[i][j];
				if (value == inf) {
					continue;
				}
				dp[start][s[i][j] - '1'] = min(dp[start][s[i][j] - '1'], value - 1);
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s[i]);
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			dp[i][j] = inf;
		}
		dp[i][i] = 0;
	}

	for (int i = 0; i < 3; ++i) {
		build(i, d[i]);
	}

	int res = inf;
	res = min(res, dp[0][1] + dp[0][2]);
	res = min(res, dp[1][0] + dp[1][2]);
	res = min(res, dp[2][0] + dp[2][1]);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (d[0][i][j] == inf || d[1][i][j] == inf || d[2][i][j] == inf) {
				continue;
			}
			int value = d[0][i][j] + d[1][i][j] + d[2][i][j];
			res = min(res, value - 2);
		}
	}

	if (res >= inf) {
		res = -1;
	}
	printf("%d\n", res);

	return 0;
}