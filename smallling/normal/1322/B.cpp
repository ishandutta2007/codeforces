#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 10;

int a[N], b[N];
int cnt[2];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int ans = 0;
	for(int x = 24; x >= 0; x--) {
		cnt[0] = cnt[1] = 0;
		int nowcnt = 0;
		for(int i = 1; i <= n; i++) {
			int cur = (a[i] >> x) & 1;
			cnt[cur]++;
			nowcnt = (nowcnt + cnt[cur ^ 1]) & 1;
		}
		if(x > 0) {
			for(int i = 1; i <= n; i++)
				b[i] = a[i] & ((1 << x) - 1);
			sort(b + 1, b + 1 + n);
			int r = n + 1;
			for(int i = 1; i <= n; i++) {
				r = max(r, i + 1);
				while(r - 1 > i && b[r - 1] + b[i] >= (1 << x))r--;
				nowcnt = (nowcnt + n - r + 1) & 1;
			}
		}
		ans += nowcnt << x;
	}
	printf("%d\n", ans);
}