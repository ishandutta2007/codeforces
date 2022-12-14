#include <stdio.h>

#define N 1010

int n, a[N], b[N];

int main() {
	char s[3][9] = {"unrated", "rated", "maybe"};
	scanf("%d", &n);
	int ans = 2;
	for (int i = 1; i <= n; i ++) {
		scanf("%d %d", &a[i], &b[i]);
		if (a[i] != b[i]) ans = 1;
	}
	if (ans == 2) for (int i = 1; i < n; i ++) if (a[i] < a[i+1]) {
		ans = 0;
		break;
	}
	puts(s[ans]);
	return 0;
}