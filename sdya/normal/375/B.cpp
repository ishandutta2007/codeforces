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

const int maxN = 5100;
char s[maxN][maxN];
int d[maxN][maxN];
int cnt[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s[i]);
		for (int j = m - 1; j >= 0; --j) {
			if (s[i][j] == '1') {
				d[i][j] = 1;
				if (j + 1 < m) {
					d[i][j] = max(d[i][j], d[i][j + 1] + 1);
				}
			}
		}
	}
	int res = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < maxN; ++j) {
			cnt[j] = 0;
		}
		for (int j = 0; j < n; ++j) {
			++cnt[d[j][i]];
		}

		for (int j = maxN - 2; j >= 0; --j) {
			cnt[j] += cnt[j + 1];
		}
		for (int j = 0; j < maxN; ++j) {
			res = max(res, j * cnt[j]);
		}
	}
	printf("%d\n", res);

	return 0;
}