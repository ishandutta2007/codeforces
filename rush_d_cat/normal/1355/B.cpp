#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const int inf = 1e9;
int T, a[N], n;
int dp[N], mx[N];
int main() {
	scanf("%d", &T);
	while (T --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= n; i ++) {
			dp[i] = -inf, mx[i] = -inf;
		}

		for (int i = 1; i <= n; i ++) {
			int pos = i - a[i];
			if (pos < 0) {
				dp[i] = -inf;
			} else {
				dp[i] = mx[pos] + 1;
			}
			mx[i] = max(mx[i-1], dp[i]);
		}
		printf("%d\n", mx[n]>0?mx[n]:0);
	}
}