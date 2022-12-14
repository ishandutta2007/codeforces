#include <bits/stdc++.h>
using namespace std;

#define N 4040

int n, a[N], b, c;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		if (a[i] < 0) a[i] = -a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		b = c = 0;
		for (int j = 1; j < i; j ++) if (a[j] < a[i]) b ++;
		for (int j = i + 1; j <= n; j ++) if (a[j] < a[i]) c ++;
		ans += min(b, c);
	}
	printf("%d\n", ans);
	return 0;
}