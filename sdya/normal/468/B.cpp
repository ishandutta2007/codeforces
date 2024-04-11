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

const int maxN = 110000;
int n, a, b;
int p[maxN];

vector < pair < int, int > > g[maxN];
map < int, int > M;

int color[maxN];
int r[maxN];

void dfs(int v) {
	if (color[v] == -1) {
		bool x = false, y = false;
		for (int i = 0; i < g[v].size(); ++i) {
			if (g[v][i].second == 0) {
				x = true;
			}
			if (g[v][i].second == 1) {
				y = true;
			}
		}
		if (x && y) {
			printf("NO\n");
			exit(0);
		}
		if (x) {
			color[v] = 0;
		} else if (y) {
			color[v] = 1;
		} else {
			if (p[v] + p[v] == a) {
				color[v] = 0;
			} else if (p[v] + p[v] == b) {
				color[v] = 1;
			} else {
				printf("NO\n");
				exit(0);
			}
		}
	}

	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i].second != color[v]) {
			printf("NO\n");
			exit(0);
		}
		if (g[v][i].second == color[v] && color[g[v][i].first] == -1) {
			color[g[v][i].first] = color[v];
			dfs(g[v][i].first);
		}
		if (color[g[v][i].first] != color[v]) {
			printf("NO\n");
			exit(0);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
		M[p[i]] = i;
	}

	if (a == b) {
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			if (M.count(a - p[i]) == 0) {
				ok = false;
				break;
			}
		}
		if (ok) {
			printf("YES\n");
			for (int i = 0; i < n; ++i) {
				printf("0 ");
			}
			printf("\n");
		} else {
			printf("NO\n");
		}
		return 0;
	}

	memset(color, -1, sizeof(color));
	set < pair < int, int > > S;
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		if (a - p[i] != p[i] && M.count(a - p[i])) {
			++cnt;
		}
		if (b - p[i] != p[i] && M.count(b - p[i])) {
			++cnt;
		}
		r[i] = cnt;
		if (cnt != 0) {
			S.insert(make_pair(cnt, i));
		} else {
			if (p[i] + p[i] == a) {
				color[i] = 0;
			} else if (p[i] + p[i] == b) {
				color[i] = 1;
			} else {
				printf("NO\n");
				return 0;
			}
		}
	}
	while (!S.empty()) {
		pair < int, int > current = *S.begin();
		int v = current.second;

		if (current.first == 2) {
			printf("NO\n");
			return 0;
		}

		vector < int > path;
		int m = 0;
		if (b - p[v] != p[v] && M.count(b - p[v])) {
			m = 1;
		}

		int start = m;

		while (true) {
			path.push_back(v);
			if (m == 0) {
				if (a - p[v] != p[v] && M.count(a - p[v])) {
					v = M[a - p[v]];
				} else {
					break;
				}
			} else {
				if (b - p[v] != p[v] && M.count(b - p[v])) {
					v = M[b - p[v]];
				} else {
					break;
				}
			}
			m = 1 - m;
		}

		if (path.size() % 2 == 0) {
			for (int i = 0; i < path.size(); ++i) {
				color[path[i]] = start;
				S.erase(make_pair(r[path[i]], path[i]));
			}
		} else {
			if (m == 0) {
				if (p[path[0]] + p[path[0]] == b) {
					for (int i = 0; i < path.size(); ++i) {
						color[path[i]] = 1;
						S.erase(make_pair(r[path[i]], path[i]));
					}
				} else if (p[path.back()] + p[path.back()] == a) {
					for (int i = 0; i < path.size(); ++i) {
						color[path[i]] = 0;
						S.erase(make_pair(r[path[i]], path[i]));
					}
				} else {
					printf("NO\n");
					return 0;
				}
			} else {
				if (p[path[0]] + p[path[0]] == a) {
					for (int i = 0; i < path.size(); ++i) {
						color[path[i]] = 0;
						S.erase(make_pair(r[path[i]], path[i]));
					}
				} else if (p[path.back()] + p[path.back()] == b) {
					for (int i = 0; i < path.size(); ++i) {
						color[path[i]] = 1;
						S.erase(make_pair(r[path[i]], path[i]));
					}
				} else {
					printf("NO\n");
					return 0;
				}
			}
		}
	}

	printf("YES\n");
	for (int i = 0; i < n; ++i) {
		printf("%d ", color[i]);
	}
	printf("\n");

	return 0;
}