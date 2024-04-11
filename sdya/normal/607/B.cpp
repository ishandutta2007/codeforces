#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 600;
const int inf = 1000000;
int n;
int d[maxN][maxN];
int a[maxN];

int calc(int l, int r) {
	if (d[l][r] != -1) {
		return d[l][r];
	}
	if (l > r) {
		return 0;
	}

	int res = inf;
	for (int i = l + 1; i <= r; ++i) {
		res = min(res, calc(l, i - 1) + calc(i, r));
	}

	res = min(res, 1 + calc(l + 1, r));
	for (int i = l + 1; i <= r; ++i) {
		if (a[i] == a[l]) {
			res = min(res, max(1, calc(l + 1, i - 1)) + calc(i + 1, r));
		}
	}
	return d[l][r] = res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			d[i][j] = -1;
		}
	}

	printf("%d\n", calc(0, n - 1));



	return 0;
}