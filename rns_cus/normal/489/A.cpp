#include <bits/stdc++.h>
using namespace std;
#define N 3030

int n, a[N], x[N], y[N], cnt;

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++) {
		int mn = a[i], num = i;
		for (int j = i + 1; j <= n; j ++) {
			if (a[j] < mn) mn = a[j], num = j;
		}
		if (num != i) x[cnt] = i, y[cnt++] = num, swap(a[i], a[num]);
	}
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i ++) printf("%d %d\n", x[i] - 1, y[i] - 1);
	return 0;
}