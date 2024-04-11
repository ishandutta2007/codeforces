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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 600;
char s[maxN][maxN];
int n, m, k;

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

bool valid(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m && s[x][y] == '.';
}

bool used[maxN][maxN];

void dfs(int x, int y) {
	if (used[x][y]) {
		return;
	}
	used[x][y] = true;
	if (k == 0) {
		s[x][y] = 'X';
	} else {
		--k;
	}
	for (int i = 0; i < 4; ++i) {
		if (valid(x + dx[i], y + dy[i])) {
			dfs(x + dx[i], y + dy[i]);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s[i]);
		cnt += count(s[i], s[i] + m, '.');
	}
	k = cnt - k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!used[i][j] && valid(i, j)) {
				dfs(i, j);
			}
		}
	}
	
	for (int i = 0; i < n; ++i) {
		puts(s[i]);
	}


	return 0;
}