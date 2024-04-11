#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <string>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 410;

char s[maxN];
int L;
bool g[maxN][maxN];
int n, m;

char x[maxN], y[maxN];

int d[maxN];

char t[maxN], res[maxN];

bool finishLine(int start, int minvalue) {
	for (int i = start; i < n; ++i) {
		bool gv = true, gc = true;
		if (d[i] == 1) {
			gc = false;
		}
		if (d[i] == 0) {
			gv = false;
		}

		if (d[i] == -1) {
			for (int j = 0; j < 2 * n; ++j) {
				if (g[2 * i + 1][j]) {
					if (d[j / 2] != -1 && d[j / 2] != j % 2) {
						gv = false;
					}
				}
			}

			for (int j = 0; j < 2 * n; ++j) {
				if (g[2 * i][j]) {
					if (d[j / 2] != -1 && d[j / 2] != j % 2) {
						gc = false;
					}
				}
			}
		}

		bool nice = false;
		for (int j = (i == start ? minvalue : 0); j < L; ++j) {
			if (s[j] == 'V' && gv) {
				nice = true;
				for (int k = 0; k < 2 * n; ++k) {
					if (g[2 * i + 1][k]) {
						d[k / 2] = k % 2;
					}
				}
				d[i] = 1;
				res[i] = j + 'a';
				break;
			}
			if (s[j] == 'C' && gc) {
				nice = true;
				for (int k = 0; k < 2 * n; ++k) {
					if (g[2 * i][k]) {
						d[k / 2] = k % 2;
					}
				}
				d[i] = 0;
				res[i] = j + 'a';
				break;
			}
		}
		if (!nice) {
			return false;
		}
	}
	return true;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%s", &s);
	L = strlen(s);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int p1, p2;
		scanf("%d%s%d%s", &p1, &x, &p2, &y);
		--p1;
		--p2;
		
		int x1 = (x[0] == 'V' ? 1 : 0);
		int y1 = (y[0] == 'V' ? 1 : 0);

		g[p1 * 2 + x1][p2 * 2 + y1] = true;
		g[p2 * 2 + (1 - y1)][p1 * 2 + (1 - x1)] = true;
	}

	for (int i = 0; i < 2 * n; ++i) {
		g[i][i] = true;
	}

	for (int i = 0; i < 2 * n; ++i) {
		for (int j = 0; j < 2 * n; ++j) {
			for (int k = 0; k < 2 * n; ++k) {
				if (g[j][i] && g[i][k]) {
					g[j][k] = true;
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (g[2 * i][2 * i + 1] && g[2 * i + 1][2 * i]) {
			printf("-1\n");
			return 0;
		}
	}

	scanf("%s", &t);

	for (int i = 0; i < n; ++i) {
		d[i] = -1;
	}

	for (int common = n; common >= 0; --common) {
		for (int i = 0; i < common; ++i) {
			res[i] = t[i];
		}
		for (int i = 0; i < n; ++i) {
			d[i] = -1;
			if (g[2 * i][2 * i + 1]) {
				d[i] = 1;
			}
			if (g[2 * i + 1][2 * i]) {
				d[i] = 0;
			}
		}

		bool nice = true;
		for (int i = 0; i < common; ++i) {
			if (s[res[i] - 'a'] == 'V') {
				if (d[i] == 0) {
					nice = false;
				}
				d[i] = 1;
			}
			if (s[res[i] - 'a'] == 'C') {
				if (d[i] == 1) {
					nice = false;
				}
				d[i] = 0;
			}
		}
		
		while (true) {
			bool updates = false;
			for (int i = 0; i < n && nice; ++i) {
				if (d[i] == -1) {
					continue;
				}
				for (int j = 0; j < 2 * n && nice; ++j) {
					if (g[2 * i + d[i]][j] && (d[j / 2] != -1 && d[j / 2] != j % 2)) {
						nice = false;
					}
					if (g[2 * i + d[i]][j] && d[j / 2] == -1) {
						d[j / 2] = j % 2;
						updates = true;
					}
				}
			}
			if (!updates) {
				break;
			}
		}
		if (!nice) {
			continue;
		}
		if (finishLine(common, t[common] - 'a' + 1)) {
			puts(res);
			return 0;
		}
	}

	printf("-1\n");

	return 0;
}