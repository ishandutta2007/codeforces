#define _CRT_SECURE_NO_WARNINGS
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
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxD = 400;
const int shift = 200;
const int maxN = 35;

bool d[maxD][maxD][maxN][8];

int dx[] = {0, 1, 1, 1, 0,-1,-1,-1};
int dy[] = {1, 1, 0,-1,-1,-1, 0, 1};

bool used[maxD][maxD];

int n;
int a[maxN];

void dfs(int x, int y, int m, int dir) {
	if (d[x][y][m][dir] || m == n) {
		return;
	}
	d[x][y][m][dir] = true;

	int ld = (dir + 7);
	if (ld >= 8) {
		ld -= 8;
	}

	int rd = (dir + 1);
	if (rd >= 8) {
		rd -= 8;
	}

	{
		int sx = 0, sy = 0;
		for (int i = 0; i <= a[m]; ++i, sx += dx[ld], sy += dy[ld]) {
			used[x + sx][y + sy] = true;
		}
		dfs(x + sx - dx[ld], y + sy - dy[ld], m + 1, ld);
	}
	{
		int sx = 0, sy = 0;
		for (int i = 0; i <= a[m]; ++i, sx += dx[rd], sy += dy[rd]) {
			used[x + sx][y + sy] = true;
		}
		dfs(x + sx - dx[rd], y + sy - dy[rd], m + 1, rd);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int j = 0; j < a[0]; ++j) {
		used[shift][shift + j] = true;
	}

	dfs(shift, shift + a[0] - 1, 1, 0);

	int res = 0;
	for (int i = 0; i < maxD; ++i) {
		for (int j = 0; j < maxD; ++j) {
			if (used[i][j]) {
				++res;
			}
		}
	}

	cout << res << endl;

	//cerr << clock() << endl;


	return 0;
}