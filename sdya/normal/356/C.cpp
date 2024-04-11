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

const int inf = 1000000000;
int a[5], b[5];
int n, total;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	total = 0;
	for (int i = 0; i < n; ++i) {
		int v;
		scanf("%d", &v);
		++a[v];
		total += v;
	}

	int res = inf;
	for (int X = 0; X <= n && X * 4 <= total; ++X) {
		if ((total - X * 4) % 3 != 0) {
			continue;
		}
		int Y = (total - X * 4) / 3;
		int x = X;
		int y = Y;
		if (x + y > n) {
			continue;
		}

		for (int i = 0; i <= 4; ++i) {
			b[i] = a[i];
		}
		int r4 = min(x, b[4]);
		x -= r4;
		b[4] -= r4;
		if (b[4] > 0) {
			b[3] += b[4];
		}

		int r3 = min(y, b[3]);
		y -= r3;
		b[3] -= r3;

		int rem = 4 * x + 3 * y;
		int cnt = x + y;
		int score = 0;
		for (int i = 3; i >= 0; --i) {
			int u = min(cnt, b[i]);
			cnt -= u;
			score += u * i;
		}
		if (cnt == 0) {
			res = min(res, rem - score);
		}
	}

	if (res == inf) {
		res = -1;
	}
	printf("%d\n", res);


	return 0;
}