#include <cstdio>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
int main() {
	int t;
	scanf("%d", &t);
	int dptable[200001][10];
	for (int i = 0; i < 10; ++i) dptable[0][i] = 1;
	for (int i = 1; i <= 200000; ++i) {
		for (int j = 0; j < 9; ++j) dptable[i][j] = dptable[i - 1][j + 1];
		dptable[i][9] = (dptable[i - 1][1] + dptable[i - 1][0]) % mod;
	}
	for (int i = 0; i < t; ++i) {
		int n, m, ans = 0;
		scanf("%d %d", &n, &m);
		while (n != 0) ans += dptable[m][n % 10], ans %= mod, n /= 10;
		printf("%d\n", ans);
	}
	return 0;
}