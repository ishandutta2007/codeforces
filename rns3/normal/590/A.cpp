#include <cstdio>

#define N 500005

int a[N];
int from[N], to[N];

main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i ++) {
		if (i == 1 || (i > 1 && a[i] == a[i - 1])) {
			if (a[i] != a[i + 1]) from[++ cnt] = i;
		} else to[cnt] = i;
	}
	int rlt = 0;
	for (int i = 1; i <= cnt; i ++) {
		int cnt = (to[i] - from[i]) / 2;
		if (rlt < cnt) rlt = cnt;
	}
	printf("%d\n", rlt);
	for (int i = 1; i <= cnt; i ++) {
		if (a[from[i]] == a[to[i]]) {
			for (int j = from[i]; j <= to[i]; j ++) a[j] = a[from[i]];
		} else {
			int cnt = (to[i] - from[i] + 1) / 2;
			for (int j = from[i]; j < from[i] + cnt; j ++) a[j] = a[from[i]];
			for (int j = from[i] + cnt; j <= to[i]; j ++) a[j] = a[to[i]];
		}
	}
	for (int i = 1; i <= n; i ++) printf("%d ", a[i]); puts("");
}