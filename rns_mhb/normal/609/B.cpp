#include <bits/stdc++.h>
using namespace std;

int cnt[11], n, m;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1, a; i <= n; i ++) scanf("%d", &a), cnt[a] ++;
	long long ans = 0;
	for (int i = 1; i < m; i ++) for (int j = i + 1; j <= m; j ++) ans += 1ll * cnt[i] * cnt[j];
	printf("%I64d\n", ans);

	return 0;
}