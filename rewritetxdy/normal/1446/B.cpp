#include <bits/stdc++.h>
using namespace std;
int n, m, f[5005][5005], ans;
char s[5005], t[5005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("B.in", "r", stdin);
#endif
	scanf("%d%d%s%s", &n, &m, s + 1, t + 1);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			int &cur = f[i][j];
			cur = max(cur, f[i - 1][j] - 1);
			cur = max(cur, f[i][j - 1] - 1);
			if (s[i] == t[j])
				cur = max(cur, f[i - 1][j - 1] + 2);
			ans = max(ans, cur);
		}
	printf("%d\n", ans);
	return 0;
}