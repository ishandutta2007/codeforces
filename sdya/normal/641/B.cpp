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

const int maxN = 11000;

int t[maxN];
int r[maxN];
int c[maxN];
int x[maxN];

int res[110][110];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m, q;

	scanf("%d%d%d", &n, &m, &q);

	for (int i = 0; i < q; ++i) {
		scanf("%d", &t[i]);
		if (t[i] == 1) {
			scanf("%d", &r[i]);
			--r[i];
		} else if (t[i] == 2) {
			scanf("%d", &c[i]);
			--c[i];
		} else {
			scanf("%d%d%d", &r[i], &c[i], &x[i]);
			--r[i], --c[i];

			for (int j = i - 1; j >= 0; --j) {
				if (t[j] == 3) {
					continue;
				}
				if (t[j] == 1) {
					c[i] += (r[i] == r[j]);
					if (c[i] >= m) {
						c[i] -= m;
					}
				} else if (t[j] == 2) {
					r[i] += (c[i] == c[j]);
					if (r[i] >= n) {
						r[i] -= n;
					}
				}
			}
			res[r[i]][c[i]] = x[i];
		}
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	return 0;
}