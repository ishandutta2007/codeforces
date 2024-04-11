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

const int P = 1000000007;
const int maxN = 2100;
int d[maxN][maxN];
int n, k;

inline void add(int &x, int value) {
	x += value;
	if (x >= P) {
		x -= P;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		d[1][i] = 1;
	}

	for (int i = 1; i < k; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (d[i][j] == 0) {
				continue;
			}
			for (int l = j; l <= n; l += j) {
				add(d[i + 1][l], d[i][j]);
			}
		}
	}

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		add(res, d[k][i]);
	}
	cout << res << endl;

	return 0;
}