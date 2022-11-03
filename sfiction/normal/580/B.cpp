#include <cstdio>
#include <cstdlib>

const int MAXN = 1E5 + 10;

int a[MAXN][2];

int cmp(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int main(){
	int n, d;
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &a[i][0], &a[i][1]);
	qsort(a, n, sizeof(a[0]), cmp);

	long long ans = 0, cnt = 0;
	for (int j = 0, i = 0; i < n; ++i){
		for (; j < n && a[i][0] + d > a[j][0]; ++j)
			cnt += a[j][1];
		if (ans < cnt)
			ans = cnt;
		cnt -= a[i][1];
	}
	printf("%I64d\n", ans);
	return 0;
}