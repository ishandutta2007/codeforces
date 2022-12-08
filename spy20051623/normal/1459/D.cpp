#include <bits/stdc++.h>

using namespace std;

int n;
int a[105];
int b[105];
unordered_map<int, int> dp[105];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		sum += b[i];
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j >= 0; --j) {
			for (auto &k:dp[j]) {
				dp[j + 1][k.first + a[i]] = max(dp[j + 1][k.first + a[i]], k.second + b[i]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		double ans = 0;
		for (auto &j:dp[i]) {
			ans = max(ans, min(j.first * 1.0, sum * 0.5 + j.second * 0.5));
		}
		printf("%.9lf ", ans);
	}
	return 0;
}