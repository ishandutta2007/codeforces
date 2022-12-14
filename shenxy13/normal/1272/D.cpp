#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int a[n], dptable[2][n], ans = 0;
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	dptable[0][0] = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i - 1]) dptable[0][i] = dptable[0][i - 1] + 1;
		else dptable[0][i] = 1;
	}
	dptable[1][0] = 1;
	if (a[1] > a[0]) dptable[1][1] = 2;
	else dptable[1][1] = 1;
	for (int i = 2; i < n; ++i) {
		dptable[1][i] = 1;
		if (a[i] > a[i - 1]) dptable[1][i] = max(dptable[1][i], dptable[1][i - 1] + 1);
		if (a[i] > a[i - 2]) dptable[1][i] = max(dptable[1][i], dptable[0][i - 2] + 1);
	}
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < n; ++j) ans = max(ans, dptable[i][j]);
	}
	printf("%d", ans);
	return 0;
}