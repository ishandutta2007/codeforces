#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <string>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1010000;
int n, a[maxN];

int dp[maxN];
int have[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		++have[a[i]];
	}
	sort(a, a + n);
	for (int i = 1; i < maxN; ++i) {
		dp[i] = have[i];
	}
	for (int i = 1; i < maxN; ++i) {
		for (int j = i + i; j < maxN; j += i) {
			if (have[i] && have[j]) {
				dp[j] = max(dp[j], dp[i] + have[j]);
			}
		}
	}

	/*int ans = 0;
	for (int i = 0; i < n; ++i) {
		int v = a[i];
		int res = 0;
		for (int j = 0; j < d[v].size(); ++j) {
			res = max(res, dp[d[v][j]]);
		}
		dp[v] = max(dp[v], res + 1);
		ans = max(ans, res + 1);
	}
	printf("%d\n", ans);*/
	int ans = 0;
	for (int i = 1; i < maxN; ++i) {
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);

	return 0;
}