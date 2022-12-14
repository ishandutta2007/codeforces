#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e7 + 5;
int n, P, dp[N];

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> P;
	dp[n] = 1;
	for (int i = n - 1; i; --i) {
		// k * i <= j < (k + 1) * i
		// k <= j / i < k + 1
		//
		for (int k = 1; k * i <= n; ++k) {
			dp[i] = (dp[i] + 1ll * k * ((k == 1 ? dp[k * i + 1] : dp[k * i]) - dp[(k + 1) * i])) % P;
		}
		for (int k = 1; k * (i + 1) <= n; ++k) {
			dp[i] = (dp[i] - 1ll * k * (dp[k * (i + 1)] - dp[(k + 1) * (i + 1)])) % P;
		}
		dp[i] = (dp[i] + 2ll * dp[i + 1]) % P;
		// for (int j = i + 1; j <= n; ++j)
			// dp[i] = (dp[i] + dp[j] * (j / i - j / (i + 1) + 1)) % P;
	}
	printf("%d\n", ((dp[1] - dp[2]) % P + P) % P);
}
// x / y = z
// z <= x / y < z+1
// z <= x / y => x / y >= z, y <= x / z
// x / y < z + 1, y > x / (z + 1), x / z - x / (z + 1)