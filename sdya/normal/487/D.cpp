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

const int maxN = 110000;
const int maxM = 12;
const int maxD = 150;

int n, m, q;
char s[maxN][maxM];

pair < int, int > d[maxN][maxM];

int l[maxN], r[maxN], cnt;

void update(int index) {
	for (int i = l[index]; i <= r[index]; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == '^') {
				d[i][j] = (i == l[index] ? make_pair(i, j) : d[i - 1][j]);
				continue;
			}
			if (s[i][j] == '>') {
				if (j == m - 1) {
					d[i][j] = make_pair(i, j);
				} else {
					bool good = false;
					for (int k = j + 1; k < m; ++k) {
						if (s[i][k] == '<') {
							d[i][j] = make_pair(-2, -2);
							good = true;
							break;
						}
						if (s[i][k] == '^') {
							d[i][j] = (i == l[index] ? make_pair(i, k) : d[i - 1][k]);
							good = true;
							break;
						}
					}
					if (!good) {
						d[i][j] = make_pair(i, m - 1);
					}
				}
				continue;
			}
			if (s[i][j] == '<') {
				if (j == 0) {
					d[i][j] = make_pair(i, j);
				} else {
					if (s[i][j - 1] == '>') {
						d[i][j] = make_pair(-2, -2);
					} else if (s[i][j - 1] == '^') {
						d[i][j] = (i == l[index] ? make_pair(i, j - 1) : d[i - 1][j - 1]);
					} else {
						d[i][j] = d[i][j - 1];
					}
				}
			}
		}
	}
}

pair < int, int > solve(int x, int y, int index) {
	pair < int, int > p = d[x][y];
	if (p.first == -2) {
		return p;
	}
	if (s[p.first][p.second] != '^') {
		return p;
	}
	if (index == 0) {
		return p;
	}
	return solve(p.first - 1, p.second, index - 1);
}

pair < int, int > solve(int x, int y) {
	for (int i = 0; i < cnt; ++i) {
		if (l[i] <= x && r[i] >= x) {
			pair < int, int > res = solve(x, y, i);
			if (res.first != -2) {
				if (s[res.first][res.second] == '^') {
					--res.first;
				} else if (s[res.first][res.second] == '>') {
					++res.second;
				} else {
					--res.second;
				}
			}
			return res;
		}
	}
	return make_pair(-2, -2);
}

void precalc() {
	int start = 0;
	cnt = 0;
	while (start < n) {
		l[cnt] = start;
		r[cnt] = min(n - 1, start + maxD - 1);
		start = r[cnt] + 1;
		++cnt; 
	}

	for (int i = 0; i < cnt; ++i) {
		update(i);
	}
}

char mode[5];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s[i]);
	}

	precalc();

	for (int i = 0; i < q; ++i) {
		scanf("%s", &mode);
		if (mode[0] == 'A') {
			int x, y;
			scanf("%d%d", &x, &y);
			pair < int, int > res = solve(x - 1, y - 1);
			printf("%d %d\n", res.first + 1, res.second + 1);
		} else {
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			scanf("%s", &mode);
			s[x][y] = mode[0];

			for (int j = 0; j < cnt; ++j) {
				if (l[j] <= x && r[j] >= x) {
					update(j);
				}
			}
		}
	}


	return 0;
}