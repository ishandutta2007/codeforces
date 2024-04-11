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

const int maxN = 510000;
const int maxL = 12;
const int maxD = 26;
const int inf = 1000000000;
char s[maxN][maxL];
int n;

int d[2][maxD][maxD];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i) {
		gets(s[i]);
	}

	int u = 0, v = 1;
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			d[u][i][j] = -inf;
		}
	}
	for (int step = 0; step < n; ++step, swap(u, v)) {
		int m = strlen(s[step]);
		int x = s[step][0] - 'a';
		int y = s[step][m - 1] - 'a';

		for (int i = 0; i < 26; ++i) {
			for (int j = 0; j < 26; ++j) {
				d[v][i][j] = d[u][i][j];
			}
		}
		for (int i = 0; i < 26; ++i) {
			for (int j = 0; j < 26; ++j) {
				if (d[u][i][j] != -inf && x == j) {
					d[v][i][y] = max(d[v][i][y], d[u][i][j] + m);
				}
			}
		}
		d[v][x][y] = max(d[v][x][y], m);
	}

	int res = 0;
	for (int i = 0; i < 26; ++i) {
		res = max(res, d[u][i][i]);
	}

	printf("%d\n", res);

	return 0;
}