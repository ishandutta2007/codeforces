#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int a[N], cnt[N];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]), cnt[i] = 0;
		int ans = 0, lastx = 1;
		for(int i = 1; i < n; i++)
			if(a[i + 1] == a[i]) {
				cnt[a[lastx]]++;
				cnt[a[i + 1]]++;
				lastx = i + 1;
				ans++;
			}
		cnt[a[lastx]]++;
		cnt[a[n]]++;
		int mx = 0;
		for(int i = 1; i <= n; i++)
			if(cnt[i] > cnt[mx])mx = i;
		if(cnt[mx] <= 2 + ans) {
			printf("%d\n", ans);
			continue;
		}
		cnt[mx] = 2 * (cnt[mx] - ans - 1);
		ans += cnt[mx] / 2 - 1;
		for(int i = 2; i <= n; i++) {
			if(a[i] == a[i - 1] || a[i] == mx || a[i - 1] == mx)continue;
			cnt[mx] -= 2;
		}
		if(cnt[mx] > 2) {
			puts("-1");
		}
		else {
			printf("%d\n", ans);
		}
	}
}