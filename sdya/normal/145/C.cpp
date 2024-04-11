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

const int maxN = 110000;
const long long P = 1000000007LL;
int n, k;
int a[maxN];

map < int, int > M;

bool isLucky(int n) {
	while (n) {
		if (n % 10 != 4 && n % 10 != 7) {
			return false;
		}
		n /= 10;
	}
	return true;
}

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

const int maxK = 2000;
long long dp[maxK][maxK];

long long f[maxN];

long long cnk(long long n, long long k) {
	if (k > n) {
		return 0;
	}
	long long q = inv(f[k]) * inv(f[n - k]);
	q %= P;
	return (f[n] * q) % P;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	f[0] = 1LL;
	for (int i = 1; i < maxN; ++i) {
		f[i] = (f[i - 1] * (long long)(i)) % P;
	}

	scanf("%d%d", &n, &k);
	int m = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if (isLucky(a[i])) {
			++M[a[i]];
		} else {
			++m;
		}
	}

	vector < int > cnt;
	for (map < int, int > ::iterator it = M.begin(); it != M.end(); ++it) {
		cnt.push_back(it->second);
	}

	dp[0][0] = 1LL;
	for (int i = 0; i < cnt.size(); ++i) {
		for (int j = 0; j < maxK; ++j) {
			if (dp[i][j] == 0) {
				continue;
			}
			dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % P;
			dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * (long long)(cnt[i])) % P;
		}
	}

	long long res = 0LL;
	for (int i = 0; i < maxK && i <= k; ++i) {
		long long A = dp[cnt.size()][i];
		long long B = cnk(m, k - i);
		res += A * B;
		res %= P;
	}

	cout << res << endl;

	return 0;
}