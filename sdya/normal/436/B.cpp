#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <bitset>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 2100;
int n, m, k;
char s[maxN][maxN];

bool valid(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d\n", &n, &m, &k);
	for (int i = 0; i < n; ++i) {
		gets(s[i]);
	}

	for (int i = 0; i < m; ++i) {
		int res = 0;
		for (int j = 1; j < n; ++j) {
			if (valid(j, i - j) && s[j][i - j] == 'R') {
				++res;
			}
			if (valid(j, i + j) && s[j][i + j] == 'L') {
				++res;
			}
			if (valid(0, i) && s[0][i] == 'D') {
				++res;
			}
			if (valid(j + j, i) && s[j + j][i] == 'U') {
				++res;
			}
		}
		printf("%d ", res);
	}
	printf("\n");

	return 0;
}