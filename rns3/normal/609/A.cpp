#include <bits/stdc++.h>
using namespace std;
#define M 100010
int flag[M], cnt[M], n, m, a[M];

int main() {
//	freopen("A.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", a + i), flag[0] = 1;
	cnt[0] = 0;
	for (int i = 1; i <= 100000; i++) cnt[i] = n + 1;

	for (int j = 0; j < n; j++) {
		for (int i = 100000; i >= a[j]; i--) {
			if (flag[i-a[j]] && cnt[i] > cnt[i-a[j]] + 1) cnt[i] = cnt[i-a[j]] + 1, flag[i] = 1;
		}
	}
	int ans = n + 1;
	for (int i = m; i <= 100000; i++) if (ans > cnt[i]) ans = cnt[i];
	printf("%d\n", ans);
}