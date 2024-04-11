#include <iostream>
#include <algorithm>
using namespace std;
int n, a[100009], dp[100009];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		if (a[i - 1] < a[i]) dp[i] = dp[i - 1] + 1;
		else dp[i] = 1;
	}
	printf("%d\n", *max_element(dp, dp + n));
	return 0;
}