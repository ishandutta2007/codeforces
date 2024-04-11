#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n, m, dptable[5000][5000];
char A[5000], B[5000];
int dp(int i, int j) {
	if (i == n || j == m) return 0;
	if (dptable[i][j] != -1) return dptable[i][j];
	if (A[i] != B[j]) return dptable[i][j] = max(0, max(dp(i + 1, j), dp(i, j + 1)) - 1);
	return dptable[i][j] = max(0, max(dp(i + 1, j + 1) + 2, max(dp(i + 1, j), dp(i, j + 1)) - 1));
}
int main() {
	memset(dptable, -1, sizeof dptable);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) scanf(" %c", &A[i]);
	for (int i = 0; i < m; ++i) scanf(" %c", &B[i]);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) ans = max(ans, dp(i, j));
	}
	printf("%d", ans);
	return 0;
}