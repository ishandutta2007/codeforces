#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 2000;
int n, m;
int a[maxN][maxN];
int used[maxN][maxN];

bool visited[maxN][maxN];

bool valid(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

void dfs(int x, int y, int color) {
	if (used[x][y]) {
		return ;
	}

	used[x][y] = color;
	
	for (int i = 0; i < 4; ++i) {
		if (valid(x + dx[i], y + dy[i]) && a[x + dx[i]][y + dy[i]] == 1) {
			dfs(x + dx[i], y + dy[i], color);
		}
	}
}

map < int, int > rays;

void calculateRays() {
	const int side = 2;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (visited[i][j] || a[i][j] == 0) {
				continue;
			}

			int ones = 0, zeroes = 0;
			bool seen = false;
			for (int x = -side; x <= side; ++x) {
				for (int y = -side; y <= side; ++y) {
					if (valid(i + x, j + y)) {
						if (a[i + x][j + y] == 1) {
							++ones;
						} else {
							++zeroes;
						}
						if (visited[i + x][j + y]) {
							seen = true;
						}
					}
				}
			}

			if (ones == 9) {
				++rays[used[i][j]];
				for (int x = -side; x <= side; ++x) {
					for (int y = -side; y <= side; ++y) {
						if (valid(i + x, j + y)) {
							visited[i + x][j + y] = true;
						}
					}
				}
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}

	int colors = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 1 && !used[i][j]) {
				++colors;
				dfs(i, j, colors);
			}
		}
	}

	calculateRays();

	printf("%d\n", colors);
	vector < int > cnt;
	for (map < int, int > :: iterator it = rays.begin(); it != rays.end(); ++it) {
		cnt.push_back(it->second);
	}
	sort(cnt.begin(), cnt.end());
	for (int i = 0; i < cnt.size(); ++i) {
		printf("%d ", cnt[i]);
	}
	printf("\n");

	return 0;
}