#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <queue>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 2100;

int n;
int a[maxN][maxN], used[maxN][maxN], s[maxN][maxN];

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

bool val(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void dfs(int x, int y) {
	if (used[x][y]) return ;
	used[x][y] = true;

	for (int i = 0; i < 4; ++i)
		if (val(x + dx[i], y + dy[i]) && a[x + dx[i]][y + dy[i]] == 1)
			dfs(x + dx[i], y + dy[i]);
}

int calc_comps() {
	int res = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (!used[i][j] && a[i][j] == 1) {
				++res;
				dfs(i, j);
			}
	return res;
}

int calc_squares() {
	int res = 0;
	for (int i = 10; i < n; ++i) 
		for (int j = 10; j < n; ++j)
			if (a[i][j] == 1) {
				bool good = true;
				if (val(i + 1, j + 1) && a[i + 1][j + 1] == 1) good = false;
				if (val(i, j + 1) && a[i][j + 1] == 1) good = false;
				if (val(i + 1, j) && a[i + 1][j] == 1) good = false;
				int score = 0;
				for (int k = i - 5; k <= i + 5 && k < n; ++k)
					for (int l = j - 5; l <= j + 5 && l < n; ++l)
						if (a[k][l] == 1) ++score;
				if (good && score == 36) {
					++res;
				}
			}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);

	int total = calc_comps();
	int squares = calc_squares();

	printf("%d %d\n", total - squares, squares);


	return 0;
}