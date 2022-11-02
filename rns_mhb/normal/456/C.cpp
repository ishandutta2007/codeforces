#include <bits/stdc++.h>
using namespace std;

#define N 100010

int n;
long long sz[N], arr[N], dp[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &arr[i]);
		sz[arr[i]] += arr[i];
	}
	dp[1] = sz[1];
	dp[2] = max(dp[1], sz[2]);
	for (int i = 3; i <= 100000; i ++) dp[i] = max(max(sz[i] + dp[i - 2], dp[i - 1]), dp[i - 3]);
	printf("%I64d", dp[100000]);
}