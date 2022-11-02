///	E : Coded by Choe Kwang

#include <bits/stdc++.h>
using namespace std;
#define N 111

int a[N], n, w, id[N], sum, s[N];

bool cmp(int i, int j) {
	return a[i] < a[j];
}

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d %d", &n, &w);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), sum += a[i];
	if (n == 1) {
		if (a[1] == w) {
			puts("Yes");
			for (int i = 1; i <= 2 * a[1]; i ++) printf("%d ", 1);
			puts("");
		}
		else puts("No");
		return 0;
	}

	for (int i = 1; i <= n; i ++) id[i] = i;
	sort(id + 1, id + n + 1, cmp);

	if (w < 1 || w > sum) {
		puts("No"); return 0;
	}
	if (w == 1) {
		if (a[id[1]] > 1) puts("No");
		else {
			puts("Yes");
			printf("%d ", id[1]);
			for (int i = 2; i <= n; i ++) {
				for (int j = 1; j <= 2 * a[id[i]]; j ++) printf("%d ", id[i]);
			}
			printf("%d ", id[1]);
		}
		return 0;
	}

	puts("Yes");
	for (int i = 1; i <= n; i ++) s[i] = s[i-1] + a[id[i]];
	int m = lower_bound(s + 1, s + n + 1, w) - s;
	if (s[m] == w) {
		printf("%d ", id[m]);
		for (int i = m + 1; i <= n; i ++) {
			for (int j = 1; j <= 2 * a[id[i]]; j ++) printf("%d ", id[i]);
		}
		for (int j = 2; j <= 2 * a[id[m]]; j ++) printf("%d ", id[m]);
		for (int i = m - 1; i >= 1; i --) {
			for (int j = 1; j <= 2 * a[id[i]]; j ++) printf("%d ", id[i]);
		}
	}
	else {
		int r = w - s[m-1];
		if (m > 1) {
			for (int j = 1; j <= 2 * r; j ++) printf("%d ", id[m]);
			printf("%d ", id[m-1]);
			for (int j = 2 * r + 1; j <= 2 * a[id[m]]; j ++) printf("%d ", id[m]);
			for (int i = m + 1; i <= n; i ++) {
				for (int j = 1; j <= 2 * a[id[i]]; j ++) printf("%d ", id[i]);
			}
			for (int j = 2; j <= 2 * a[id[m-1]]; j ++) printf("%d ", id[m-1]);
			for (int i = m - 2; i >= 1; i --) {
				for (int j = 1; j <= 2 * a[id[i]]; j ++) printf("%d ", id[i]);
			}
		}
		else {
			printf("%d ", id[m+1]);
			for (int j = 1; j <= 2 * a[id[m]] - 2; j ++) printf("%d ", id[m]);
			for (int j = 2; j <= 2 * r - 2; j ++) printf("%d ", id[m+1]);
			printf("%d ", id[m]);
			for (int j = 2 * r - 1; j <= 2 * a[id[m+1]]; j ++) printf("%d ", id[m+1]);
			for (int i = m + 2; i <= n; i ++) {
				for (int j = 1; j <= 2 * a[id[i]]; j ++) printf("%d ", id[i]);
			}
			printf("%d ", id[m]);
			for (int i = m - 1; i >= 1; i --) {
				for (int j = 1; j <= 2 * a[id[i]]; j ++) printf("%d ", id[i]);
			}
		}
	}
	puts("");
	return 0;
}