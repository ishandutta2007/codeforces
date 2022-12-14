#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 1000000000;
int n, a[100], dptable[100][100][100][2];
int dp(int i, int x, int y, int k) {
	if (i == n) return 0;
	if (dptable[i][x][y][k] != -1) return dptable[i][x][y][k];
	if (a[i] != 0) return dptable[i][x][y][k] = dp(i + 1, x, y, a[i] % 2) + (a[i] % 2 == k ? 0 : 1);
	int ans = INF;
	if (x != 0) ans = min(ans, dp(i + 1, x - 1, y, 1) + (k ? 0 : 1));
	if (y != 0) ans = min(ans, dp(i + 1, x, y - 1, 0) + (k ? 1 : 0));
	return dptable[i][x][y][k] = ans;
}
int main() {
	memset(dptable, -1, sizeof dptable);
	scanf("%d", &n);
	int odd = (n + 1) / 2, even = n / 2;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] % 2) --odd;
		else if (a[i] != 0) --even;
	}
	printf("%d", min(dp(0, odd, even, 1), dp(0, odd, even, 0)));
	return 0;
}