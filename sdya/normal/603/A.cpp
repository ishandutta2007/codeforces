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
const int inf = 1000000000;
int n;
char s[maxN];

int d[maxN][2][3];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	scanf("%s", &s);

	for (int i = 0; i < maxN; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 3; ++k) {
				d[i][j][k] = 0;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 3; ++k) {
				d[i + 1][j][k] = max(d[i + 1][j][k], d[i][j][k]);
				d[i + 1][j][2] = max(d[i + 1][j][2], d[i][j][k]);
				if (k == 0 || k == 1) {
					if (s[i] - '0' == j) {
						d[i + 1][1 - j][1] = max(d[i + 1][1 - j][1], d[i][j][k] + 1);
					}
				}
				if (k == 0) {
					if (s[i] - '0' != j) {
						d[i + 1][1 - j][k] = max(d[i + 1][1 - j][k], d[i][j][k] + 1);
					}
				}
				if (k == 1 || k == 2) {
					if (s[i] - '0' != j) {
						d[i + 1][1 - j][2] = max(d[i + 1][1 - j][2], d[i][j][k] + 1);
					}
				}
			}
		}
	}

	int res = 0;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			res = max(res, d[n][i][j]);
		}
	}
	printf("%d\n", res);


	return 0;
}