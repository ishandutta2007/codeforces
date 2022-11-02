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

const long long P = 1000000007LL;
const long long P2 = 6LL * P * P;

long long powmod(long long a, long long n) {
	if (n == 0) {
		return 1LL % P;
	}
	long long b = powmod(a, n / 2);
	b = (b * b) % P;
	if (n % 2 == 1) {
		b = (b * a) % P;
	}
	return b;
}

const int maxN = 110;
long long c[maxN][maxN];
long long n, m;
long long f[maxN];
long long ways[maxN][maxN];

long long get(long long x) {
	return 1 + (m - x) / n;
}

long long dp[maxN][maxN * maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 0; i < maxN; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % P;
		}
	}

	long long k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		f[i] = get(i);
	}

	for (int i = 0; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			ways[j][i] = powmod(c[n][i], f[j]);
		}
	}

	dp[0][0] = 1LL;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			if (dp[i][j] == 0) {
				continue;
			}
			dp[i][j] %= P;
			for (int x = 0; x <= n && j + x <= k; ++x) {
				dp[i + 1][j + x] += dp[i][j] * ways[i + 1][x];
				if (dp[i + 1][j + x] >= P2) {
					dp[i + 1][j + x] -= P2;
				}
			}
		}
	}

	cout << (dp[n][k] % P) << endl;
	//cerr << clock() << endl;

	return 0;
}