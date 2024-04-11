#include <cstdio>
#pragma warning(disable : 4996)
const int inf = 1012345678;
int H, W, a[109][109], r[109], c[109], pr[109], pc[109];
int main() {
	scanf("%d %d", &H, &W);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int ret = inf;
	for (int i = 0; i <= 500; i++) {
		r[0] = i;
		int sum = i;
		for (int j = 0; j < W; j++) c[j] = a[0][j] - r[0], sum += c[j];
		for (int j = 1; j < H; j++) r[j] = a[j][0] - c[0], sum += r[j];
		bool flag = true;
		for (int j = 0; j < W; j++) if (c[j] < 0) flag = false;
		for (int j = 0; j < H; j++) if (r[j] < 0) flag = false;
		if (flag) {
			bool f = true;
			for (int j = 0; j < H; j++) {
				for (int k = 0; k < W; k++) {
					if (r[j] + c[k] != a[j][k]) f = false;
				}
			}
			if (f && ret > sum) {
				ret = sum;
				for (int j = 0; j < H; j++) pr[j] = r[j];
				for (int j = 0; j < W; j++) pc[j] = c[j];
			}
		}
	}
	if (ret == inf) printf("-1\n");
	else {
		printf("%d\n", ret);
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < pr[i]; j++) {
				printf("row %d\n", i + 1);
			}
		}
		for (int i = 0; i < W; i++) {
			for (int j = 0; j < pc[i]; j++) {
				printf("col %d\n", i + 1);
			}
		}
	}
	return 0;
}