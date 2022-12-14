#include <bits/stdc++.h>
using namespace std;

#define N 101

int n, k[N], a[N][N];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; j ++) scanf("%d", &a[i][j]);
	}
	int s = 0, t = 0, b[N], e = 0;
	for (int i = 1; i <= n; i ++) {
        if (k[i] % 2) {
			b[++e] = a[i][(k[i]+1)/2];
        }
        for (int j = 1; 2 * j <= k[i]; j ++) {
			s += a[i][j];
			t += a[i][k[i]+1-j];
		}
	}
    sort (b + 1, b + e + 1, cmp);
    for (int i = 1; i <= e; i ++) {
		if (i % 2) s += b[i];
		else t += b[i];
    }
    printf("%d %d\n", s, t);
	return 0;
}