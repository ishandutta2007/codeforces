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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 80;
long long f[maxN];
int d[maxN];

const int maxD = 1000;
const int K = 13;
int dp[maxD][maxD];
bool filled = false;

pair < int, int > get(int order, long long x) {
	if (order == K && filled) {
		return make_pair(dp[x][1], dp[x][f[K]]);
	}
	if (order == 0) {
		return make_pair(0, 0);
	}
	if (order == 1) {
		return make_pair(x != 1, x != 2);
	}

	if (x > f[order - 1]) {
		int add = 0;
		while (order > 1 && x > f[order - 1]) {
			x -= f[order - 1];
			order -= 2;
			++add;
		}
		pair < int, int > current = get(order, x);
		return make_pair(current.first + add, current.second);
	}

	pair < int, int > current = get(order - 1, x);
	int toOne = min(current.first, current.second + 2);
	int toN = min(current.first, current.second) + 1 + d[order - 2];
	return make_pair(toOne, toN);
}

int calc(int order, long long x, long long y) {
	if (order == K && filled) {
		return dp[x][y];
	}
	if (x == y) {
		return 0;
	}
	if (x > y) {
		swap(x, y);
	}
	if (order == 1) {
		return x != y;
	}
	if (order == 0) {
		return 0;
	}
	if (f[order - 1] >= y) {
		pair < int, int > a = get(order - 1, x);
		pair < int, int > b = get(order - 1, y);
		int score = min(a.first + b.second, a.second + b.first) + 2;
		return min(score, calc(order - 1, x, y));
	}

	if (x > f[order - 1]) {
		while (order > 1 && x > f[order - 1]) {
			x -= f[order - 1];
			y -= f[order - 1];
			order -= 2;
		}
		return calc(order, x, y);
	}

	pair < int, int > a = get(order - 2, y - f[order - 1]);
	pair < int, int > b = get(order - 1, x);
	return min(b.first, b.second) + 1 + a.first;
}

void gen() {
	int t = 100000;
	int n = 1000;
	cout << t << " " << n << endl;
	for (int i = 0; i < t; ++i) {
		long long x = 1LL * rand() * rand() * rand() + 1LL;
		long long y = 1LL * rand() * rand() * rand() + 1LL;
		cout << x << " " << y << endl;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen();

	f[0] = 1;
	f[1] = 2;
	for (int i = 2; i < maxN; ++i) {
		f[i] = f[i - 1] + f[i - 2];
	}

	d[0] = 0;
	d[1] = 1;
	for (int i = 2; i < maxN; ++i) {
		d[i] = d[i - 2] + 1;
	}

	for (int i = 1; i <= f[K]; ++i) {
		for (int j = i; j <= f[K]; ++j) {
			dp[i][j] = dp[j][i] = calc(K, i, j);
		}
	}

	cerr << clock() << endl;
	filled = true;

	int t, n;
	scanf("%d%d", &t, &n);
	if (n >= maxN) {
		n = maxN - 1;
	}

	for (int i = 1; i <= t; ++i) {
		long long u, v;
		scanf("%I64d%I64d", &u, &v);
		if (u > v) {
			swap(u, v);
		}
		int m = n;
		while (m > 20 && f[m - 5] >= v) {
			--m;
		}
		printf("%d\n", calc(m, u, v));
	}
	cerr << clock() << endl;

	return 0;
}