#include <bits/stdc++.h>
using namespace std;

int cnt[100010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++) cnt[i] = 0;
		for (int i = 0; i < n; i++) {
			int x; scanf("%d", &x);
			cnt[x % m]++;
		}
		int ans = 0;
		for (int i = 0; i < m; i++) {
			if (!cnt[i]) continue;
			int j = (m - i) % m;
			ans++;
			if (i != j && abs(cnt[i] - cnt[j]) > 1) ans += abs(cnt[i] - cnt[j]) - 1;
			cnt[i] = cnt[j] = 0;
		}
		printf("%d\n", ans); 
	}
	return 0;
}