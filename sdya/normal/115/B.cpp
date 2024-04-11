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

const int maxN = 200;
const int inf = 1000000;
int n, m;
string s[maxN];

int l[maxN], r[maxN];
int dp[maxN][maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		l[i] = m;
		r[i] = -1;

		for (int j = 0; j < m; ++j) {
			if (s[i][j] == 'W') {
				l[i] = min(l[i], j);
				r[i] = max(r[i], j);
			}
		}
	}

	while (n > 0 && r[n - 1] == -1) {
		--n;
	}
	if (n == 0) {
		printf("0\n");
		return 0;
	}

	for (int i = 0; i < m; ++i) {
		dp[0][i] = i;
		if (i < r[0]) {
			dp[0][i] = inf;
		}
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			dp[i][j] = inf;
		}
		if (i % 2 == 1) {
			for (int j = 0; j < m && j <= l[i]; ++j) {
				for (int k = max(j, r[i]); k < m; ++k) {
					dp[i][j] = min(dp[i][j], dp[i - 1][k] + 1 + k - j);
				}
			}
		} else {
			for (int j = max(0, r[i]); j < m; ++j) {
				for (int k = 0; k <= min(l[i], m - 1) && k <= j; ++k) {
					dp[i][j] = min(dp[i][j], dp[i - 1][k] + 1 + j - k);
				}
			}
		}
	}

	int res = ((n - 1) % 2 == 1 ? dp[n - 1][l[n - 1]] : dp[n - 1][r[n - 1]]);
	printf("%d\n", res);
	
	return 0;
}