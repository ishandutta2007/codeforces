#include <bits/stdc++.h>
using namespace std;

int mp[2000005], x[2000005], cnt[2000005];
int main() {
	int T;
	scanf("%d", &T);
	while (T --) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++ i) {
			scanf("%d", &x[i]);
			mp[x[i]] ++;
		}
		int tot = 0;
		for (int i = 1; i <= n; ++ i) {
			if (mp[i]) {
				for (int j = 1; j <= mp[i] + 1; ++ j) {
					if (mp[i] % j == 0 || j - 1 - (mp[i] % j) <= mp[i] / j) {
						cnt[j] ++;
					}
				}
				++ tot;
			}
		}
		int s = 1;
		for (int i = 1; i <= n; ++ i)
			if (cnt[i] == tot) s = i;
		long long ans = 0;
		for (int i = 1; i <= n; ++ i) {
			ans += (mp[i] + s - 1) / s;
		}
		for (int i = 1; i <= n + 1; ++ i)
			mp[i] = cnt[i] = 0;
		printf("%lld\n", ans);
	}
	return 0;
}