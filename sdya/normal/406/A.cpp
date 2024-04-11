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
int n, a[maxN][maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}

	int m;
	scanf("%d", &m);

	int score = 0;
	for (int i = 0; i < n; ++i) {
		score ^= a[i][i];
	}

	for (int i = 0; i < m; ++i) {
		int mode;
		scanf("%d", &mode);
		if (mode == 1 || mode == 2) {
			int j;
			scanf("%d", &j);
			score ^= 1;
		} else {
			printf("%d", score);
		}
	}
	printf("\n");

	return 0;
}