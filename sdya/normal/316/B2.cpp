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

const int maxN = 1100;
int n, x, a[maxN], b[maxN];
int visited[2][maxN], p, q;
int used[maxN];

int dfs(int v) {
	int res = 1;
	int y = v;
	used[v] = true;
	while (b[y] != 0) {
		++res;
		y = b[y];
		used[y] = true;
	}

	y = v;
	while (a[y] != 0) {
		++res;
		y = a[y];
		used[y] = true;
	}
	return res;
}

int generate() {
	vector < int > components;
	dfs(x);
	int position = 1;
	int y = x;
	while (a[y] != 0) {
		++position;
		y = a[y];
	}

	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			components.push_back(dfs(i));
		}
	}

	p = 0, q = 1;
	visited[p][0] = 1;
	for (int i = 0; i < components.size(); ++i, swap(p, q)) {
		memset(visited[q], 0, sizeof(visited[q]));
		for (int j = 0; j < maxN; ++j) {
			if (visited[p][j]) {
				visited[q][j] = true;
				visited[q][j + components[i]] = true;
			}
		}
	}

	return position;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] != 0) {
			b[a[i]] = i;
		}
	}

	int index = generate();

	for (int i = 0; i < maxN; ++i) {
		if (visited[p][i]) {
			printf("%d\n", i + index);
		}
	}

	return 0;
}