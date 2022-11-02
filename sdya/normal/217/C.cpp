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

const int maxN = 1100000;

// & - 0, ^ - 1, | - 2
int a[maxN];
int x[maxN], y[maxN];

int n;
char s[maxN];
int m = 0;
int p[maxN];

int k;
int pos[maxN];

int build(int l, int r) {
	if (l == r) {
		int res = k;
		pos[k++] = l;
		return res;
	}

	int t = (s[l] == '(' ? p[l] : l);
	if (t == r) {
		return build(l + 1, r - 1);
	}

	int u = build(l, t);
	int v = build(t + 2, r);
	int res = k++;
	a[res] = (s[t + 1] == '&' ? 0 : (s[t + 1] == '^' ? 1 : 2));
	x[res] = u;
	y[res] = v;
	return res;
}

int can[2][2][maxN];

void dfs(int v) {
	if (x[v] != -1) {
		dfs(x[v]);
	}
	if (y[v] != -1) {
		dfs(y[v]);
	}

	if (pos[v] != -1) {
		if (s[pos[v]] == '0') {
			can[0][0][v] = 1;
		} else if (s[pos[v]] == '1') {
			can[1][1][v] = 1;
		} else {
			can[0][1][v] = can[1][0][v] = 1;
		}
		return ;
	}

	int p = x[v];
	int q = y[v];
	for (int a1 = 0; a1 < 2; ++a1) {
		for (int b1 = 0; b1 < 2; ++b1) {
			for (int a2 = 0; a2 < 2; ++a2) {
				for (int b2 = 0; b2 < 2; ++b2) {
					if (!can[a1][b1][p] || !can[a2][b2][q]) {
						continue;
					}

					int x, y;
					if (a[v] == 0) {
						x = (a1 & a2);
						y = (b1 & b2);
					} else if (a[v] == 1) {
						x = (a1 ^ a2);
						y = (b1 ^ b2);
					} else {
						x = (a1 | a2);
						y = (b1 | b2);
					}
					can[x][y][v] = 1;
				}
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	scanf("%s", &s);
	m = strlen(s);
	vector < int > q;
	for (int i = 0; i < m; ++i) {
		if (s[i] == '(') {
			q.push_back(i);
		} else if (s[i] == ')') {
			p[q.back()] = i;
			p[i] = q.back();
			q.pop_back();
		}
	}

	memset(x, -1, sizeof(x));
	memset(y, -1, sizeof(y));
	memset(pos, -1, sizeof(pos));
	int t = build(0, m - 1);

	dfs(t);

	if (can[0][1][t] || can[1][0][t]) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	return 0;
}