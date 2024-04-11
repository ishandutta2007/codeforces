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

const int maxN = 310;
int n, t;
int a[maxN];

int d[maxN][maxN];

void prepare() {
	vector < int > p(n);
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			p[j] = 0;
		}
		p[i] = 1;
		for (int j = i + 1; j < n; ++j) {
			if (a[j] < a[i]) {
				continue;
			}
			p[j] = 0;
			for (int k = i; k < j; ++k) {
				if (a[k] <= a[j]) {
					p[j] = max(p[j], p[k]);
				}
			}
			++p[j];
		}

		for (int j = i; j < n; ++j) {
			d[a[i]][a[j]] = max(d[a[i]][a[j]], p[j]);
		}
	}
}

int dp[110][110][110];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &t);
	vector < int > b;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		b.push_back(a[i]);
	}
	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end()) - b.begin());

	prepare();

	int m = b.size();

	for (int i = 0; i < maxN; ++i) {
		for (int j = i; j < maxN; ++j) {
			if (j > i) {
				d[i][j] = max(d[i][j], d[i][j - 1]);
			}
		}
	}

	for (int i = maxN - 1; i >= 0; --i) {
		for (int j = i; j < maxN; ++j) {
			if (i < j) {
				d[i][j] = max(d[i][j], d[i + 1][j]);
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			dp[1][i][j] = d[b[i]][b[j]];
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = j; k < m; ++k) {
				if (dp[i][j][k] == 0) {
					continue;
				}
				for (int l = k; l < m; ++l) {
					if (d[b[k]][b[l]] > 0) {
						dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j][k] + d[b[k]][b[l]]);
					}
				}
			}
		}
	}

	int res = 0;
	for (int l1 = 0; l1 <= n && l1 <= t; ++l1) {
		for (int l2 = 0; l2 <= n && l1 + l2 <= t; ++l2) {
			for (int k = 0; k < m; ++k) {
				int current = dp[l1][0][k] + dp[l2][k][m - 1] + (t - l1 - l2) * d[b[k]][b[k]];
				if (current > res) {
					res = current;
				}
				//res = max(res, current);
			}
		}
	}

	printf("%d\n", res);

	return 0;
}