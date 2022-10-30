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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100;
int n, m;
char s[maxN][maxN];

map < pair < int, int >, int > M;

vector < int > g[maxN * maxN];
bool used[maxN * maxN];

bool visited[maxN][maxN];

int id[maxN][maxN];

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

void dfsC(int n) {
	used[n] = true;
	for (int i = 0; i < g[n].size(); ++i) {
		if (!used[g[n][i]]) {
			dfsC(g[n][i]);
		}
	}
}

bool valid(int u, int v) {
	return 0 <= u && u < n && 0 <= v && v < m;
}

void dfs(int x, int y, vector < pair < int, int > > *output) {
	visited[x][y] = true;
	output->push_back(make_pair(x, y));
	for (int dx = -1; dx <= 1; ++dx) {
		for (int dy = -1; dy <= 1; ++dy) {
			if (valid(x + dx, y + dy) && !visited[x + dx][y + dy] && s[x + dx][y + dy] == '0') {
				dfs(x + dx, y + dy, output);
			}
		}
	}
}

bool isValid(vector < pair < int, int > > p, int cur_id) {
	M.clear();
	for (int i = 0; i < p.size(); ++i) {
		if (p[i].first == 0 || p[i].first == n - 1 || p[i].second == 0 || p[i].second == m - 1) {
			return false;
		}
		M[p[i]] = i;
	}

	for (int i = 0; i < p.size(); ++i) {
		g[i].clear();
		used[i] = false;
	}

	for (int i = 0; i < p.size(); ++i) {
		int cnt = 0;
		for (int j = 0; j < 4; ++j) {
			int nx = p[i].first + dx[j];
			int ny = p[i].second + dy[j];
			if (valid(nx, ny) && id[nx][ny] == cur_id) {
				g[i].push_back(M[make_pair(nx, ny)]);
				++cnt;
			}
		}
		if (cnt != 2) {
			return false;
		}
	}

	dfsC(0);
	if (count(used, used + p.size(), false) == 0) {
		return true;
	}
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", &s[i]);
		for (int j = m - 1; j >= 0; --j) {
			s[i][j + 1] = s[i][j];
		}
	}

	n += 2;
	m += 2;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
				s[i][j] = '1';
			}
		}
	}

	int cur_id = 0;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (visited[i][j] || s[i][j] != '0') {
				continue;
			}
			++cur_id;
			vector < pair < int, int > > out;
			dfs(i, j, &out);
			vector < pair < int, int > > p;
			for (int k = 0; k < out.size(); ++k) {
				int x = out[k].first;
				int y = out[k].second;
				for (int dx = -1; dx <= 1; ++dx) {
					for (int dy = -1; dy <= 1; ++dy) {
						if (valid(x + dx, y + dy) && s[x + dx][y + dy] == '1' && id[x + dx][y + dy] != cur_id) {
							id[x + dx][y + dy] = cur_id;
							p.push_back(make_pair(x + dx, y + dy));
						}
					}
				}
			}
			if (isValid(p, cur_id)) {
				res = max(res, (int)p.size());
			}
		}
	}

	for (int i = 1; i + 2 < n; ++i) {
		for (int j = 1; j + 2 < m; ++j) {
			if (s[i][j] == '1' && s[i][j + 1] == '1' && s[i + 1][j] == '1' && s[i + 1][j + 1] == '1') {
				res = max(res, 4);
			}
		}
	}
	printf("%d\n", res);

	return 0;
}