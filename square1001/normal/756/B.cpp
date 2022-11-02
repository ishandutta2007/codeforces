#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
typedef long long ll;
int n, a[100009]; ll dp[100009];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + 20;
		int ptr1 = max(lower_bound(a, a + n + 1, a[i] - 89) - a - 1, 0);
		int ptr2 = max(lower_bound(a, a + n + 1, a[i] - 1439) - a - 1, 0);
		dp[i] = min(dp[i], dp[ptr1] + 50);
		dp[i] = min(dp[i], dp[ptr2] + 120);
		printf("%lld\n", dp[i] - dp[i - 1]);
	}
	return 0;
}