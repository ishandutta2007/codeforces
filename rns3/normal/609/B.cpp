#include <bits/stdc++.h>
using namespace std;
int n, m, ans, x;
int cnt[30];
int main() {
//	freopen("B.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &x), cnt[x]++;
	for (int i = 1; i <= m; i++) {
		for (int j = i + 1; j <= m; j++) ans += cnt[i] * cnt[j];
	}
	printf("%d\n", ans);
}