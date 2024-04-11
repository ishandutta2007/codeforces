#include <bits/stdc++.h>
using namespace std;
#define M 200010

int p[22][M], dp[M], n;

int LCA(int i, int j) {
	int k;
	if (dp[i] < dp[j]) i ^= j ^= i ^= j;
	for (k = 0; (1 << k) <= dp[i]; k ++); k --;
	for (int u = k; u >= 0; u --) if (dp[i] - (1 << u) >= dp[j]) i = p[u][i];
	if (i != j) {
		for (int u = k; u >= 0; u --) if (p[u][i] != p[u][j]) i = p[u][i], j = p[u][j];
		i = p[0][i];
	}
	return i;
}

int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	int d = 1, a = 1, b = 2, x;

	scanf("%d", &x); p[0][2] = 1;
	dp[1] = 1; dp[2] = 2;
	printf("%d ", 1);

	for (int i = 3; i <= n; i++) {
		scanf("%d", &x); p[0][i] = x;
		dp[i] = dp[x] + 1;

		for (int j = 1; j <= 20; j++) p[j][i] = p[j - 1][p[j - 1][i]];
		int z = LCA(a, i);

		int A = dp[a] + dp[i] - 2 * dp[z];
		z = LCA(b, i);
		int B = dp[b] + dp[i] - 2 * dp[z];
		int bf = 0;
		if (A > B) bf = 1;
		if (max(A, B) > d) {
			d = max(A, B);
			if (bf) b = i; else a = i;
		}
		printf("%d ", d);
	}
}