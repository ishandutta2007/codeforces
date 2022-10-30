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

const int maxN = 2100;
const int inf = 1000000000;
char s[maxN], p[maxN];
int n, m;

int l[maxN];
int d[maxN][maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", &s);
	scanf("%s", &p);
	n = strlen(s);
	m = strlen(p);

	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		l[i] = -1;
		for (int j = i; j >= 0; --j) {
			if (s[j] == p[m - 1 - cnt]) {
				++cnt;
				if (cnt == m) {
					l[i] = j;
					break;
				}
			}
		}
	}

	for (int i = 0; i < maxN; ++i) {
		for (int j = 0; j < maxN; ++j) {
			d[i][j] = inf;
		}
	}

	d[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			d[i][j] = min(d[i][j], d[i - 1][j]);
			if (l[i - 1] == -1) {
				continue;
			}

			if (j > 0) {
				int added = (i - l[i - 1] - m);
				d[i][j] = min(d[i][j], d[l[i - 1]][j - 1] + added);
			}
		}
	}

	for (int i = 0; i <= n; ++i) {
		int res = 0;
		for (int j = 0; j <= n; ++j) {
			if (d[n][j] == inf) {
				continue;
			}
			int a = d[n][j];
			int b = n - j * m;
			if (i >= a && i <= b) {
				res = j;
			}
		}
		printf("%d ", res);
	}
	printf("\n");

	return 0;
}