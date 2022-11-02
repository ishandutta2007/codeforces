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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxD = 20;
const int maxN = 210000;
int a[maxN], n;

long long p[maxD][maxN], add[maxD][maxN];

bool isValid(int x) {
	return 2 <= x && x <= n;
}

void precalc() {
	for (int i = 2; i <= n; ++i) {
		long long s = 0;
		int value = i;
		s += a[i];
		value += a[i];
		if (!isValid(value)) {
			continue;
		}
		s += a[value];
		value -= a[value];
		if (!isValid(value)) {
			continue;
		}
		p[0][i] = value;
		add[0][i] = s;
	}

	for (int i = 1; i < maxD; ++i) {
		for (int j = 2; j <= n; ++j) {
			if (p[i - 1][j] == 0) {
				continue;
			}

			int k = p[i - 1][j];
			if (p[i - 1][k] == 0) {
				continue;
			}
			p[i][j] = p[i - 1][k];
			add[i][j] = add[i - 1][j] + add[i - 1][k];
		}
	}
}

long long calculate(int start) {
	a[1] = start;
	long long x = 1, y = 0;
	int ones = 1, length = 0;
	while (true) {
		if (length >= 2 * n) {
			return -1LL;
		}
		if (ones >= 2) {
			return -1LL;
		}
		if (x == 1) {
			y += a[x];
			x += a[x];
			if (x <= 0 || x > n) {
				return y;
			}

			if (x == 1) {
				++ones;
			}

			y += a[x];
			x -= a[x];
			if (x <= 0 || x > n) {
				return y;
			}
			if (x == 1) {
				++ones;
			}
			length += 2;
			continue;
		}

		bool can = false;
		for (int i = maxD - 1; i >= 0; --i) {
			if (p[i][x] != 0) {
				can = true;
				length += (1 << i);
				y += add[i][x];
				x = p[i][x];
				break;
			}
		}

		if (can) {
			if (x == 1) {
				++ones;
			}
			continue;
		}
		{
			y += a[x];
			x += a[x];
			if (x <= 0 || x > n) {
				return y;
			}

			if (x == 1) {
				++ones;
			}

			y += a[x];
			x -= a[x];
			if (x <= 0 || x > n) {
				return y;
			}
			if (x == 1) {
				++ones;
			}
			length += 2;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 2; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	precalc();

	for (int i = 1; i <= n - 1; ++i) {
		printf("%I64d\n", calculate(i));
	}

	return 0;
}