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

const int maxN = 110;
int n, m, k;
int a[maxN][maxN];

int res = 1000000000;
int parts[maxN], c = 0;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	
	if (n > 10) {
		for (int i = 0; i < n; ++i) {
			int cnt = 0;
			for (int x = 0; x < n; ++x) {
				if (x == i) {
					continue;
				}
				int u = 0, v = 0;
				for (int y = 0; y < m; ++y) {
					if (a[x][y] == a[i][y]) {
						++u;
					} else {
						++v;
					}
				}
				cnt += min(u, v);
			}
			res = min(res, cnt);
		}
	} else {
		for (int mask = 0; mask < (1 << n); ++mask) {
			int current = 0;
			for (int i = 0; i < n; ++i) {
				if (mask & (1 << i)) {
					++current;
					a[i][0] = 1 - a[i][0];
				}
			}

			for (int i = 1; i < m; ++i) {
				int u = 0, v = 0;
				for (int j = 0; j < n; ++j) {
					if (a[j][i] == a[j][0]) {
						++u;
					} else {
						++v;
					}
				}
				current += min(u, v);
			}

			res = min(res, current);

			for (int i = 0; i < n; ++i) {
				if (mask & (1 << i)) {
					a[i][0] = 1 - a[i][0];
				}
			}
		}
	}

	if (res > k) {
		cout << -1 << endl;
	} else {
		cout << res << endl;
	}

	return 0;
}