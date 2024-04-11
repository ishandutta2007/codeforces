#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1600;
char s[maxN][maxN];
int n, m;

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

vector < pair < int, int > > used[maxN][maxN];
bool infinite = false;

void dfs(int x, int y, int horizontal = 0, int vertical = 0) {
	if (infinite) {
		return ;
	}
	if (used[x][y].size() == 0) {
		used[x][y].push_back(make_pair(horizontal, vertical));
	} else {
		if (used[x][y][0] != make_pair(horizontal, vertical)) {
			infinite = true;
		}
		return ;
	}

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		int new_h = horizontal, new_v = vertical;
		if (nx < 0) {
			nx += n;
			++new_h;
		}
		if (nx >= n) {
			nx -= n;
			--new_h;
		}
		if (ny < 0) {
			ny += m;
			++new_v;
		}
		if (ny >= m) {
			ny -= m;
			--new_v;
		}
		if (s[nx][ny] != '#') {
			dfs(nx, ny, new_h, new_v);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d\n", &n, &m);
	for (int i = 0; i < n; ++i) {
		gets(s[i]);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == 'S') {
				dfs(i, j);
			}
		}
	}

	if (infinite) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
}