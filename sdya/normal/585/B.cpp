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

const int maxN = 110;
int n, k;
char s[3][maxN];

bool used[3][maxN];

bool isValid(int x, int y) {
	return 0 <= x && x < 3 && 0 <= y && y < maxN && (s[x][y] < 'A' || s[x][y] > 'Z');
}

void dfs(int x, int y) {
	if (used[x][y]) {
		return;
	}
	used[x][y] = true;
	if (y >= 105) {
		return;
	}

	if (isValid(x, y + 1) && isValid(x - 1, y + 1) && isValid(x - 1, y + 2) && isValid(x - 1, y + 3)) {
		dfs(x - 1, y + 3);
	}
	if (isValid(x, y + 1) && isValid(x, y + 1) && isValid(x, y + 2) && isValid(x, y + 3)) {
		dfs(x, y + 3);
	}
	if (isValid(x, y + 1) && isValid(x + 1, y + 1) && isValid(x + 1, y + 2) && isValid(x + 1, y + 3)) {
		dfs(x + 1, y + 3);
	}
}

void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < maxN; ++j) {
			s[i][j] = 0;
		}
	}
	for (int i = 0; i < 3; ++i) {
		scanf("%s", &s[i]);
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < maxN; ++j) {
			used[i][j] = false;
		}
	}

	for (int i = 0; i < 3; ++i) {
		if (s[i][0] == 's') {
			dfs(i, 0);
		}
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 105; j < maxN; ++j) {
			if (used[i][j]) {
				printf("YES\n");
				return;
			}
		}
	}
	printf("NO\n");
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		solve();
	}



	return 0;
}