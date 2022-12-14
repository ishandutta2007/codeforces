#include <bits/stdc++.h>
using namespace std;

int func(int k) {
	int rlt = k;
	while (k) {
		rlt += (k % 10);
		k /= 10;
	}
	return rlt;
}

int cnt, ans[1010];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = max(1, n - 100); i <= n; i ++) if (func(i) == n) ans[++cnt] = i;
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i ++) printf("%d ", ans[i]);

	return 0;
}