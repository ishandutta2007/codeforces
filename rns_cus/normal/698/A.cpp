#include <bits/stdc++.h>

using namespace std;

#define N 111
#define inf 1000000000

int n, a[N];
int f[3][N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j < 3; j ++) f[j][i] = inf;
		for(int j = 0; j < 3; j ++) f[0][i] = min(f[0][i], f[j][i - 1] + 1);
		if(a[i] & 1) {
			f[1][i] = min(f[2][i - 1], f[1][i]);
			f[1][i] = min(f[0][i - 1], f[1][i]);
		}
		if(a[i] >= 2) {
			f[2][i] = min(f[1][i - 1], f[2][i]);
			f[2][i] = min(f[0][i - 1], f[2][i]);
		}
	}
	int ans = inf;
	for(int j = 0; j < 3; j ++) ans = min(ans, f[j][n]);
	printf("%d\n", ans);
	return 0;
}