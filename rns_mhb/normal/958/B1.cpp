#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n, cnt[N];

int main() {
	scanf("%d", &n);
	for (int i = 1, x, y; i < n; i ++) scanf("%d %d", &x, &y), cnt[x] ++, cnt[y] ++;
	int ans = 0;
	for (int i = 1; i <= n; i ++) if (cnt[i] == 1) ans ++;
	printf("%d\n", ans);

	return 0;
}