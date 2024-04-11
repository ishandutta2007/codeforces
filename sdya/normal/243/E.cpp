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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 501;
char g[maxN][maxN][maxN];
int n;
char s[maxN][maxN];

bool used[maxN][maxN];
pair < int, int > order[maxN * maxN];
int m_order;
int comp[maxN][maxN];

void dfs1 (int x, int y) {
	used[x][y] = true;
	for (int i = 0; i < n; ++i) {
		if ((g[x][y][i] & 1) && !used[x][i]) {
			dfs1(x, i);
		}
		if ((g[x][y][i] & 2) && !used[i][y]) {
			dfs1(i, y);
		}
	}
	order[m_order++] = make_pair(x, y);
}

void dfs2 (int x, int y, int id) {
	comp[x][y] = id;
	if (comp[y][x] == id) {
		printf("NO\n");
		exit(0);
	}
	for (int i = 0; i < n; ++i) {
		if ((g[x][y][i] & 1) && comp[x][i] == -1) {
			dfs2(x, i, id);
		}
		if ((g[x][y][i] & 2) && comp[i][y] == -1) {
			dfs2(i, y, id);
		}
	}
}

bool h[maxN][maxN];
vector < int > r;
bool visited[maxN];

void dfs(int v) {
	visited[v] = true;
	for (int i = 0; i < n; ++i) {
		if (h[v][i] && !visited[i]) {
			dfs(i);
		}
	}
	r.push_back(v);
}

void solve() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j && !used[i][j]) {
				dfs1(i, j);
			}
		}
	}
	memset(comp, -1, sizeof(comp));
	int id = 0;
	reverse(order, order + m_order);
	for (int i = 0; i < m_order; ++i) {
		int x = order[i].first;
		int y = order[i].second;
		if (comp[x][y] == -1) {
			++id;
			dfs2(x, y, id);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (comp[i][j] == comp[j][i]) {
				printf("NO\n");
				exit(0);
			} else {
				if (comp[i][j] > comp[j][i]) {
					h[i][j] = true;
				} else {
					h[j][i] = true;
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	printf("YES\n");
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < r.size(); ++j) {
			printf("%c", s[i][r[j]]);
		}
		printf("\n");
	}
}

int ones[maxN], m;

void gen() {
	int n = 500;
	printf("%d\n", n);
	for (int i = 0; i < n; ++i) {
		int l = rand() % n;
		int r = rand() % n;
		if (l > r) {
			swap(l, r);
		}
		for (int j = 0; j < n; ++j) {
			printf("%c", '0' + (j >= l && j <= r));
		}
		printf("\n");
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen();

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s[i]);
	}

	for (int k = 0; k < n; ++k) {
		m = 0;
		for (int i = 0; i < n; ++i) {
			if (s[k][i] == '1') {
				ones[m++] = i;
			}
		}

		for (int i = 0; i < n; ++i) {
			if (s[k][i] == '1') {
				continue;
			}

			for (int j = 0; j < m; ++j) {
				int l = j + 1;
				if (l == m) {
					l = 0;
				}
				if (j == l) {
					continue;
				}
				g[i][ones[j]][ones[l]] |= 1;
				//g[i][ones[l]][ones[j]] |= 4;

				g[ones[j]][i][ones[l]] |= 2;
				//g[ones[l]][i][ones[j]] |= 8;
			}
		}
	}
	//cerr << clock() << endl;

	solve();

	cerr << clock() << endl;

	return 0;
}