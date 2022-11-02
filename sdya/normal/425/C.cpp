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

const int maxN = 110000;
const int maxK = 310;
int n, m, s, e;
int a[maxN], b[maxN];

int d[maxK][maxN];

vector < int > p[maxN];

int getIndex(int value, int position) {
	int i = upper_bound(p[value].begin(), p[value].end(), position) - p[value].begin();
	if (i == p[value].size()) {
		return m;
	}
	return p[value][i];
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d%d", &n, &m, &s, &e);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &b[i]);
		p[b[i]].push_back(i);
	}

	int res = 0;
	for (int i = 0; i < n; ++i) {
		d[1][i] = getIndex(a[i], -1);
		if (i > 0) {
			d[1][i] = min(d[1][i], d[1][i - 1]);
		}
	}

	for (int c = 1; c + 1 < maxK; ++c) {
		for (int i = 0; i < n; ++i) {
			d[c + 1][i] = m;
		}
		for (int i = 0; i + 1 < n; ++i) {
			if (d[c][i] == m) {
				continue;
			}
			int value = getIndex(a[i + 1], d[c][i]);
			d[c + 1][i + 1] = min(d[c + 1][i + 1], value);
		}
		for (int i = 1; i < n; ++i) {
			d[c + 1][i] = min(d[c + 1][i], d[c + 1][i - 1]);
		}
	}

	for (int c = 1; c < maxK && c * e <= s; ++c) {
		for (int i = 0; i < n; ++i) {
			if (d[c][i] == m) {
				continue;
			}

			int needed = c * e + (i + 1) + (d[c][i] + 1);
			if (needed <= s) {
				res = max(res, c);
			}
		}
	}

	printf("%d\n", res);


	return 0;
}