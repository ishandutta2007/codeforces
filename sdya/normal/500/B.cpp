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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 400;
int n;
int p[maxN];
bool g[maxN][maxN];
char s[maxN];
bool used[maxN];

int c[maxN];

void dfs(int v, int cnt) {
	used[v] = true;
	c[v] = cnt;
	for (int i = 0; i < n; ++i) {
		if (g[v][i] && !used[i]) {
			dfs(i, cnt);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s);
		for (int j = 0; j < n; ++j) {
			g[i][j] = s[j] - '0';
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			dfs(i, cnt);
			++cnt;
		}
	}

	for (int i = 0; i < cnt; ++i) {
		vector < int > values;
		for (int j = 0; j < n; ++j) {
			if (c[j] == i) {
				values.push_back(p[j]);
			}
		}
		sort(values.begin(), values.end());
		int m = 0;
		for (int j = 0; j < n; ++j) {
			if (c[j] == i) {
				p[j] = values[m];
				++m;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("%d ", p[i]);
	}
	printf("\n");
	
	return 0;
}