#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 200005;
const int MOD = 1e9 + 7;

int ans[MAXN];

int main() {
	ans[2] = 1;
	for (int i = 3; i <= 200000; ++i) {
		ans[i] = 1LL * ans[i - 1] * i % MOD;
	}
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		printf("%d\n", ans[n << 1]);
	}
	return 0;
}