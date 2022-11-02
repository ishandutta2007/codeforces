#include <bits/stdc++.h>
using namespace std;

int n, a[100100];

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	if (n <= 2) {
		puts("-1"); return 0;
	}
	for (int i = 2; i <= n; i ++) {
		if (a[i] > a[i-1]) break;
		else if (a[i] < a[i-1]) {
			for (int j = 1; j <= n; j ++) a[j] = -a[j];
			break;
		}
	}
	int x = 0;
	for (int i = 2; i <= n; i ++) {
		if (a[i] > a[i-1]) {x = i; break;}
	}
	if (!x) {
		puts("-1"); return 0;
	}
	if (x >= 3) {
		printf("%d %d\n", 2, x); return 0;
	}
	for (int i = x + 1; i <= n; i ++) {
		if (a[i] >= a[x]) {
			printf("%d %d\n", 1, x); return 0;
		}
	}
	for (int i = x + 1; i <= n; i ++) {
		if (a[i] != a[1]) {
			printf("%d %d\n", 1, i); return 0;
		}
	}
	if (n >= 4) {
		printf("%d %d\n", x, x + 1); return 0;
	}
	puts("-1");
	return 0;
}