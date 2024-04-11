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
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 2100;
const int inf = 2000000000;
int n, k;
int a[maxN], p[maxN][maxN];
int dp[maxN];

bool check(int d) {
	dp[0] = 0;
	for (int i = 1; i <= n + 1; ++i) {
		dp[i] = inf;
		for (int j = 0; j < i; ++j) {
			if (p[j][i] <= d) {
				dp[i] = min(dp[i], dp[j] + (i - j - 1));
			}
		}
	}
	return dp[n + 1] <= k;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			p[i][j] = p[j][i] = (abs(a[i] - a[j]) + (j - i - 1)) / (j - i);
		}
		p[0][i] = 0;
		p[i][n + 1] = 0;
	}
	p[0][n + 1] = 0;

	long long left_bound = 0, right_bound = 2000000000;
	while (right_bound - left_bound > 1) {
		long long middle = (left_bound + right_bound) / 2;
		if (check(middle)) {
			right_bound = middle;
		} else {
			left_bound = middle;
		}
	}
	if (check(left_bound)) {
		printf("%d\n", (int)(left_bound));
	} else {
		printf("%d\n", (int)(right_bound));
	}



	return 0;
}