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

const int maxN = 16;
const int maxK = 122;
const int inf = 1000000000;

int d[1 << maxN][maxK];
string c[maxN];
int r[maxN], b[maxN], color[maxN];
int n;

int cr[1 << maxN], cb[1 << maxN];

int calc(int mask, int x) {
	if (d[mask][x] != -1) {
		return d[mask][x];
	}
	if (mask == 0) {
		return d[mask][x] = (x == 0 ? 0 : -inf);
	}

	int res = -inf;
	for (int i = 0; i < n; ++i) {
		if (!(mask & (1 << i))) {
			continue;
		}

		int u = cr[mask ^ (1 << i)];
		int v = cb[mask ^ (1 << i)];

		int p = max(r[i] - u, 0);
		int q = max(b[i] - v, 0);

		int dp = r[i] - p;
		int dq = b[i] - q;

		if (dp <= x) {
			res = max(res, calc(mask ^ (1 << i), x - dp) + dq);
		}
	}

	if (res < 0) {
		res = -inf;
	}
	return d[mask][x] = res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	int sr = 0, sb = 0;
	for (int i = 0; i < n; ++i) {
		cin >> c[i] >> r[i] >> b[i];
		color[i] = (c[i] == "R");
		sr += r[i];
		sb += b[i];
	}

	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				if (color[j] == 1) {
					++cr[i];
				} else {
					++cb[i];
				}
			}
		}
	}

	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < maxK; ++j) {
			d[i][j] = -1;
		}
	}

	int res = 1000000000;
	for (int i = 0; i < maxK; ++i) {
		int v = calc((1 << n) - 1, i);
		int cur = max(sr - i, sb - v);
		res = min(res, cur);
	}

	cout << n + res << endl;

	//cerr << clock() << endl;


	return 0;
}