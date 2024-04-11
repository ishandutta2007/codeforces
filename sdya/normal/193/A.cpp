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

using namespace std;

const int maxN = 60;
int n, m;
char s[maxN][maxN];

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

bool val(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int used[maxN][maxN];

void dfs(int x, int y) {
	if (used[x][y]) {
		return ;
	}
	used[x][y] = true;
	for (int i = 0; i < 4; ++i) {
		if (val(x + dx[i], y + dy[i]) && s[x + dx[i]][y + dy[i]] == '#') {
			dfs(x + dx[i], y + dy[i]);
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

	int total = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == '#') {
				++total;
			}
		}
	}

	int res = 1000000;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == '#') {
				int need = 0;
				for (int k = 0; k < 4; ++k) {
					if (val(i + dx[k], j + dy[k]) && s[i + dx[k]][j + dy[k]] == '#') {
						++need;
					}
				}
				if (need + 1 != total) {
					res = min(res, need);
				}

				if (total != 1) {
					s[i][j] = '.';
					for (int k = 0; k < n; ++k) {
						for (int l = 0; l < m; ++l) {
							used[k][l] = false;
						}
					}

					int comp = 0;
					for (int k = 0; k < n; ++k) {
						for (int l = 0; l < m; ++l) {
							if (s[k][l] == '#' && !used[k][l]) {
								dfs(k, l);
								++comp;
							}
						}
					}
					if (comp != 1) {
						res = min(res, 1);
					}
					s[i][j] = '#';
				}
			}
		}
	}

	if (res == 1000000) {
		res = -1;
	}
	printf("%d\n", res);

	return 0;
}