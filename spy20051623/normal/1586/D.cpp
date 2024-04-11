#include <bits/stdc++.h>

using namespace std;

int n;

int ask(int d) {
	if (d > 0) {
		printf("? ");
		for (int i = 0; i < n - 1; ++i) {
			printf("%d ", 1 + d);
		}
		printf("1\n");
		fflush(stdout);
		int r;
		scanf("%d", &r);
		return r;
	} else {
		printf("? ");
		for (int i = 0; i < n - 1; ++i) {
			printf("%d ", n + d);
		}
		printf("%d\n", n);
		fflush(stdout);
		int r;
		scanf("%d", &r);
		return r;
	}
}

int a[200];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = -n + 1; i < n; ++i) {
		if (i == 0) continue;
		int ans = ask(i);
		if (ans) {
			a[ans] = i;
		}
	}
	int minm = 1e9;
	for (int i = 1; i <= n; ++i) {
		minm = min(minm, a[i]);
	}
	printf("!");
	for (int i = 1; i <= n; ++i) {
		printf(" %d", n - a[i] + minm);
	}
	puts("");
	fflush(stdout);
	return 0;
}