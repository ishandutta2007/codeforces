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

const int maxN = 110;
const int P = 1000000007;
int n, a[maxN];

long long inv(long long a) {
	long long x1 = 1, b1 = a;
	long long x2 = 0, b2 = P;
	while (b2) {
		long long q = b1 / b2;
		b1 -= q * b2;
		x1 -= q * x2;
		swap(x1, x2);
		swap(b1, b2);
	}
	return ((x1 % P) + P) % P;
}

long long dp[maxN][maxN];
long long f[maxN];

long long solve(long long n, vector < int > current) {
	f[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		f[i] = (long long)(i) * f[i - 1];
		f[i] %= P;
	}
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (dp[i][j] == 0) {
				continue;
			}
			for (int k = current[i]; j + k <= n; ++k) {
				dp[i + 1][j + k] += dp[i][j] * inv(f[k]);
				dp[i + 1][j + k] %= P;
			}
		}
	}
	long long res = 0;
	for (int i = 0; i <= n; ++i) {
		res += dp[10][i] * f[i];
		res %= P;
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < 10; ++i) {
		cin >> a[i];
	}

	long long res = 0;
	for (int i = 1; i < 10; ++i) {
		vector < int > current;
		for (int j = 0; j < 10; ++j) {
			current.push_back(a[j]);
		}
		current[i] = max(0, current[i] - 1);
		res += solve(n - 1, current);
	}
	cout << (res % P) << endl;

	return 0;
}