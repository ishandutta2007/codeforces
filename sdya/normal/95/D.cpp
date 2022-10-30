#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100;
int t, L;
const long long P = 1000000007LL;
long long d[maxN], p[maxN];

long long dp[maxN][maxN];

char a[maxN], b[maxN];

void precalc() {
	p[0] = 1LL;
	for (int i = 1; i < maxN; ++i) {
		p[i] = p[i - 1] * 8LL;
		p[i] %= P;
	}
	memset(dp, 0, sizeof(dp));
	d[0] = 1;
	dp[1][0] = 8;
	dp[1][1] = 2;
	for (int j = 1; j + 1 < maxN; ++j) {
		for (int k = 0; k <= j; ++k) {
			if (dp[j][k] == 0) {
				continue;
			}

			dp[j + 1][k] += 8LL * dp[j][k];
			dp[j + 1][k] %= P;

			if (k == 0 || (j + 1 - k > L)) {
				dp[j + 1][j + 1] += 2LL * dp[j][k];
				dp[j + 1][j + 1] %= P;
			}
		}
	}

	for (int j = 1; j < maxN; ++j) {
		for (int k = 0; k <= j; ++k) {
			d[j] += dp[j][k];
			d[j] %= P;
		}
	}
}

long long solve(char s[]) {
	int n = strlen(s);
	memset(dp, 0, sizeof(dp));

	vector < int > good;
	int gd = 0;
	long long res = 0;
	for (int i = 0; i <= n; ++i) {
		if (i > 0 && (s[i - 1] == '4' || s[i - 1] == '7')) {
			good.push_back(i - 1);
			++gd;
		}
		if (gd >= 2 && good[gd - 1] - good[gd - 2] <= L) {
			break;
		}
		if (i == n) {
			++res;
			res %= P;
			continue;
		}

		for (int j = 0; j < s[i] - '0'; ++j) {
			int last = -1;
			if (gd >= 1) {
				last = good[gd - 1];
			}

			if (j == 4 || j == 7) {
				if (last != -1 && i - last <= L) {
					continue;
				}
				last = i;
			}

			int length = n - i - 1;
			if (last >= 0) {
				length = n - max(i, last + L) - 1;
			}
			if (length <= 0) {
				length = 0;
			}
			res += d[length] * p[n - i - 1 - length];
			res %= P;
		}
	}

	long long total = 0LL;
	for (int i = 0; i < n; ++i) {
		total = total * 10LL + (s[i] - '0');
		total %= P;
	}
	++total;
	total -= res;
	return ((total % P) + P) % P;
}

bool isOk(char s[]) {
	int n = strlen(s);
	vector < int > good;
	int gd = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '4' || s[i] == '7') {
			++gd;
			good.push_back(i);
		}
		if (gd >= 2 && good[gd - 1] - good[gd - 2] <= L) {
			return true;
		}
	}
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &t, &L);
	precalc();

	for (int i = 1; i <= t; ++i) {
		scanf("%s%s", &a, &b);
		long long res = solve(b) - solve(a);
		if (isOk(a)) {
			++res;
		}
		res = ((res % P) + P) % P;
		printf("%d\n", (int)(res));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
	}
	
	return 0;
}