#include <bits/stdc++.h>
using namespace std;

#define N 2020

int x[N], y[N];
int n;

int id[N];

int cmp_id;
bool cmp(int i, int j) {
	int xx = x[i] - x[cmp_id];
	int yy = y[i] - y[cmp_id];
	int xxx = x[j] - x[cmp_id];
	int yyy = y[j] - y[cmp_id];
	if (yy < 0) yy = -yy, xx = -xx;
	if (yyy < 0) yyy = -yyy, xxx = -xxx;
	long long tmp = 1ll * xx * yyy - 1ll * yy * xxx;
	return tmp > 0;
}

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d %d", &x[i], &y[i]);
	long long ans = 0;
	for (int k = 1; k <= n; k ++) {
		int e = 0;
		cmp_id = k;
		int A = 0, B = 0;
		for (int i = 1; i <= n; i ++) if (i != k) {
			id[++e] = i;
			if (y[i] >= y[k]) A ++;
			else B ++;
		}
		sort(id + 1, id + e + 1, cmp);
		//for (int i = 1; i <= e; i ++) printf("(%d %d) ", x[id[i]], y[id[i]]);puts("");
		for (int i = 1; i <= e; i ++) {
			if (y[id[i]] < y[k]) B --;
			else A --;
			ans += A * (A - 1ll) * B * (B - 1ll) / 4;
			if (y[id[i]] < y[k]) A ++;
			else B ++;
		}
	}
	printf("%I64d\n", ans / 2);

	return 0;
}