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

const int maxN = 110000;
int n, m, d;
vector < int > g[maxN];
int id[maxN];
int res;

int value[20][maxN];

void rec(int current, int mask, int visited, int cnt) {
	if (cnt >= res) {
		return;
	}
	if (current >= n - d + 1) {
		res = min(res, cnt);
		return;
	}

	int bound = current - 1;
	for (int i = 0; i < m; ++i) {
		if (visited & (1 << i)) {
			bound = max(bound, value[i][current + d]);
		}
	}
	if (bound > current) {
		rec(bound, mask, visited, cnt);
		return;
	}

	int nmask = mask;
	for (int i = current + 1; i <= current + d && (nmask + visited + 1 != (1 << m)); ++i) {
		if (nmask & (1 << id[i])) {
			continue;
		}
		rec(i, nmask, visited | (1 << id[i]), cnt + 1);
		nmask |= (1 << id[i]);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &d);
	for (int i = 0; i < m; ++i) {
		int k;
		scanf("%d", &k);
		g[i].resize(k);
		for (int j = 0; j < k; ++j) {
			scanf("%d", &g[i][j]);
			id[g[i][j]] = i;
		}
		sort(g[i].begin(), g[i].end());
		int index = (int)(g[i].size()) - 1;
		for (int j = n; j >= 1; --j) {
			while (index >= 0 && g[i][index] > j) {
				--index;
			}
			if (index >= 0 && g[i][index] <= j) {
				value[i][j] = g[i][index];
			}
		}
	}
	res = n;
	rec(0, 0, 0, 0);
	printf("%d\n", res);

	return 0;
}