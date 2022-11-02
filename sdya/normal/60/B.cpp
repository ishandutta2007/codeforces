#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 15;
int k, n, m;

char s[maxN][maxN][maxN];
bool used[maxN][maxN][maxN];

bool isValid(int x, int y, int z) {
	return 0 <= x && x < k && 0 <= y && y < n && 0 <= z && z < m && s[x][y][z] == '.';
}

int res = 0;

void dfs(int x, int y, int z) {
	if (used[x][y][z]) {
		return;
	}
	++res;
	used[x][y][z] = true;
	if (isValid(x - 1, y, z)) dfs(x - 1, y, z);
	if (isValid(x + 1, y, z)) dfs(x + 1, y, z);
	if (isValid(x, y - 1, z)) dfs(x, y - 1, z);
	if (isValid(x, y + 1, z)) dfs(x, y + 1, z);
	if (isValid(x, y, z - 1)) dfs(x, y, z - 1);
	if (isValid(x, y, z + 1)) dfs(x, y, z + 1);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &k, &n, &m);
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%s", &s[i][j]);
		}
	}
	int x, y;
	scanf("%d%d", &x, &y);
	dfs(0, x - 1, y - 1);
	cout << res << endl;

	return 0;
}