#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
typedef long long ll;
int n; ll c[100009], dp[100009][2]; string s[100009], rs[100009];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);
	for (int i = 1; i <= n; i++) {
		cin >> s[i]; rs[i] = s[i];
		reverse(rs[i].begin(), rs[i].end());
	}
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i][1] = 1LL << 60;
		if (s[i - 1] <= s[i]) dp[i][0] = dp[i - 1][0];
		if (s[i - 1] <= rs[i]) dp[i][1] = dp[i - 1][0] + c[i];
		if (rs[i - 1] <= s[i]) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
		if (rs[i - 1] <= rs[i]) dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
	}
	ll ret = min(dp[n][0], dp[n][1]);
	if (ret == 1LL << 60) puts("-1");
	else printf("%lld\n", ret);
	return 0;
}