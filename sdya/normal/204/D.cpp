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

const int maxN = 1100000;
const int P = 1000000007;

void add(int &x, int delta) {
	x += delta;
	if (x >= P) {
		x -= P;
	}
}

int currentVersion = 0;

struct DP {
	int a[2 * maxN];
	int version[2 * maxN];
	int start;
	int lastZero;
	int sum;
	DP() {
		memset(a, 0, sizeof(a));
		memset(version, 0, sizeof(version));
		start = maxN;
		lastZero = -1;
		sum = 0;
	}

	void shift() {
		++currentVersion;
		--start;
	}

	void update(int k, int delta) {
		++currentVersion;
		if (version[start + k] < lastZero) {
			a[start + k] = 0;
		}
		add(a[start + k], delta);
		version[start + k] = currentVersion;
		add(sum, delta);
	}

	void setZero() {
		++currentVersion;
		lastZero = currentVersion;
		sum = 0;
	}

	int get(int k) {
		if (version[start + k] < lastZero) {
			a[start + k] = 0;
		}
		return a[start + k];
	}
};

DP d, c;
int L[maxN], R[maxN];
int n, k;
char s[maxN];
int sumB[maxN], sumW[maxN];

int getBlack(int l, int r) {
	return sumB[r] - (l == 0 ? 0 : sumB[l - 1]);
}

int getWhite(int l, int r) {
	return sumW[r] - (l == 0 ? 0 : sumW[l - 1]);
}

int getX(int l, int r) {
	return (r - l + 1) - getBlack(l, r) - getWhite(l, r);
}

long long dp[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	scanf("%s", &s);

	for (int i = 0; i < n; ++i) {
		sumB[i] = (s[i] == 'B');
		sumW[i] = (s[i] == 'W');
		if (i > 0) {
			sumB[i] += sumB[i - 1];
			sumW[i] += sumW[i - 1];
		}
	}

	d.update(0, 1);
	L[0] = 1;
	for (int i = 0; i < n; ++i) {
		int sum = d.sum;
		if (s[i] == 'B') {
			d.shift();
			int value = d.get(k);
			if (value > 0) {
				d.update(k, P - value);
			}
		} else if (s[i] == 'W') {
			d.setZero();
			d.update(0, sum);
		} else {
			d.shift();
			d.update(0, sum);
			int value = d.get(k);
			if (value > 0) {
				d.update(k, P - value);
			}
		}
		L[i + 1] = d.get(0);
	}

	c.update(0, 1);
	R[n] = 1;
	for (int i = n - 1; i >= 0; --i) {
		int sum = c.sum;
		if (s[i] == 'W') {
			c.shift();
			int value = c.get(k);
			if (value > 0) {
				c.update(k, P - value);
			}
		} else if (s[i] == 'B') {
			c.setZero();
			c.update(0, sum);
		} else {
			c.shift();
			c.update(0, sum);
			int value = c.get(k);
			if (value > 0) {
				c.update(k, P - value);
			}
		}
		R[i] = c.get(0);
	}

	long long res = 0;
	for (int i = k - 1; i + k < n; ++i) {
		long long coef = (s[i] == 'X' ? 2 : 1);
		bool can = (getWhite(i - k + 1, i) == 0);
		dp[i + 1] += dp[i] * coef;
		dp[i + 1] %= P;

		if (can) {
			dp[i + 1] += L[i - k + 1];
			dp[i + 1] %= P;
		}

		{
			bool can = (getBlack(i + 1, i + k) == 0);
			if (can) {
				res += dp[i + 1] * (long long)(R[i + k + 1]);
				res %= P;
			}
		}
	}

	printf("%d\n", (int)(res));

	return 0;
}