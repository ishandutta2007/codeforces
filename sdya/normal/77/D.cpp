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

const int maxN = 1200;
char s[maxN][maxN];
int n, m;

int value[maxN][maxN], h[maxN][maxN], v[maxN][maxN];

const long long P = 1000000007LL;

long long ways2[maxN];
long long ways1[maxN];

long long c[maxN];
long long d[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < 4 * n + 1; ++i) {
		scanf("%s", &s[i]);
	}

	for (int i = 1; i < 4 * n + 1; i += 4) {
		for (int j = 1; j < 4 * m + 1; j += 4) {
			for (int a = i; a < i + 3; ++a) {
				for (int b = j; b < j + 3; ++b) {
					if (s[a][b] == 'O') {
						++value[i / 4][j / 4];
					}
				}
			}
			if (value[i / 4][j / 4] == 2 || value[i / 4][j / 4] == 3) {
				if (s[i][j] == 'O') {
					h[i / 4][j / 4] = 1;
					v[i / 4][j / 4] = 0;
				} else {
					h[i / 4][j / 4] = 0;
					v[i / 4][j / 4] = 1;
				}
			} else if (value[i / 4][j / 4] == 6) {
				if (s[i + 1][j] != 'O') {
					h[i / 4][j / 4] = 1;
					v[i / 4][j / 4] = 0;
				} else {
					h[i / 4][j / 4] = 0;
					v[i / 4][j / 4] = 1;
				}
			} else {
				h[i / 4][j / 4] = 1;
				v[i / 4][j / 4] = 1;
			}
		}
	}

	for (int j = 0; j < m; ++j) {
		if (n % 2 != 0) {
			ways1[j] = 0;
			continue;
		}
		ways1[j] = 1;
		for (int i = 0; i < n; i += 2) {
			if (v[i][j] && v[i + 1][j]) {
				continue;
			}
			ways1[j] = 0;
			break;
		}
	}

	for (int j = 0; j + 1 < m; ++j) {
		vector < long long > dp(n + 1, 0);
		dp[0] = 1LL;
		for (int i = 0; i < n; ++i) {
			if (h[i][j] && h[i][j + 1]) {
				dp[i + 1] += dp[i];
				dp[i + 1] %= P;
			}
			if (i + 2 <= n) {
				if (v[i][j] && v[i + 1][j] && v[i][j + 1] && v[i + 1][j + 1]) {
					dp[i + 2] += dp[i];
					dp[i + 2] %= P;
				}
			}
		}
		ways2[j] = dp[n];
		if (n % 2 == 0 && ways1[j] == 1 && ways1[j + 1] == 1) {
			ways2[j] = (ways2[j] + P - 1) % P;
		}
	}

	c[0] = ways1[0];
	d[0] = 0LL;
	for (int i = 1; i < m; ++i) {
		c[i] = (c[i - 1] + d[i - 1]) * ways1[i];
		c[i] %= P;

		if (i == 1) {
			d[i] = ways2[i - 1];
		} else {
			d[i] = (c[i - 2] + d[i - 2]) * ways2[i - 1];
			d[i] %= P;
		}
	}

	cout << (c[m - 1] + d[m - 1]) % P << endl;

	return 0;
}