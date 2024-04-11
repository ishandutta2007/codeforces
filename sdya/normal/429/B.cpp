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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100;
int n, m;
int a[maxN][maxN];
int s1[maxN][maxN], s2[maxN][maxN];
int s3[maxN][maxN], s4[maxN][maxN];

int dx[] = {-1, 0, 1, 0};
int dy[] = { 0,-1, 0, 1};

bool isValid(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			s1[i][j] = max(s1[i - 1][j], s1[i][j - 1]) + a[i][j];
		}
		for (int j = m; j >= 1; --j) {
			s4[i][j] = max(s4[i - 1][j], s4[i][j + 1]) + a[i][j];
		}
	}

	for (int i = n; i >= 1; --i) {
		for (int j = m; j >= 1; --j) {
			s2[i][j] = max(s2[i + 1][j], s2[i][j + 1]) + a[i][j];
		}
		for (int j = 1; j <= m; ++j) {
			s3[i][j] = max(s3[i + 1][j], s3[i][j - 1]) + a[i][j];
		}
	}

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int x[4], y[4];
			for (int k = 0; k < 4; ++k) {
				x[k] = i + dx[k];
				y[k] = j + dy[k];
			}

			vector < int > ca, cb;
			if (isValid(x[0], y[0])) {
				ca.push_back(0);
			}
			if (isValid(x[1], y[1])) {
				ca.push_back(1);
				cb.push_back(1);
			}
			if (isValid(x[2], y[2])) {
				cb.push_back(2);
			}

			vector < int > da, db;
			if (isValid(x[2], y[2])) {
				da.push_back(2);
			}
			if (isValid(x[3], y[3])) {
				da.push_back(3);
				db.push_back(3);
			}
			if (isValid(x[0], y[0])) {
				db.push_back(0);
			}

			for (int u = 0; u < ca.size(); ++u) {
				for (int v = 0; v < cb.size(); ++v) {
					if (ca[u] != cb[v]) {
						for (int s = 0; s < da.size(); ++s) {
							for (int t = 0; t < db.size(); ++t) {
								if (da[s] != db[t] && da[s] != cb[v] && db[t] != ca[u]) {
									res = max(res, s1[x[ca[u]]][y[ca[u]]] + s2[x[da[s]]][y[da[s]]] + s3[x[cb[v]]][y[cb[v]]] + s4[x[db[t]]][y[db[t]]]);
								}
							}
						}
					}
				}
			}
		}
	}

	printf("%d\n", res);

	return 0;
}