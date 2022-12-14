/// Choe Kwang D

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long LL;

#define N 40

LL f[N][N];

void solve() {
	f[0][0] = 1;
	f[1][1] = 1;
	for (int i = 2; i <= 35; i ++) {
		for (int j = 1; j <= i; j ++) {
            for (int k = 0; k < i; k ++) {
				for (int r = 0; r < j - 1; r ++) f[i][j] += f[k][r] * f[i-1-k][j-1];
				for (int r = 0; r < j - 1; r ++) f[i][j] += f[k][j-1] * f[i-1-k][r];
				f[i][j] += f[k][j-1] * f[i-1-k][j-1];
            }
		}
	}
}

int main() {
//	freopen("d.in", "r", stdin);
	solve();
	int n, k;
	scanf("%d %d", &n, &k);
	LL ans = 0;
	for (int i = k; i <= n; i ++) ans += f[n][i];
	printf("%I64d\n", ans);
}