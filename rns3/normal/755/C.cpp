#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a[10011], ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++) {
		if (a[a[i]] == i) ans ++;
		if (a[i] == i) ans ++;
	}
	printf("%d\n", ans / 2);
	return 0;
}