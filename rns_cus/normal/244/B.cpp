#include <bits/stdc++.h>
using namespace std;
#define M 100100

int a[M], n, cnt;

void make(int x, int y, int d) {
	int N = 1 << d;
	for (int i = 0; i < N; i ++) {
		int rlt = 0;
		for (int j = 0; j < d; j ++) {
			if (i & (1 << j)) rlt = rlt * 10 + x;
			else rlt = rlt * 10 + y;
		}
		a[cnt++] = rlt;
	}
}

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i <= 9; i ++) {
		for (int j = i; j <= 9; j ++) for (int k = 1; k <= 9; k ++) make(i, j, k);
	}
	sort(a, a + cnt);
	int m = unique(a, a + cnt) - a;
    int x = lower_bound(a, a + m, n + 1) - a;
    int ans = x - 1;
    if (n == 1000000000) ans ++;
    printf("%d\n", ans);
    return 0;
}