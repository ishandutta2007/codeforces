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
#include <queue>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100;
char s[maxN][maxN];
int n, m;

int d[maxN][maxN];

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

bool isValid(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m && s[x][y] != 'T';
}

void build(int x, int y) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			d[i][j] = 1000000000;
		}
	}

	d[x][y] = 0;
	queue < pair < int, int > > q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!isValid(nx, ny)) {
				continue;
			}
			if (d[nx][ny] > d[x][y] + 1) {
				d[nx][ny] = d[x][y] + 1;
				q.push(make_pair(nx, ny));
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

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == 'E') {
				build(i, j);
			}
		}
	}

	int len = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == 'S') {
				len = d[i][j];
			}
		}
	}

	int res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (d[i][j] <= len && s[i][j] >= '0' && s[i][j] <= '9') {
				res += s[i][j] - '0';
			}
		}
	}

	printf("%d\n", res);

	return 0;
}