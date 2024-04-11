#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <ctime>
#include <unordered_set>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 5100;
int n;
int a[maxN][3];
int s[3], c[3];
int l[6], r[6], p[6];

int w, scores[maxN];

int m;
int b[maxN][3];

int ans = n;

bool can(int solutions, int challenges, int group) {
	int xl = max(0, solutions - r[group]);
	int xr = min(challenges, solutions - l[group]);

	return xl <= xr;
}

bool isgood(int s, int c, int g) {
	return s - c >= l[g] && s - c <= r[g];
}

int getScore(int g, int t) {
	return t == 0 ? 0 : p[g] * (250 - abs(t)) / 250;
}

const int maxM = 95;
int d[2][maxM][maxM][maxM];

void solve(int g0, int g1, int g2, int score, int cnt) {
	int our = score + 100 * cnt;
	
	int added = upper_bound(scores, scores + w, our) - scores;
	added = w - added;

	if (added >= ans) {
		return ;
	}

	int u = 0, v = 1;
	for (int i = 0; i <= cnt; ++i) {
		for (int j = 0; i + j <= cnt; ++j) {
			for (int k = 0; i + j + k <= cnt; ++k) {
				d[u][i][j][k] = 1000;
			}
		}
	}
	d[u][0][0][0] = 0;
	for (int step = 0; step < m; ++step, swap(u, v)) {
		for (int i = 0; i <= cnt; ++i) {
			for (int j = 0; i + j <= cnt; ++j) {
				for (int k = 0; i + j + k <= cnt; ++k) {
					d[v][i][j][k] = 1000;
				}
			}
		}

		for (int i = 0; i <= cnt; ++i) {
			for (int j = 0; i + j <= cnt; ++j) {
				for (int k = 0; i + j + k <= cnt; ++k) {
					if (d[u][i][j][k] == 1000 || d[u][i][j][k] + added >= ans) {
						continue;
					}

					int g[3] = {getScore(g0, b[step][0]), getScore(g1, b[step][1]), getScore(g2, b[step][2])};
					int score = g[0] + g[1] + g[2];
					for (int mask = 0; mask < 8; ++mask) {
						int ii[3] = {i, j, k};
						int nscore = score;
						bool good = true;
						for (int l = 0; l < 3; ++l) {
							if (mask & (1 << l)) {
								if (b[step][l] >= 0) {
									good = false;
								}
								++ii[l];
								nscore -= g[l];
							}
						}
						if (!good) {
							continue;
						}
						int coef = (nscore > our ? 1 : 0);
						d[v][ii[0]][ii[1]][ii[2]] = min(d[v][ii[0]][ii[1]][ii[2]], d[u][i][j][k] + coef);
					}
				}
			}
		}
	}

	int res = 1000;
	for (int i = 0; i <= cnt; ++i) {
		for (int j = 0; i + j <= cnt; ++j) {
			if (isgood(s[0], i, g0) && isgood(s[1], j, g1) && isgood(s[2], cnt - i - j, g2)) {
				res = min(res, d[u][i][j][cnt - i - j]);
			}
		}
	}
	ans = min(ans, res + added);
}


void solve(int g0, int g1, int g2) {
	w = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i][0] >= 0 && a[i][1] >= 0 && a[i][2] >= 0) {
			scores[w ++] = getScore(g0, a[i][0]) + getScore(g1, a[i][1]) + getScore(g2, a[i][2]);
		}
	}
	sort(scores, scores + w);

	int our = getScore(g0, a[0][0]) + getScore(g1, a[0][1]) + getScore(g2, a[0][2]);
	for (int challenges = 0; challenges <= c[0] + c[1] + c[2]; ++challenges) {
		solve(g0, g1, g2, our, challenges);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < 6; ++i) {
		l[i] = n;
		r[i] = 0;
	}
	p[0] = 500;
	p[1] = 1000;
	p[2] = 1500;
	p[3] = 2000;
	p[4] = 2500;
	p[5] = 3000;
	for (int k = 0; k <= n; ++k) {
		if (n < 2 * k && 2 * k <= 2 * n) {
			l[0] = min(l[0], k);
			r[0] = max(r[0], k);
		}
		if (n < 4 * k && 4 * k <= 2 * n) {
			l[1] = min(l[1], k);
			r[1] = max(r[1], k);
		}
		if (n < 8 * k && 8 * k <= 2 * n) {
			l[2] = min(l[2], k);
			r[2] = max(r[2], k);
		}
		if (n < 16 * k && 16 * k <= 2 * n) {
			l[3] = min(l[3], k);
			r[3] = max(r[3], k);
		}
		if (n < 32 * k && 32 * k <= 2 * n) {
			l[4] = min(l[4], k);
			r[4] = max(r[4], k);
		}
		if (32 * k <= n) {
			l[5] = min(l[5], k);
			r[5] = max(r[5], k);
		}
	}
	for (int i = 0; i < n; ++i) {
		bool ok = false;
		for (int j = 0; j < 3; ++j) {
			scanf("%d", &a[i][j]);
			if (a[i][j] != 0) {
				++s[j];
			}
			if (a[i][j] < 0) {
				++c[j];
				ok = true;
			}
		}
		if (ok) {
			for (int j = 0; j < 3; ++j) {
				b[m][j] = a[i][j];
			}
			++m;
		}
	}

	if (c[0] + c[1] + c[2] >= 90) {
		printf("1\n");
		return 0;
	}

	ans = n - 1;
	can(2, 1, 1);
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			for (int k = 0; k < 6; ++k) {
				if (can(s[0], c[0], i) && can(s[1], c[1], j) && can(s[2], c[2], k)) {
					solve(i, j, k);
				}
			}
		}
	}
	printf("%d\n", ans + 1);


	return 0;
}